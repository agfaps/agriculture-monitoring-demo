# this still not working, use direct include source at host cmakelists.txt

set(APP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/AgricultureMonitoring.cpp
    PARENT_SCOPE  # This passes the variable up to the parent scope
)