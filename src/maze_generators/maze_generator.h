#pragma once

#include "../maze.h"

class MazeGenerator {
public:
	MazeGenerator(int width, int height);
	virtual Maze Generate() = 0;

protected:
	int width_ = 0;
	int height_ = 0;
};
