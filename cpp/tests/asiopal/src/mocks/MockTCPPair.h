/*
 * Copyright 2013-2019 Automatak, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
 * LLC (www.automatak.com) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Automatak LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ASIOPAL_MOCKTCPPAIR_H
#define ASIOPAL_MOCKTCPPAIR_H

#include "MockIO.h"
#include "MockTCPClientHandler.h"
#include "MockTCPServer.h"

#include "asiopal/TCPClient.h"

#include "testlib/MockLogHandler.h"

namespace asiopal
{

class MockTCPPair
{

public:
    MockTCPPair(const std::shared_ptr<MockIO>& io, uint16_t port, std::error_code ec = std::error_code());

    ~MockTCPPair();

    void Connect(size_t num = 1);

    bool NumConnectionsEqual(size_t num) const;

private:
    testlib::MockLogHandler log;
    std::shared_ptr<MockIO> io;
    uint16_t port;
    std::shared_ptr<MockTCPClientHandler> chandler;
    std::shared_ptr<TCPClient> client;
    std::shared_ptr<MockTCPServer> server;
};

} // namespace asiopal

#endif
