#Include shared library and OSAL
add_subdirectory(../../components/osal osal_lib)

# Include the subfolder's CMake file to get variables
# include(../../src/app/CMakeLists.txt)
# include(../../src/StatusLed/CMakeLists.txt)

# Instead of including, directly set the sources
set(APP_SOURCES
    ${CMAKE_SOURCE_DIR}/src/app/AgricultureMonitoring.cpp
)

set(STATUS_LED_SOURCES
    # List your StatusLed sources here directly
    ${CMAKE_SOURCE_DIR}/src/StatusLed/StatusLed.cpp
    # ... other files
)

set(HOST_IMPL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/hal_impl/LedGpio.cpp
)

add_executable(host_simulator
    ${APP_SOURCES}
    ${STATUS_LED_SOURCES}
    ${HOST_IMPL_SOURCES}
    main/SimulatorMain.cpp)

target_link_libraries(host_simulator osal_lib)

# Include directories
target_include_directories(host_simulator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/hal
)

# Set C++ standard (C++17 or later)
set_target_properties(host_simulator PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)