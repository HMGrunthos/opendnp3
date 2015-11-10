/*
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */

#include "LoggingHandler.h"

using namespace openpal;

namespace opendnp3
{
	
LoggingHandler::LoggingHandler(openpal::Logger logger_, IDecoderCallbacks& callbacks_) :	
	logger(logger_),
	callbacks(&callbacks_)
{}

IINField LoggingHandler::PrintUnsupported()
{
	Indent i(*callbacks);
	SIMPLE_LOG_BLOCK(logger, flags::APP_OBJECT_RX, "Pretty printing of this type not yet supported");
	return IINField::Empty();
}

IINField LoggingHandler::PrintCrob(const ICollection<Indexed<ControlRelayOutputBlock>>& items)
{
	Indent i(*callbacks);
	auto logItem = [this](const Indexed<ControlRelayOutputBlock>& item)
	{
		std::ostringstream oss;
		oss << "[" << item.index << "] - code: 0x" << ToHex(item.value.rawCode) << " (" << ControlCodeToString(item.value.functionCode) << ")";
		oss << " count: " << static_cast<uint32_t>(item.value.count);
		oss << " on-time: " << static_cast<uint32_t>(item.value.onTimeMS);
		oss << " off-time: " << static_cast<uint32_t>(item.value.offTimeMS);
		oss << " status: " << CommandStatusToString(item.value.status);
		SIMPLE_LOG_BLOCK(logger, flags::APP_OBJECT_RX, oss.str().c_str());
	};

	items.ForeachItem(logItem);

	return IINField::Empty();
}


IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var1& value, const openpal::RSlice& object) 
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var2& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var5& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var6& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var7& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var9& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var10& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var11& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var12& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var13& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var14& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const FreeFormatHeader& header, const Group120Var15& value, const openpal::RSlice& object)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const CountHeader& header, const ICollection<Group50Var1>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const CountHeader& header, const ICollection<Group51Var1>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const CountHeader& header, const ICollection<Group51Var2>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const CountHeader& header, const ICollection<Group52Var1>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const CountHeader& header, const ICollection<Group52Var2>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const CountHeader& header, const ICollection<Group120Var3>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const CountHeader& header, const ICollection<Group120Var4>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<IINValue>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Binary>>& values)
{
	auto stringify = [](bool value) -> const char* { return GetStringValue(value); };
	return this->PrintVQTStringify(values, stringify);
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values)
{	
	auto stringify = [](DoubleBit db) -> const char* { return DoubleBitToString(db); };
	return this->PrintVQTStringify(values, stringify);
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Counter>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<FrozenCounter>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Analog>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<OctetString>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<TimeAndInterval>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Group121Var1>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Binary>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values)
{
	auto stringify = [](DoubleBit db) -> const char* { return DoubleBitToString(db); };
	return this->PrintVQTStringify(values, stringify);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Counter>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<FrozenCounter>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Analog>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values)
{
	return this->PrintVQT(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<OctetString>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<TimeAndInterval>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryCommandEvent>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogCommandEvent>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Group122Var1>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Group122Var2>>& values)
{
	return this->PrintUnsupported();
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<ControlRelayOutputBlock>>& values)
{
	return PrintCrob(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputInt16>>& values)
{
	return PrintAO(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputInt32>>& values)
{
	return PrintAO(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputFloat32>>& values)
{
	return PrintAO(values);
}

IINField LoggingHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputDouble64>>& values)
{
	return PrintAO(values);
}

}

