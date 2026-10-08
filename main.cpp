#include "game.hpp"

#include <chrono>
#include <iostream>

int main() {
    const auto seed = static_cast<unsigned>(
        std::chrono::system_clock::now().time_since_epoch().count()
    );
    HighCardGame game(seed);
    game.play(std::cin, std::cout);
    return 0;
}
