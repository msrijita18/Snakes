// Created by Srijita Mallick on 18/10/20.

#include "snake.h"
#include "ncurses.h"

#include <vector> 
#include <utility> 

// Declaring snake's coordinates at start
std::vector< std::pair< int, int > > snake{};

// Corridnates of the latest tail that was removed
int last_snake_x; 
int last_snake_y;

std::pair< int, int > snake_head{};

void InitSnake() {
    snake.clear();

    // Initial length and initial coordinates
    snake.push_back({LINES/2, COLS/2});
    snake.push_back({LINES/2, COLS/2 + 1});
    snake.push_back({LINES/2, COLS/2 + 2});

    snake_head = {LINES/2, COLS/2};

    last_snake_x = LINES/ 2;
    last_snake_y = COLS/ 2 + 3;

    PaintSnake();
}

void PaintSnake() {
   for (int i = 0; i < snake.size(); ++i) {
       int x = snake[i].first;
       int y = snake[i].second;

       move(x, y);
       addstr("\u2588");
   }
}

// Moves snake
std::pair< int, int > MoveSnake(int key) {
    // remove tail
    last_snake_x = snake[0].first;
    last_snake_y = snake[0].second;
    snake.pop_back();
    int prev_head_x = snake_head.first;
    int prev_head_y = snake_head.second;
    int next_head_x;
    int next_head_y;

    if (key == KEY_UP) {
        next_head_x = prev_head_x - 1;
        next_head_y = prev_head_y;
    } else if (key == KEY_DOWN) {
        next_head_x = prev_head_x + 1;
        next_head_y = prev_head_y;
    } else if (key == KEY_LEFT) {
        next_head_x = prev_head_x;
        next_head_y = prev_head_y - 1;
    } else if (key == KEY_RIGHT) {
        next_head_x = prev_head_x;
        next_head_y = prev_head_y + 1;
    }

    snake.insert(snake.begin(), {next_head_x, next_head_y});
    snake_head = {next_head_x, next_head_y};

    return snake_head;
}

// Detects collision
bool DetectCollision() {
    int head_x = snake[0].first;
    int head_y = snake[0].second;

    // Checks if the head of snake doesn;'t collide with the boundary
    if (head_x == 0 or head_x == LINES - 1) {
        return TRUE;
    }
    if (head_y == 0 or head_y == COLS - 1) {
        return TRUE;
    }

    // Checks if the head of the snake doesn't collide with its body
    for (int i = 1; i < snake.size(); ++i) {
        if (snake[i] == std::make_pair(head_x, head_y)) {
            return TRUE;
        }
    }
    return FALSE;
}

// Grows the snake's size
void GrowSnake() {
    snake.push_back({last_snake_x, last_snake_y});
}