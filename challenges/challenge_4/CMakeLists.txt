file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE SRC_TEST test/*.cc)

add_library(Challenge_4 OBJECT ${SRC})
target_link_libraries(Challenge_4 PUBLIC Prime)
target_include_directories(Challenge_4 PUBLIC src)

include(Testing)
add_executable(Test_Challenge_4 ${SRC_TEST})
target_link_libraries(Test_Challenge_4 PRIVATE Challenge_4)
AddTests(Test_Challenge_4)