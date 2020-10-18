// Created by Srijita Mallick on 18/10/20.

#include <vector>
#include <utility>
#include "ncurses.h"
#include "constants.h"
#include <experimental/random>

std::vector< std::pair< int, int > > food_items{};

// Creates foods for random pair of coordinates {x,y}
void AddFood() {
    int x = std::experimental::randint(1, LINES - 2); 
    int y = std::experimental::randint(1, COLS - 2); 

    food_items.push_back({x, y});
}

// Generates food items equal to kMaxFoodItems
void InitFood() {
    food_items.clear();

    for (int i = 0; i < kMaxFoodItems; ++i) {
        AddFood();
    }
}

// Erases food if consumed
bool ConsumeFood(int x, int y) {
    for (int i = 0; i < kMaxFoodItems; ++i) {
        if (food_items[i] ==  std::make_pair(x, y)) {
            food_items.erase(food_items.begin() + i);
            AddFood();
            return true;
        }
    }
    return false;
}

// Prints food at the specified position
void PrintFood() {
    int number_of_foods = food_items.size();

    for (int i = 0; i < number_of_foods; ++i) {
        int x = food_items[i].first;
        int y = food_items[i].second;

        move(x, y);
        addstr("\u25cb");
    }
}