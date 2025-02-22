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

# Add target-specific directory
add_subdirectory(targets/${TARGET_PLATFORM})
add_subdirectory(tests)
