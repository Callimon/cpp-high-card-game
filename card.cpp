#include "card.hpp"

#include <array>
#include <stdexcept>

Card::Card(int rank, Suit suit) : rank_(rank), suit_(suit) {
    if (rank < 2 || rank > 14) {
        throw std::invalid_argument("card rank must be between 2 and 14");
    }
}

int Card::rank() const { return rank_; }

Suit Card::suit() const { return suit_; }

std::string Card::toString() const {
    static const std::array<std::string, 4> suitNames{
        "Clubs", "Diamonds", "Hearts", "Spades"
    };

    std::string rankName;
    switch (rank_) {
        case 11: rankName = "Jack"; break;
        case 12: rankName = "Queen"; break;
        case 13: rankName = "King"; break;
        case 14: rankName = "Ace"; break;
        default: rankName = std::to_string(rank_);
    }

    return rankName + " of " + suitNames.at(static_cast<int>(suit_));
}

int compareCards(const Card& first, const Card& second) {
    if (first.rank() < second.rank()) return -1;
    if (first.rank() > second.rank()) return 1;
    return 0;
}
