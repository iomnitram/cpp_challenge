#include <iostream>
#include <gtest/gtest.h>
#include <challenge_3.h>

using namespace Challenge_3;

template<typename T>
class TEST_Challenge_3 : public ::testing::Test {
public:
    using SignedType_ = T;
    using UnsignedType_ = std::make_unsigned_t<T>;
};

using SignedTypes = ::testing::Types<
    int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t>;
TYPED_TEST_SUITE(TEST_Challenge_3, SignedTypes);


TYPED_TEST(TEST_Challenge_3, Types) {
    using SignedType = typename TestFixture::SignedType_;
    using UnsignedType = typename TestFixture::UnsignedType_;
    EXPECT_TRUE((std::is_same_v<decltype(abs_to_u(SignedType{})), UnsignedType>));
    EXPECT_EQ(abs_to_u(static_cast<SignedType>(0)), static_cast<UnsignedType>(0));
}

#define ALL_TEST\
    T(1)\
    T(5,5)\
    T(4,2,4)\
    T(2520,4,5,6,7,8,9,10)\
    T(2520,4,-5,6,-7,8,-9,10)

TEST(TEST_Challenge_3, lcm_1){
#define T(ANS, ...) \
    {std::vector<short>l({__VA_ARGS__});EXPECT_EQ(lcm_1(l.begin(), l.end()),ANS);}\
    {std::list<int>l({__VA_ARGS__});EXPECT_EQ(lcm_1(l.begin(), l.end()),ANS);}\
    {std::set<long>l({__VA_ARGS__});EXPECT_EQ(lcm_1(l.begin(), l.end()),ANS);}
    ALL_TEST
#undef T
}

TEST(TEST_Challenge_3, lcm_2){
#define T(ANS, ...) \
    EXPECT_EQ(lcm_2(std::vector<short>({__VA_ARGS__})),ANS);\
    EXPECT_EQ(lcm_2(std::list<int>({__VA_ARGS__})),ANS);\
    EXPECT_EQ(lcm_2(std::set<long>({__VA_ARGS__})),ANS);
    ALL_TEST
#undef T
}



TEST(TEST_Challenge_3, lcm_3){
#define T(ANS, ...) EXPECT_EQ(lcm_3(__VA_ARGS__),ANS);
    ALL_TEST
#undef T
}