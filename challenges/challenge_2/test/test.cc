#include <iostream>
#include <gtest/gtest.h>
#include <challenge_2.h>

using namespace Challenge_2;

void test_gcd(std::function<uint64_t(int64_t, int64_t)>gcd_func) {
#define TEST_PAIR(A,B,ANS) \
    EXPECT_EQ(gcd_func(A,B),ANS);\
    EXPECT_EQ(gcd_func(B,A),ANS);\
    EXPECT_EQ(gcd_func(-A,B),ANS);\
    EXPECT_EQ(gcd_func(B,-A),ANS);\
    EXPECT_EQ(gcd_func(A,-B),ANS);\
    EXPECT_EQ(gcd_func(-B,A),ANS);\
    EXPECT_EQ(gcd_func(-A,-B),ANS);\
    EXPECT_EQ(gcd_func(-B,-A),ANS);

    TEST_PAIR(0,0,0)
    TEST_PAIR(0,1,1)
    TEST_PAIR(0,2,2)
    TEST_PAIR(1,1,1)
    TEST_PAIR(1,2,1)
    TEST_PAIR(1,3,1)
    TEST_PAIR(1,4,1)
    TEST_PAIR(2,2,2)
    TEST_PAIR(2,3,1)
    TEST_PAIR(2,4,2)
    TEST_PAIR(2,16,2)
    TEST_PAIR(2,6,2)
    TEST_PAIR(3,6,3)
    TEST_PAIR(6,9,3)
    TEST_PAIR(54,135,27);

#undef TEST_PAIR
}

#define GCD(F) [](int64_t a, int64_t b) {return F(a,b);}

TEST(TEST_Challenge_2, Solution_1){
    test_gcd(GCD(gcd_1));
}

TEST(TEST_Challenge_2, Solution_2){
    test_gcd(GCD(gcd_2));
}

TEST(TEST_Challenge_2, Solution_3){
    test_gcd(GCD(gcd_3));
}

TEST(TEST_Challenge_2, Solution_4){
    test_gcd(GCD(gcd_4));
}

TEST(TEST_Challenge_2, Solution_5){
    test_gcd(GCD(gcd_5));
}


#undef GCD