cmake_minimum_required(VERSION 3.16)
project(high_card_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(card_game card.cpp game.cpp)
target_include_directories(card_game PUBLIC .)

add_executable(high_card_game main.cpp)
target_link_libraries(high_card_game PRIVATE card_game)

add_executable(card_game_tests test_card_game.cpp)
target_link_libraries(card_game_tests PRIVATE card_game)

enable_testing()
add_test(NAME card_game_tests COMMAND card_game_tests)
