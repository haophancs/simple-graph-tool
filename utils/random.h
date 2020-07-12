#ifndef RANDOM_H
#define RANDOM_H

#include <random>

using uint32 = unsigned int;

class Random {
public:
    Random() = default;

    explicit Random(std::mt19937::result_type seed) : eng(seed) {}

    uint32 drawNumber(uint32 min, uint32 max) {
        return std::uniform_int_distribution<uint32>{min, max}(eng);
    }

private:
    std::mt19937 eng{std::random_device{}()};
};

#endif //RANDOM_H
