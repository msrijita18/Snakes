// Created by Srijita Mallick on 18/10/20.

#include <chrono> 
#include "constants.h"
#include "ui.h"
#include "game.h"
#include "food.h"
using namespace std; 

int key = ERR;

// Moves the game ahead by the specifying time here
void EventLoop() {
    auto last_time = chrono::system_clock::now();
    auto current_time = chrono::system_clock::now();
    int delta_t;
    while(true) {
        current_time = chrono::system_clock::now();
        delta_t = chrono::duration_cast<chrono::milliseconds>(
                      current_time - last_time
                  ).count(); // count the number of units that have passed
        if(delta_t > TICK_INTERVAL) {
            int k = getch();
            if (k != ERR) {
                key = k;
            }
            tick(key);
            refresh();
            last_time = current_time;
        }
    }
}

int main() {
    InitUi();
    EventLoop();
    TearDownUi();
    return 0;
}
