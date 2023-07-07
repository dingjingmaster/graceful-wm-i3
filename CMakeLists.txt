cmake_minimum_required(VERSION 3.5)

project(graceful-wm LANGUAGES C CXX)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LINUX_VERSION "${LINUX_VERSION_MAJOR}.${LINUX_VERSION_MINOR}.${LINUX_VERSION_PATCH}")
set(PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

find_package (PkgConfig)

cmake_host_system_information(RESULT OS QUERY OS_NAME)
cmake_host_system_information(RESULT RELEASE QUERY OS_RELEASE)

execute_process(COMMAND uname -m OUTPUT_VARIABLE OS_ARCH OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND bash -c "cat /etc/os-release|grep -E '^NAME'|awk -F'=' '{print $2}'|sed 's/\"//g'|tr '\n' ' '|sed 's/ //g'"  OUTPUT_VARIABLE DISTRIB)


pkg_check_modules(YAJL  REQUIRED yajl)
pkg_check_modules(CAIRO REQUIRED cairo)
pkg_check_modules(GIO   REQUIRED gio-2.0)
pkg_check_modules(PCRE  REQUIRED libpcre2-8)
pkg_check_modules(PANGO REQUIRED pangocairo)
pkg_check_modules(XKB   REQUIRED xkbcommon xkbcommon-x11)
pkg_check_modules(SN    REQUIRED libstartup-notification-1.0)
pkg_check_modules(XCB   REQUIRED xcb xcb-xkb xcb-xinerama xcb-randr xcb-shape xcb-util xcb-cursor xcb-keysyms xcb-icccm xcb-xrm)

find_library(EV         libev.so)


MESSAGE("")
MESSAGE(STATUS "OS name                             : ${OS}")
MESSAGE(STATUS "OS arch                             : ${OS_ARCH}")
MESSAGE(STATUS "OS release                          : ${RELEASE}")
MESSAGE(STATUS "OS distribute                       : ${DISTRIB}")
MESSAGE(STATUS "System platform                     : ${CMAKE_SYSTEM_NAME}")
MESSAGE("")

add_definitions(-w -g
        -D I3_VERSION=\\"${PACKAGE_VERSION}\\"
        -D APP_NAME=\\"graceful-wm\\"
        -D INSTALL_DIR=\\"/usr/local/\\"
        -D APP_VERSION=\\"${PACKAGE_VERSION}\\"
        )

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(wm)
add_subdirectory(app)
