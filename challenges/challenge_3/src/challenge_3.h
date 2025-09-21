#ifndef CHALLENGE_3_H
#define CHALLENGE_3_H

#include <concepts>
#include <numeric>
#include <mymath.h>
#include <algorithm>

namespace Challenge_3 {

    template<std::input_iterator It>
        requires std::integral<std::iter_value_t<It> >
    std::iter_value_t<It> lcm_1(It first, It last) {
        using T = std::iter_value_t<It>;
        return std::accumulate(first, last, T{1},
                               [](T a, T b) { return std::lcm(a, b); });
    }

    template<std::ranges::range R>
        requires std::integral<std::ranges::range_value_t<R> >
    constexpr auto lcm_2(const R &r) {
        using T = std::ranges::range_value_t<R>;
        return std::accumulate(r.begin(), r.end(), T{1},
                               [](T a, T b) { return std::lcm(a, b); });
    }

    constexpr unsigned int lcm_3() noexcept {
        return 1;
    }

    template<std::integral T, std::integral... Ts>
    constexpr std::make_unsigned_t<std::common_type_t<T, Ts...>> lcm_3(T first, Ts... rest) noexcept {
        using U = std::make_unsigned_t<std::common_type_t<T, Ts...>>;
        return std::lcm(static_cast<U>(abs_to_u(first)), static_cast<U>(lcm_3(rest...)));
    }
};



#endif //CHALLENGE_3_H
