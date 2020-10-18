// Created by Srijita Mallick on 18/10/20.

#include <utility>

#ifndef SLITHER_SNAKE_H
#define SLITHER_SNAKE_H

void InitSnake();
void PaintSnake();
std::pair< int, int > MoveSnake(int key);
void GrowSnake();
bool DetectCollision();

#endif //SLITHER_SNAKE_H