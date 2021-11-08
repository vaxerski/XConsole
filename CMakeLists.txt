cmake_minimum_required(VERSION 3.0.0)
project(XConsole VERSION 0.1.0)

add_compile_options(-std=c++17)

if(UNIX)
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
endif(UNIX)

file(GLOB SRCFILES "*.cpp")
file(GLOB XCONSOLEFILES "XConsole/*.cpp")
add_executable(XConsole ${SRCFILES} ${XCONSOLEFILES})
target_link_libraries(XConsole ${CURSES_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
