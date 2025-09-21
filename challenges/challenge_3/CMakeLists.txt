file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE SRC_TEST test/*.cc)

add_library(Challenge_3 OBJECT ${SRC})
target_link_libraries(Challenge_3 PUBLIC MyMath)
target_include_directories(Challenge_3 PUBLIC src)

include(Testing)
add_executable(Test_Challenge_3 ${SRC_TEST})
target_link_libraries(Test_Challenge_3 PRIVATE Challenge_3)
AddTests(Test_Challenge_3)