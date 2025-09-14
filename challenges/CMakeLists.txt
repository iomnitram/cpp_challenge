
set(LIST_CHALLENGE "${CMAKE_CURRENT_SOURCE_DIR}/list_challenge.txt")
if(NOT EXISTS "${LIST_CHALLENGE}")
    file(TOUCH "${LIST_CHALLENGE}")
endif()
include(${LIST_CHALLENGE})

add_custom_target(Reload
        COMMAND ./detect.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


add_custom_target(New
        COMMAND ./create.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})