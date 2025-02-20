cmake_minimum_required(VERSION 3.15)

project(LedControllerUnitTest LANGUAGES CXX)

set(LED_CONTROLLER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ActivityLed/ActivityLed.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/ConnectivityLed/ConnectivityLed.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/LedController/LedController.cpp
    # ... other files
)

add_executable(LedControllerTests
    ${LED_CONTROLLER_SOURCES}
    test_LedController.cpp
)

target_link_libraries(LedControllerTests PRIVATE gtest_gmock_lib)

target_include_directories(LedControllerTests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/hal
)

enable_testing()

add_test(NAME MyUnitTests COMMAND LedControllerTests)