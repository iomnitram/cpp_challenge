#include <iostream>
#include <gtest/gtest.h>
#include <challenge_1.h>

using namespace Challenge_1;

void test_solution(std::function<int(int)> sol) {
    EXPECT_EQ(sol(0), 0);
    EXPECT_EQ(sol(1), 0);
    EXPECT_EQ(sol(2), 0);
    EXPECT_EQ(sol(3), 3);
    EXPECT_EQ(sol(4), 3);
    EXPECT_EQ(sol(5), 8);
    EXPECT_EQ(sol(6), 14);
    EXPECT_EQ(sol(7), 14);
    EXPECT_EQ(sol(8), 14);
    EXPECT_EQ(sol(9), 23);
    EXPECT_EQ(sol(10), 33);
    EXPECT_EQ(sol(11), 33);
    EXPECT_EQ(sol(12), 45);
    EXPECT_EQ(sol(13), 45);
    EXPECT_EQ(sol(14), 45);
    EXPECT_EQ(sol(15), 60);
    EXPECT_EQ(sol(20), 98);
    EXPECT_EQ(sol(30), 225);
    EXPECT_EQ(sol(40), 408);
    EXPECT_EQ(sol(100), 2418);
    EXPECT_EQ(sol(149), 5175);
    EXPECT_EQ(sol(150), 5325);
    EXPECT_EQ(sol(152), 5325);
    EXPECT_EQ(sol(153), 5478);
    EXPECT_EQ(sol(154), 5478);
    EXPECT_EQ(sol(155), 5633);
    EXPECT_EQ(sol(156), 5789);
    EXPECT_EQ(sol(157), 5789);
    EXPECT_EQ(sol(1000), 234168);
    EXPECT_EQ(sol(10000), 23341668);
}


TEST(TEST_Challenge_1, Solution_1){
    test_solution(solution1);
}

TEST(TEST_Challenge_1, Solution_2){
    test_solution(solution2);
}