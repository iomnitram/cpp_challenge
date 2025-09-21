file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE SRC_TEST test/*.cc)

add_library(MyMath STATIC ${SRC})
target_include_directories(MyMath PUBLIC include)
target_link_libraries(MyMath PRIVATE Prime)

include(Testing)
add_executable(Test_MyMath ${SRC_TEST})
target_link_libraries(Test_MyMath PRIVATE MyMath)
AddTests(Test_MyMath)