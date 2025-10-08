#include "challenge_4.h"
#include <prime.h>
using namespace Challenge_4;


uint64_t Challenge_4::sol_1(uint64_t nbr) {
    if (nbr < 3)
        return 0;
    Prime prime;
    while (!prime.isPrime(--nbr)){}
        return nbr;
}

uint64_t Challenge_4::sol_2(uint64_t nbr) {
    if (nbr < 4) {
        if (nbr == 3)
            return 2;
        return 0;
    }
    if (--nbr % 2 == 0)
        --nbr;
    Prime prime;
    while (!prime.isPrime(nbr)) {
        nbr -=2;
    }
    return nbr;
}
