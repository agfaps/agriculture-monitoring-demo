cmake_minimum_required(VERSION 3.15)
project(AgricultureMonitor LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Determine target from environment variable or default to host
if(NOT DEFINED TARGET_PLATFORM)
    set(TARGET_PLATFORM "host")
endif()

# Add target-specific directory
add_subdirectory(targets/${TARGET_PLATFORM})
