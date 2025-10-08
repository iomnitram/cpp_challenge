#ifndef CHALLENGE_5_H
#define CHALLENGE_5_H
#include <cstdint>
#include <utility>
#include <vector>


namespace Challenge_5 {

    using F_Param = int64_t;
    using F_Return = std::vector<std::pair<uint64_t, uint64_t>>;

    std::vector<std::pair<uint64_t, uint64_t>> sol_1(uint64_t max);
    std::vector<std::pair<uint64_t, uint64_t>> sol_2(uint64_t max);
};



#endif //CHALLENGE_5_H
