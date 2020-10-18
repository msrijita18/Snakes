// Created by Srijita Mallick on 18/10/20.

#include "game.h"
#include "ui.h"
#include "ncurses.h"
#include "constants.h"
#include "food.h"
#include "snake.h"

// Initialising game status
int current_game_state = kStateGameBeforeStart;
int current_score = 0;
int current_direction = KEY_UP;

// Prints game status
void PrintStatus() {
    move(0, 5);

    if (current_game_state == kStateGameBeforeStart) {
        printw("Press any key to start.");
    } else {
        printw("Current Score: %d", current_score);
    }
}

// Starts the game and snake moves
void StartGame() {
    current_score = 0;
    current_game_state = kStateGameStarted;
    current_direction = KEY_UP;

    erase();
    InitFood();
    InitSnake();
    PrintFood();
}

// Moves the snake ahead 
void tick(int key) {

    // move the game ahead by 1 tick
    if (current_game_state == kStateGameBeforeStart) {
        erase();
        PrintBorder();
        PrintStatus();
        if (key != ERR) {
            StartGame();
        }
    } else {

        erase();

        std::pair< int, int > snake_head_coords;
        if (key == KEY_UP && current_direction != KEY_DOWN) {
//            snake_head_coords = MoveSnake(KEY_UP);
            current_direction = KEY_UP;
        } else if (key == KEY_DOWN && current_direction != KEY_UP ) {
//            snake_head_coords = MoveSnake(KEY_DOWN);
            current_direction = KEY_DOWN;
        } else if (key == KEY_LEFT && current_direction != KEY_RIGHT) {
//            snake_head_coords = MoveSnake(KEY_LEFT);
            current_direction = KEY_LEFT;
        } else if (key == KEY_RIGHT && current_direction != KEY_LEFT) {
//            snake_head_coords = MoveSnake(KEY_RIGHT);
            current_direction = KEY_RIGHT;
        }

        snake_head_coords = MoveSnake(current_direction);

        if (key != ERR) {
            if (ConsumeFood(snake_head_coords.first, snake_head_coords.second)) {
                GrowSnake();
                current_score += 1;
            }
        }
        
        PrintBorder();
        PrintStatus();
        PaintSnake();
        PrintFood();

        if (DetectCollision()) {
            current_game_state = kStateGameBeforeStart;
        }
    }
}