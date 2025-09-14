file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE SRC_TEST test/*.cc)

add_library(Challenge_$NUM OBJECT ${SRC})
#target_link_libraries(Challenge_$NUM PRIVATE xxx)
target_include_directories(Challenge_$NUM PUBLIC src)

include(Testing)
add_executable(Test_Challenge_$NUM ${SRC_TEST})
target_link_libraries(Test_Challenge_$NUM PRIVATE Challenge_$NUM)
AddTests(Test_Challenge_$NUM)