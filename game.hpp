#pragma once

#include "card.hpp"

#include <iosfwd>
#include <random>

class HighCardGame {
public:
    explicit HighCardGame(unsigned seed);

    Card drawCard();
    void play(std::istream& input, std::ostream& output);

private:
    std::mt19937 generator_;
    int firstScore_ = 0;
    int secondScore_ = 0;
};
