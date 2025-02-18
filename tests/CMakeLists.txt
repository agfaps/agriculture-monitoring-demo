cmake_minimum_required(VERSION 3.15)

project(tests LANGUAGES CXX)

# Enable testing
enable_testing()

add_subdirectory(googletest)

# Add test types
add_subdirectory(unit)
# add_subdirectory(integration)
# add_subdirectory(system)
