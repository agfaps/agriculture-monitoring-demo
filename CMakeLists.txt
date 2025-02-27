cmake_minimum_required(VERSION 3.15)
project(AgricultureMonitor LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 17)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    option(CODE_COVERAGE "Enable code coverage" ON)
    # Set common warnings for all files
    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wunused -Wcast-align -Wcast-qual -Werror)

    # Set C++-specific warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast -Wzero-as-null-pointer-constant")
    if(CODE_COVERAGE)
        add_compile_options(--coverage)
        add_link_options(--coverage)
    endif()
endif()

# Determine target from environment variable or default to host
if(NOT DEFINED TARGET_PLATFORM)
    set(TARGET_PLATFORM "host")
endif()

# Allow IDF_PATH to be passed as a CMake flag argument
set(IDF_PATH "" CACHE PATH "Path to ESP-IDF installation")

# Include target-specific setup
if(TARGET_PLATFORM STREQUAL "esp32-s3")
    # if(NOT IDF_PATH)
    #     message(FATAL_ERROR "IDF_PATH is not set. Please provide the path to your ESP-IDF installation using -DIDF_PATH=/path/to/esp-idf.")
    # endif()

    # # Set up ESP-IDF environment for ESP32-S3
    # set(ENV{IDF_PATH} "${IDF_PATH}")

    # # Ensure the ESP-IDF environment is sourced
    # execute_process(COMMAND bash -c "source ${IDF_PATH}/export.sh && echo $IDF_PATH"
    #                 OUTPUT_VARIABLE IDF_PATH_OUTPUT
    #                 ERROR_QUIET)

    # if(NOT IDF_PATH_OUTPUT)
    #     message(FATAL_ERROR "Failed to source ESP-IDF environment. Please ensure export.sh is sourced manually.")
    # endif()

    # # Include the ESP-IDF CMake project setup
    # include($ENV{IDF_PATH}/tools/cmake/project.cmake)

    # # Set the project name and target
    # project(AgricultureMonitor_ESP32S3)

    # # Set the toolchain for ESP32-S3
    # set(CMAKE_TOOLCHAIN_FILE ${IDF_PATH}/tools/cmake/toolchain-esp32s3.cmake)

    # Add the ESP32-S3 target directory
    add_subdirectory(targets/esp32-s3)
elseif(TARGET_PLATFORM STREQUAL "esp32")
    # Add ESP32 target directories
    # add_subdirectory(targets/esp32)
elseif(TARGET_PLATFORM STREQUAL "nrf52840")
    # Add ESP32 target directories
    # add_subdirectory(targets/nrf52840)
elseif(TARGET_PLATFORM STREQUAL "stm32f4")
    # Add ESP32 target directories
    # add_subdirectory(targets/stm32f4)
elseif(TARGET_PLATFORM STREQUAL "host")
    add_subdirectory(targets/${TARGET_PLATFORM})
elseif(TARGET_PLATFORM STREQUAL "test")
    add_subdirectory(tests)
elseif(TARGET_PLATFORM STREQUAL "host-test")
    add_subdirectory(targets/host)
    add_subdirectory(tests)
else()
    # Unknown target
    message(FATAL_ERROR "Unknown target: ${TARGET_PLATFORM}")
endif()