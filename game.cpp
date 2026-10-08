#include "game.hpp"

#include <iostream>
#include <limits>

HighCardGame::HighCardGame(unsigned seed) : generator_(seed) {}

Card HighCardGame::drawCard() {
    std::uniform_int_distribution<int> rank(2, 14);
    std::uniform_int_distribution<int> suit(0, 3);
    return Card(rank(generator_), static_cast<Suit>(suit(generator_)));
}

void HighCardGame::play(std::istream& input, std::ostream& output) {
    output << "Welcome to High Card!\n";
    char again = 'y';
    int round = 1;

    while (again == 'y') {
        const Card first = drawCard();
        const Card second = drawCard();
        output << "\nRound " << round << "\n";
        output << "Player 1 draws " << first.toString() << "\n";
        output << "Player 2 draws " << second.toString() << "\n";

        const int result = compareCards(first, second);
        if (result > 0) {
            ++firstScore_;
            output << "Player 1 wins the round.\n";
        } else if (result < 0) {
            ++secondScore_;
            output << "Player 2 wins the round.\n";
        } else {
            output << "The round is a draw.\n";
        }

        output << "Score: " << firstScore_ << " - " << secondScore_ << "\n";
        output << "Play another round? (y/n): ";

        while (!(input >> again) || (again != 'y' && again != 'n')) {
            input.clear();
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            output << "Please enter y or n: ";
        }
        ++round;
    }

    output << "Final score: " << firstScore_ << " - " << secondScore_ << "\n";
}
