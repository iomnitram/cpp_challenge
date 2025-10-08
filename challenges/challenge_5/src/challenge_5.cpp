#include "challenge_5.h"
#include <prime.h>

using namespace Challenge_5;

std::vector<std::pair<uint64_t, uint64_t>> Challenge_5::sol_1(uint64_t max) {
    std::vector<std::pair<uint64_t, uint64_t>> ans;
    Prime primes;
    auto prime0 = primes.begin();
    auto prime1 = primes.begin();
    while (*prime1 <= max) {
        auto diff = *prime1 - *prime0;
        if (diff == 6)
            ans.push_back(std::make_pair(*prime0++, *prime1++));
        else if (diff < 6 )
            ++prime1;
        else
            ++prime0;
    }
    return ans;
}

std::vector<std::pair<uint64_t, uint64_t>> Challenge_5::sol_2(uint64_t max) {
    std::vector<std::pair<uint64_t, uint64_t>> ans;
    Prime primes;
    for (uint64_t i = 9; i <= max; i += 2) {
        if (primes.isPrime(i) && primes.isPrime(i - 6))
            ans.push_back(std::make_pair(i-6, i));
    }
    return ans;
}
