#include <iostream>
#include <gtest/gtest.h>
#include <challenge_4.h>

using namespace Challenge_4;

void test_solution(std::function<uint64_t(int64_t)>solution) {
    EXPECT_EQ(solution(0),0);
    EXPECT_EQ(solution(1),0);
    EXPECT_EQ(solution(2),0);
    EXPECT_EQ(solution(3),2);
    EXPECT_EQ(solution(10),7);
    EXPECT_EQ(solution(20),19);
    EXPECT_EQ(solution(100),97);
    EXPECT_EQ(solution(50),47);
}

TEST(TEST_Challenge_4, sol_1){
    test_solution(sol_1);
}

TEST(TEST_Challenge_4, sol_2){
    test_solution(sol_2);
}