#include "challenge_1.h"

#include <utility>

using namespace Challenge_1;

uint Challenge_1::solution1(uint max) {
    uint sum = 0;
    for (uint i = 1; i <= max; i++) {
        if (i%3 == 0 || i%5 == 0) {
            sum += i;
        }
    }
    return sum;
}

uint Challenge_1::solution2(uint max) {
    std::pair<uint, uint> rest[] {
        {0, 0},
        {0, 0},
        {0, 0},
        {3, 1},
        {3, 1},
        {8, 2},
        {14, 3},
        {14, 3},
        {14, 3},
        {23, 4},
        {33, 5},
        {33, 5},
        {45, 6},
        {45, 6},
        {45, 6},
    };
    const uint chunkSize = 15;
    const uint chunkValue = 7;
    const uint chunkSum = 60;

    const uint nbChunk = max/chunkSize;
    const uint chunkIdx = max % chunkSize;

    return
    rest[chunkIdx].first
    + rest[chunkIdx].second * nbChunk * chunkSize
    + chunkSum*nbChunk
    + chunkValue * chunkSize * (nbChunk * (nbChunk-1))/2;
}