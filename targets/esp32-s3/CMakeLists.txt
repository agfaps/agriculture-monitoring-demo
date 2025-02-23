cmake_minimum_required(VERSION 3.16)

# if(NOT IDF_PATH)
#     message(FATAL_ERROR "IDF_PATH is not set. Please provide the path to your ESP-IDF installation using -DIDF_PATH=/path/to/esp-idf.")
# endif()

# Set up ESP-IDF environment for ESP32-S3
# set(ENV{IDF_PATH} "${IDF_PATH}")

# # Ensure the ESP-IDF environment is sourced
# execute_process(COMMAND bash -c "source ${IDF_PATH}/export.sh && echo $IDF_PATH"
#             OUTPUT_VARIABLE IDF_PATH_OUTPUT
#             ERROR_QUIET)

# Ensure the ESP-IDF environment is sourced
# execute_process(COMMAND bash -c "source ${IDF_PATH}/export.sh && echo $IDF_PATH")

# Set the target to esp32s3
# set(IDF_TARGET "esp32s3")

# if(NOT IDF_PATH_OUTPUT)
#     message(FATAL_ERROR "Failed to source ESP-IDF environment. Please ensure export.sh is sourced manually.")
# endif()

# message(STATUS "IDF_PATH: $ENV{IDF_PATH}")

# Include the ESP-IDF CMake project setup
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Set the project name and target
project(AgricultureMonitor_ESP32S3)

# Set the toolchain for ESP32-S3
set(CMAKE_TOOLCHAIN_FILE $ENV{IDF_PATH}/tools/cmake/toolchain-esp32s3.cmake)

# Include the main application
# add_subdirectory(main)

