# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.15)

# Set the project name
project(osal_lib LANGUAGES C)

# Determine source file based on platform at configure time
if(TARGET_PLATFORM STREQUAL "esp32" OR TARGET_PLATFORM STREQUAL "esp32-s3")
    set(OSAL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/freertos/osal_freertos.c)
elseif(TARGET_PLATFORM STREQUAL "host")
    set(OSAL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/posix/osal_posix.c)
endif()


add_library(osal_lib ${OSAL_SOURCES})

# Include the public headers
target_include_directories(osal_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set C++ standard (C++17 or later)
set_target_properties(osal_lib PROPERTIES
    C_STANDARD 17
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)
