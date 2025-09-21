#ifndef CPP_CHALLENGE_ABS_H
#define CPP_CHALLENGE_ABS_H

#include <numeric>

template <std::integral T>
[[nodiscard]] constexpr std::make_unsigned_t<T> abs_to_u(T value) noexcept {
    return value >= 0 ?
        static_cast<std::make_unsigned_t<T>>(value)
        : static_cast<std::make_unsigned_t<T>>(-value);
}

#endif //CPP_CHALLENGE_ABS_H