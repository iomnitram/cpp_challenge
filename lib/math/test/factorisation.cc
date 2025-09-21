#include <iostream>
#include <gtest/gtest.h>
#include <factorisation.h>
#include <sstream>

TEST(TEST_Factorisation, Factor_constructor){
    EXPECT_EQ(Factorisation::Factor().base,1);
    EXPECT_EQ(Factorisation::Factor().exponent.has_value(),false);
    EXPECT_EQ(Factorisation::Factor(2).base,2);
    EXPECT_EQ(Factorisation::Factor(2).exponent.has_value(),false);
    EXPECT_EQ(Factorisation::Factor(3,4).base,3);
    EXPECT_EQ(Factorisation::Factor(3,4).exponent.has_value(),true);
    EXPECT_EQ(Factorisation::Factor(3,4).exponent.value(),4);
}

TEST(TEST_Factorisation, Factor_stream){
    std::ostringstream oss;
    oss << Factorisation::Factor();
    EXPECT_EQ(oss.str(), "1^x");
    oss.str("");

    oss << Factorisation::Factor(0);
    EXPECT_EQ(oss.str(), "0^x");
    oss.str("");

    oss << Factorisation::Factor(5);
    EXPECT_EQ(oss.str(), "5^x");
    oss.str("");

    oss << Factorisation::Factor(3,4);
    EXPECT_EQ(oss.str(), "3^4");
    oss.str("");
}

TEST(TEST_Factorisation, Factor_value){
    EXPECT_EQ(Factorisation::Factor(3,4).value(),81);
    EXPECT_EQ(Factorisation::Factor(3,4)(),81);
    EXPECT_EQ(Factorisation::Factor(2,4).value(),16);
    EXPECT_EQ(Factorisation::Factor(2,4)(),16);

    EXPECT_EQ(Factorisation::Factor(0,4).value(),0);
    EXPECT_EQ(Factorisation::Factor(1,4).value(),1);
    EXPECT_EQ(Factorisation::Factor(0,0).value(),1);
    EXPECT_EQ(Factorisation::Factor(1,0).value(),1);
    EXPECT_EQ(Factorisation::Factor(0).value(),1);
    EXPECT_EQ(Factorisation::Factor(1).value(),1);
    EXPECT_EQ(Factorisation::Factor(2).value(),1);
    EXPECT_EQ(Factorisation::Factor(3).value(),1);
}

TEST(TEST_Factorisation, Factorisation_Base){
    {
        Factorisation f(0);
        EXPECT_EQ(f(),1);
        EXPECT_EQ(f.size(),0);
        EXPECT_EQ(f.begin(),f.end());
        EXPECT_EQ(f.cbegin(),f.cend());
        EXPECT_EQ(f.rbegin(),f.rend());
        EXPECT_EQ(f.crbegin(),f.crend());
    }
    {
        Factorisation f(1);
        EXPECT_EQ(f(),1);
        EXPECT_EQ(f.size(),0);
        EXPECT_EQ(f.begin(),f.end());
        EXPECT_EQ(f.cbegin(),f.cend());
        EXPECT_EQ(f.rbegin(),f.rend());
        EXPECT_EQ(f.crbegin(),f.crend());
    }
    {
        Factorisation f(2);
        EXPECT_EQ(f(),2);
        EXPECT_EQ(f.size(),1);
        EXPECT_EQ(f[0],Factorisation::Factor(2,1));
        EXPECT_EQ(*f.begin(),Factorisation::Factor(2,1));
        EXPECT_EQ(*f.cbegin(),Factorisation::Factor(2,1));
        EXPECT_EQ(*f.rbegin(),Factorisation::Factor(2,1));
        EXPECT_EQ(*f.crbegin(),Factorisation::Factor(2,1));
        EXPECT_EQ(std::distance(f.begin(),f.end()), 1);
        EXPECT_EQ(std::distance(f.cbegin(),f.cend()), 1);
        EXPECT_EQ(std::distance(f.rbegin(),f.rend()), 1);
        EXPECT_EQ(std::distance(f.crbegin(),f.crend()), 1);
    }
    {
        Factorisation f(3);
        EXPECT_EQ(f(),3);
        EXPECT_EQ(f.size(),1);
        EXPECT_EQ(f[0],Factorisation::Factor(3,1));
        EXPECT_EQ(*f.begin(),Factorisation::Factor(3,1));
        EXPECT_EQ(*f.cbegin(),Factorisation::Factor(3,1));
        EXPECT_EQ(*f.rbegin(),Factorisation::Factor(3,1));
        EXPECT_EQ(*f.crbegin(),Factorisation::Factor(3,1));
        EXPECT_EQ(std::distance(f.begin(),f.end()), 1);
        EXPECT_EQ(std::distance(f.cbegin(),f.cend()), 1);
        EXPECT_EQ(std::distance(f.rbegin(),f.rend()), 1);
        EXPECT_EQ(std::distance(f.crbegin(),f.crend()), 1);
    }
    {
        Factorisation f(4);
        EXPECT_EQ(f(),4);
        EXPECT_EQ(f.size(),1);
        EXPECT_EQ(f[0],Factorisation::Factor(2,2));
        EXPECT_EQ(*f.begin(),Factorisation::Factor(2,2));
        EXPECT_EQ(*f.cbegin(),Factorisation::Factor(2,2));
        EXPECT_EQ(*f.rbegin(),Factorisation::Factor(2,2));
        EXPECT_EQ(*f.crbegin(),Factorisation::Factor(2,2));
        EXPECT_EQ(std::distance(f.begin(),f.end()), 1);
        EXPECT_EQ(std::distance(f.cbegin(),f.cend()), 1);
        EXPECT_EQ(std::distance(f.rbegin(),f.rend()), 1);
        EXPECT_EQ(std::distance(f.crbegin(),f.crend()), 1);
    }
    {
        Factorisation f(6);
        EXPECT_EQ(f(),6);
        EXPECT_EQ(f.size(),2);
        EXPECT_EQ(f[0],Factorisation::Factor(2,1));
        EXPECT_EQ(f[1],Factorisation::Factor(3,1));
        EXPECT_EQ(*f.begin(),Factorisation::Factor(2,1));
        EXPECT_EQ(*f.cbegin(),Factorisation::Factor(2,1));
        EXPECT_EQ(*(++f.rbegin()),Factorisation::Factor(2,1));
        EXPECT_EQ(*(++f.crbegin()),Factorisation::Factor(2,1));
        EXPECT_EQ(*f.rbegin(),Factorisation::Factor(3,1));
        EXPECT_EQ(*f.crbegin(),Factorisation::Factor(3,1));
        EXPECT_EQ(*(++f.begin()),Factorisation::Factor(3,1));
        EXPECT_EQ(*(++f.cbegin()),Factorisation::Factor(3,1));
        EXPECT_EQ(std::distance(f.begin(),f.end()), 2);
        EXPECT_EQ(std::distance(f.cbegin(),f.cend()), 2);
        EXPECT_EQ(std::distance(f.rbegin(),f.rend()), 2);
        EXPECT_EQ(std::distance(f.crbegin(),f.crend()), 2);
    }
    {
        Factorisation f(819);
        EXPECT_EQ(f(),819);
        EXPECT_EQ(f.size(),3);
        EXPECT_EQ(f[0],Factorisation::Factor(3,2));
        EXPECT_EQ(f[1],Factorisation::Factor(7,1));
        EXPECT_EQ(f[2],Factorisation::Factor(13,1));
        EXPECT_EQ(*f.begin(),Factorisation::Factor(3,2));
        EXPECT_EQ(*f.cbegin(),Factorisation::Factor(3,2));
        EXPECT_EQ(*(++f.begin()),Factorisation::Factor(7,1));
        EXPECT_EQ(*(++f.cbegin()),Factorisation::Factor(7,1));
        EXPECT_EQ(*(++(++f.begin())),Factorisation::Factor(13,1));
        EXPECT_EQ(*(++(++f.cbegin())),Factorisation::Factor(13,1));
        EXPECT_EQ(*f.rbegin(),Factorisation::Factor(13,1));
        EXPECT_EQ(*f.crbegin(),Factorisation::Factor(13,1));
        EXPECT_EQ(*(++f.rbegin()),Factorisation::Factor(7,1));
        EXPECT_EQ(*(++f.crbegin()),Factorisation::Factor(7,1));
        EXPECT_EQ(*(++(++f.rbegin())),Factorisation::Factor(3,2));
        EXPECT_EQ(*(++(++f.crbegin())),Factorisation::Factor(3,2));
        EXPECT_EQ(std::distance(f.begin(),f.end()), 3);
        EXPECT_EQ(std::distance(f.cbegin(),f.cend()), 3);
        EXPECT_EQ(std::distance(f.rbegin(),f.rend()), 3);
        EXPECT_EQ(std::distance(f.crbegin(),f.crend()), 3);
    }
}

TEST(TEST_Factorisation, Factorisation_stream){
    std::ostringstream oss;
    oss << Factorisation();
    EXPECT_EQ(oss.str(), "(1)");
    oss.str("");

    oss << Factorisation(0);
    EXPECT_EQ(oss.str(), "(1)");
    oss.str("");

    oss << Factorisation(2);
    EXPECT_EQ(oss.str(), "(1*2^1)");
    oss.str("");

    oss << Factorisation(4);
    EXPECT_EQ(oss.str(), "(1*2^2)");
    oss.str("");

    oss << Factorisation(6);
    EXPECT_EQ(oss.str(), "(1*2^1*3^1)");
    oss.str("");

    oss << Factorisation(4096);
    EXPECT_EQ(oss.str(), "(1*2^12)");
    oss.str("");

    oss << Factorisation(5828130);
    EXPECT_EQ(oss.str(), "(1*2^1*3^2*5^1*7^1*11^1*29^2)");
    oss.str("");
}

static bool operator==(const Factorisation& lhs, const std::list<Factorisation::Factor>& rhs) noexcept {
    if (lhs.size() != rhs.size()) return false;
    auto it_lhs = lhs.cbegin();
    auto it_rhs = rhs.cbegin();
    while (it_lhs != lhs.cend()) {
        if (*it_lhs++ != *it_rhs++)
            return false;
    }
    return true;
}

TEST(TEST_Factorisation, Factorisation_limits) {

    EXPECT_EQ(Factorisation(0), std::list<Factorisation::Factor>{});
    EXPECT_EQ(Factorisation(1), std::list<Factorisation::Factor>{});
    /*EXPECT_EQ(Factorisation(std::numeric_limits<Factorisation::value_type>::max()-1),
        std::list<Factorisation::Factor>({{2,1},{7,2},{73,1},{127,1},{337,1},{92737,1},{649657,1}}));
    EXPECT_EQ(Factorisation(std::numeric_limits<Factorisation::value_type>::max()),
        std::list<Factorisation::Factor>({{3,1},{5,1},{17,1},{257,1},{641,1},{65537,1},{6700417,1}}));
*/}

TEST(TEST_Factorisation, Factorisation_add) {
    EXPECT_EQ(Factorisation(0) + Factorisation::Factor(), Factorisation(0));
    EXPECT_EQ(Factorisation(0) + Factorisation::Factor(5), Factorisation(0));
    EXPECT_EQ(Factorisation(2) + Factorisation::Factor(), Factorisation(2));
    EXPECT_EQ(Factorisation(2) + Factorisation::Factor(5), Factorisation(2));


    EXPECT_EQ(Factorisation(0) + Factorisation::Factor(5,1), Factorisation(5));
    EXPECT_EQ(Factorisation(2) + Factorisation::Factor(5,1), Factorisation(10));
    EXPECT_EQ(Factorisation(5) + Factorisation::Factor(5,1), Factorisation(25));
    EXPECT_EQ(Factorisation(7) + Factorisation::Factor(5,1), Factorisation(35));
}

TEST(TEST_Factorisation, Factorisation_sub) {
    EXPECT_EQ(Factorisation(0) - Factorisation::Factor(), Factorisation(0));
    EXPECT_EQ(Factorisation(0) - Factorisation::Factor(5), Factorisation(0));
    EXPECT_EQ(Factorisation(2) - Factorisation::Factor(), Factorisation(2));
    EXPECT_EQ(Factorisation(2) - Factorisation::Factor(5), Factorisation(2));


    EXPECT_THROW(Factorisation(0) - Factorisation::Factor(5,1), std::range_error);
    EXPECT_THROW(Factorisation(2) - Factorisation::Factor(5,1), std::range_error);
    EXPECT_EQ(Factorisation(5) - Factorisation::Factor(5,1), Factorisation(1));
    EXPECT_EQ(Factorisation(25) - Factorisation::Factor(5,1), Factorisation(5));
    EXPECT_EQ(Factorisation(125) - Factorisation::Factor(5,1), Factorisation(25));
    EXPECT_THROW(Factorisation(5) - Factorisation::Factor(5,2), std::range_error);
    EXPECT_EQ(Factorisation(25) - Factorisation::Factor(5,2), Factorisation(1));
    EXPECT_EQ(Factorisation(125) - Factorisation::Factor(5,2), Factorisation(5));
    EXPECT_THROW(Factorisation(7) - Factorisation::Factor(5,1), std::range_error);
}


TEST(TEST_Factorisation, Factorisation_divisors) {
    EXPECT_EQ(Factorisation(0).getDivisors(), std::set<Factorisation::value_type>({1}));
    EXPECT_EQ(Factorisation(1).getDivisors(), std::set<Factorisation::value_type>({1}));
    EXPECT_EQ(Factorisation(2).getDivisors(), std::set<Factorisation::value_type>({1,2}));
    EXPECT_EQ(Factorisation(3).getDivisors(), std::set<Factorisation::value_type>({1,3}));
    EXPECT_EQ(Factorisation(4).getDivisors(), std::set<Factorisation::value_type>({1,2,4}));
    EXPECT_EQ(Factorisation(12).getDivisors(), std::set<Factorisation::value_type>({1,2,3,4,6,12}));
    EXPECT_EQ(Factorisation(36).getDivisors(), std::set<Factorisation::value_type>({1,2,3,4,6,9,12,18,36}));
}


TEST(TEST_Factorisation, Factorisation_gcd) {
#define TEST_GCD(A,B,ANS) \
    EXPECT_EQ(Factorisation(A).gcd(Factorisation(B)), Factorisation(ANS)); \
    EXPECT_EQ(Factorisation(B).gcd(Factorisation(A)), Factorisation(ANS));

    TEST_GCD(1,1,1);
    TEST_GCD(1,2,1);
    TEST_GCD(1,3,1);
    TEST_GCD(1,4,1);
    TEST_GCD(2,2,2);
    TEST_GCD(2,3,1);
    TEST_GCD(2,4,2);
    TEST_GCD(2,6,2);
    TEST_GCD(6,9,3);
    TEST_GCD(54,135,27);

#undef TEST_GCD
}

TEST(TEST_Factorisation, Factorisation_lcm) {
#define TEST_LCM(A,B,ANS) \
EXPECT_EQ(Factorisation(A).lcm(Factorisation(B)), Factorisation(ANS)); \
EXPECT_EQ(Factorisation(B).lcm(Factorisation(A)), Factorisation(ANS));

    TEST_LCM(1,1,1);
    TEST_LCM(1,2,2);
    TEST_LCM(1,3,3);
    TEST_LCM(1,4,4);
    TEST_LCM(2,2,2);
    TEST_LCM(2,3,6);
    TEST_LCM(2,4,4);
    TEST_LCM(2,6,6);
    TEST_LCM(6,9,18);
    TEST_LCM(54,135,270);

#undef TEST_LCM
}
