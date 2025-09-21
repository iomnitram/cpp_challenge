#include <iostream>
#include <gtest/gtest.h>
#include <abs.h>
#include <sstream>


template<typename T>
class TEST_Abs : public ::testing::Test {
public:
    using SignedType_ = T;
    using UnsignedType_ = std::make_unsigned_t<T>;
};

using SignedTypes = ::testing::Types<
    int8_t, int16_t, int32_t, int64_t, short, int, long, long long,
    uint8_t, uint16_t, uint32_t, uint64_t, unsigned short, unsigned int, unsigned long, unsigned long long>;
TYPED_TEST_SUITE(TEST_Abs, SignedTypes);


TYPED_TEST(TEST_Abs, Types) {
    using SignedType = typename TestFixture::SignedType_;
    using UnsignedType = typename TestFixture::UnsignedType_;
    EXPECT_TRUE((std::is_same_v<decltype(abs_to_u(SignedType{})), UnsignedType>));
    EXPECT_EQ(abs_to_u(static_cast<SignedType>(0)), static_cast<UnsignedType>(0));
}

TYPED_TEST(TEST_Abs, Small_Value) {
    using SignedType = typename TestFixture::SignedType_;
    using UnsignedType = typename TestFixture::UnsignedType_;

#define TEST_SIGNE(VAL) \
    EXPECT_EQ(abs_to_u(static_cast<SignedType>(VAL)), static_cast<UnsignedType>(VAL));\
    if constexpr (std::is_signed_v<SignedType>){\
        EXPECT_EQ(abs_to_u(static_cast<SignedType>(-VAL)), static_cast<UnsignedType>(VAL));}



    TEST_SIGNE(0)
    TEST_SIGNE(1)
    TEST_SIGNE(2)
    TEST_SIGNE(3)
#undef TEST_SIGNE
}

TYPED_TEST(TEST_Abs, Limit_Max) {
    using SignedType = typename TestFixture::SignedType_;
    using UnsignedType = typename TestFixture::UnsignedType_;

    EXPECT_EQ(
        abs_to_u(static_cast<SignedType>( std::numeric_limits<SignedType>::max() )),
        static_cast<UnsignedType>(std::numeric_limits<SignedType>::max()));
}

TYPED_TEST(TEST_Abs, Limit_Min) {
    using SignedType = typename TestFixture::SignedType_;
    using UnsignedType = typename TestFixture::UnsignedType_;

    if constexpr (std::is_signed_v<SignedType>) {
        EXPECT_EQ(
            abs_to_u(std::numeric_limits<SignedType>::min()),
            static_cast<UnsignedType>(std::numeric_limits<SignedType>::max())+1
        );
    } else {
        EXPECT_EQ(
            abs_to_u(std::numeric_limits<SignedType>::min()),
            static_cast<UnsignedType>(std::numeric_limits<SignedType>::min())
        );
    }
}