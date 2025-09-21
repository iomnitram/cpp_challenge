#include "challenge_2.h"
#include <mymath.h>

using namespace Challenge_2;


std::uint64_t Challenge_2::gcd_4(std::int64_t a, std::int64_t b) noexcept {
    auto absA = abs_to_u(a);
    auto absB = abs_to_u(b);
    if (std::min(absA,absB)==0)
        return abs_to_u(std::max(absA,absB));
    auto div_a = Factorisation(absA).getDivisors();
    auto div_b = Factorisation(absB).getDivisors();

    for (auto it = div_a.rbegin(); it != div_a.rend(); ++it)
        if (div_b.contains(*it))
            return *it;
    return 1;
}

std::uint64_t Challenge_2::gcd_5(int64_t a, int64_t b) noexcept {
    auto absA = abs_to_u(a);
    auto absB = abs_to_u(b);
    if (std::min(absA,absB)==0)
        return abs_to_u(std::max(absA,absB));

    return Factorisation(absA).gcd(Factorisation(absB)).value();
}
