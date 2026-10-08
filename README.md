# C++ High Card Game

A command-line card game in which two players draw cards over multiple rounds. The program compares the cards, keeps score, validates user input, and supports repeatable games through a random seed.

This project is an original portfolio adaptation of concepts practiced in introductory C++ coursework.

## Skills demonstrated

- C++ classes and enums
- Multiple source and header files
- Random number generation
- Stream-based input and output
- Input validation
- Automated tests with CTest

## Build and play

```sh
cmake -S . -B build
cmake --build build
./build/high_card_game
```

## Run the tests

```sh
ctest --test-dir build --output-on-failure
```

