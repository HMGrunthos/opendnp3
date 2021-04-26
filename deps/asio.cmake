find_package(Threads REQUIRED)

add_library(asio INTERFACE)
target_include_directories(asio INTERFACE deps/asio/include)
target_compile_definitions(asio INTERFACE ASIO_STANDALONE)
target_compile_definitions(asio INTERFACE ASIO_FREERTOS)
target_compile_definitions(asio INTERFACE ASIO_LWIP_SOCKETS)
target_compile_definitions(asio INTERFACE ASIO_DISABLE_LOCAL_SOCKETS)
target_compile_definitions(asio INTERFACE ASIO_SEPARATE_COMPILATION)
target_compile_features(asio INTERFACE cxx_std_11)
target_link_libraries(asio INTERFACE Threads::Threads)
include_directories(
	LwIP/src/include/compat/posix
	ARMDrivers/STM32F7xx_HAL_Driver/Inc
	ARMDrivers/CMSIS/Device/ST/STM32F7xx/Include
	ARMDrivers/CMSIS/Include
)
