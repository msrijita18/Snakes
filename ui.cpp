// Created by Srijita Mallick on 18/10/20.

#include "ui.h"

// Prints the border in UI 
void PrintBorder() {

    for(int i = 0; i < COLS; i++) {
        move(0, i);
        addstr("\u2588");
        move(LINES - 1, i);
        addstr("\u2588");
    }

    for(int i = 0; i < LINES; i++) {
        move(i, 0);
        addstr("\u2588");
        move(i, COLS - 1);
        addstr("\u2588");
    }
    refresh();
}

// Initialises the UI
void InitUi() {
    
    setlocale(LC_ALL, "");      // override the default locale
    initscr();                  // initilizes the ncurses mode
    curs_set(0);                // hide the cursor
    noecho();                   // prevents printing out whatever you typed
    cbreak();                   // generate an interrupt on ctrl+c
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}


// Exits the ncurses mode and restores the previous terminal
void TearDownUi() {
    endwin(); 
}
