file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE SRC_TEST test/*.cc)

add_library(Prime STATIC ${SRC})
target_include_directories(Prime PUBLIC include)

include(Testing)
add_executable(Test_Prime ${SRC_TEST})
target_link_libraries(Test_Prime PRIVATE Prime)
AddTests(Test_Prime)