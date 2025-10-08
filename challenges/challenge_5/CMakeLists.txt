file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE SRC_TEST test/*.cc)

add_library(Challenge_5 OBJECT ${SRC})
target_link_libraries(Challenge_5 PRIVATE Prime)
target_include_directories(Challenge_5 PUBLIC src)

include(Testing)
add_executable(Test_Challenge_5 ${SRC_TEST})
target_link_libraries(Test_Challenge_5 PRIVATE Challenge_5)
AddTests(Test_Challenge_5)