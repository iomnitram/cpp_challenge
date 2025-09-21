#ifndef CHALLENGE_2_H
#define CHALLENGE_2_H

#include <complex>
#include <concepts>
#include <cstdint>
#include <numeric>

namespace Challenge_2 {
    constexpr auto gcd_1(std::integral auto a, std::integral auto b) noexcept {
        return std::gcd(a,b);
    }

    constexpr auto gcd_2(std::integral auto a, std::integral auto b) noexcept {
        while (b != 0) {
            a = a % b;
            std::swap(a, b);
        }
        return std::abs(a);
    }

    constexpr auto gcd_3(std::integral auto a, std::integral auto b) noexcept {
        a = abs(a);
        b = abs(b);
        if (std::min(a,b)==0)
            return std::max(a,b);
        for (auto gcd = std::min(a,b); ; --gcd)
            if (a % gcd == 0 && b % gcd == 0)
                return gcd;
    }

    std::uint64_t gcd_4(int64_t a, int64_t b) noexcept;

    std::uint64_t gcd_5(int64_t a, int64_t b) noexcept;
};



#endif //CHALLENGE_2_H
