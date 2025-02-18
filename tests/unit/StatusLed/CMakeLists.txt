cmake_minimum_required(VERSION 3.15)

project(StatusLedUnitTest LANGUAGES CXX)

set(STATUS_LED_SOURCES
    # List your StatusLed sources here directly
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/StatusLed/StatusLed.cpp
    # ... other files
)

add_executable(StatusLedTests
    ${STATUS_LED_SOURCES}
    test_StatusLed.cpp
)

target_link_libraries(StatusLedTests PRIVATE gtest_gmock_lib)

target_include_directories(StatusLedTests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/hal
)

enable_testing()

add_test(NAME MyUnitTests COMMAND StatusLedTests)