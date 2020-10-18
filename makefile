slither: main.cpp ui.cpp game.cpp food.cpp snake.cpp
	g++ main.cpp ui.cpp game.cpp food.cpp snake.cpp -lncursesw -o ./slither && ./slither