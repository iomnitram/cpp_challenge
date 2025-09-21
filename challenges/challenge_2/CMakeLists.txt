file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE SRC_TEST test/*.cc)

add_library(Challenge_2 OBJECT ${SRC})
target_link_libraries(Challenge_2 PRIVATE MyMath)
target_include_directories(Challenge_2 PUBLIC src)

include(Testing)
add_executable(Test_Challenge_2 ${SRC_TEST})
target_link_libraries(Test_Challenge_2 PRIVATE Challenge_2)
AddTests(Test_Challenge_2)