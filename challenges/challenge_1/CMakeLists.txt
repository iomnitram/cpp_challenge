file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE SRC_TEST test/*.cc)

add_library(Challenge_1 OBJECT ${SRC})
#target_link_libraries(Challenge_1 PRIVATE xxx)
target_include_directories(Challenge_1 PUBLIC src)

include(Testing)
add_executable(Test_Challenge_1 ${SRC_TEST})
target_link_libraries(Test_Challenge_1 PRIVATE Challenge_1)
AddTests(Test_Challenge_1)