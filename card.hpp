#pragma once

#include <string>

enum class Suit { clubs, diamonds, hearts, spades };

class Card {
public:
    Card(int rank, Suit suit);

    int rank() const;
    Suit suit() const;
    std::string toString() const;

private:
    int rank_;
    Suit suit_;
};

int compareCards(const Card& first, const Card& second);
