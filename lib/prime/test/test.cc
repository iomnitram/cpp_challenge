#include <iostream>
#include <gtest/gtest.h>
#include <prime.h>
#include <random>
#include <chrono>

std::vector<Prime::value_type> primes_0_100
    {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
std::vector<Prime::value_type> primes_400_100
    {401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};
std::vector<Prime::value_type> primes_1000_100
    {1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097};
std::vector<Prime::value_type> primes_1000000_1000
    {1000003,1000033,1000037,1000039,1000081,1000099,
        1000117,1000121,1000133,1000151,1000159,1000171,1000183,1000187,1000193,1000199,
        1000211,1000213,1000231,1000249,1000253,1000273,1000289,1000291,
        1000303,1000313,1000333,1000357,1000367,1000381,1000393,1000397,
        1000403,1000409,1000423,1000427,1000429,1000453,1000457,
        1000507,1000537,1000541,1000547,1000577,1000579,1000589,
        1000609,1000619,1000621,1000639,1000651,1000667,1000669,1000679,1000691,1000697,
        1000721,1000723,1000763,1000777,1000793,
        1000829,1000847,1000849,1000859,1000861,1000889,
        1000907,1000919,1000921,1000931,1000969,1000973,1000981,1000999};

TEST(TEST_Prime, Prime_till_100){
    Prime prime;
    auto it = prime.begin();
    for (const auto& p : primes_0_100) {
        EXPECT_EQ(p, (*it++));
    }
}


TEST(TEST_Prime, last){
    Prime prime;
    auto it = prime.begin();
    while (*(++it) < 200);
    EXPECT_EQ(*prime.last(), 211);
    while (*(++it) < 250);
    EXPECT_EQ(*prime.last(), 251);
    while (*(++it) < 300);
    EXPECT_EQ(*prime.last(), 307);
    while (*(++it) < 350);
    EXPECT_EQ(*prime.last(), 353);
}

TEST(TEST_Prime, preprocess){
    Prime prime;
    prime.preprocess(400);
    EXPECT_EQ(*prime.last(), 397);
    prime.preprocess(450);
    EXPECT_EQ(*prime.last(), 449);
    prime.preprocess(500);
    EXPECT_EQ(*prime.last(), 499);
    prime.preprocess(550);
    EXPECT_EQ(*prime.last(), 547);
}

TEST(TEST_Prime, isPrime){
    Prime prime;
    for (Prime::value_type i=2;i<100;++i) {
        EXPECT_EQ(prime.isPrime(i), std::binary_search(primes_0_100.begin(), primes_0_100.end(), i))<< "i = " << i;
    }
    for (Prime::value_type i=400;i<500;++i) {
        EXPECT_EQ(prime.isPrime(i), std::binary_search(primes_400_100.begin(), primes_400_100.end(), i))<< "i = " << i;
    }
    for (Prime::value_type i=1000;i<1100;++i) {
        EXPECT_EQ(prime.isPrime(i), std::binary_search(primes_1000_100.begin(), primes_1000_100.end(), i))<< "i = " << i;
    }
    EXPECT_LT(*prime.last(), 600);
    for (Prime::value_type i=1000000;i<1001000;++i) {
        EXPECT_EQ(prime.isPrime(i), std::binary_search(primes_1000000_1000.begin(), primes_1000000_1000.end(), i))<< "i = " << i;
    }
    EXPECT_GT(*prime.last(), 900);
    EXPECT_LT(*prime.last(), 1100);
}

TEST(TEST_Prime, isPrime_large){
    Prime prime;
    std::random_device rd;
    std::mt19937 gen(rd());

    uint tests = 1000;
    uint base{5};
    for (int exp = 9; exp < 15; ++exp) {
        std::uniform_int_distribution<Prime::value_type> dist(static_cast<Prime::value_type>(std::pow(base,exp)), static_cast<Prime::value_type>(2*std::pow(base,exp)));

        auto start = std::chrono::high_resolution_clock::now();
        for (uint i=0;i<tests;++i) {
            prime.isPrime(dist(gen));
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << tests << " tests in range [" << dist.min() << " ; " << dist.max() << "] in " << dur.count() << " ms" <<std::endl;
    }
}