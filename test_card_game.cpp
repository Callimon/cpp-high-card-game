#include "card.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

int main() {
    const Card ace(14, Suit::spades);
    const Card king(13, Suit::hearts);
    const Card anotherAce(14, Suit::clubs);

    assert(ace.toString() == "Ace of Spades");
    assert(king.toString() == "King of Hearts");
    assert(compareCards(ace, king) == 1);
    assert(compareCards(king, ace) == -1);
    assert(compareCards(ace, anotherAce) == 0);

    bool rejectedBadRank = false;
    try {
        Card invalid(15, Suit::clubs);
    } catch (const std::invalid_argument&) {
        rejectedBadRank = true;
    }
    assert(rejectedBadRank);

    std::cout << "All card game tests passed.\n";
    return 0;
}
