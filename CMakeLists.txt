cmake_minimum_required(VERSION 3.20.0)
project(cpp_challenge LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(ALL_WARNINGS "Enable strict compiler warnings" OFF)
option(WARNINGS_ERROR "Warning from compiler became errors" OFF)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(NoInSourceBuilds)
include(Warnings)
include(Testing)

if(ALL_WARNINGS)
    warnings_project()
endif()

if(WARNINGS_ERROR)
    warnings_error_project()
endif()


add_subdirectory(thirdparty)
add_subdirectory(lib)
add_subdirectory(challenges)