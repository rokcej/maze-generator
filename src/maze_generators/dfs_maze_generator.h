#pragma once

#include "maze_generator.h"

/**
 * Randomized depth-first search with backtracking
 */
class DfsMazeGenerator : public MazeGenerator {
public:
	DfsMazeGenerator(int width, int height);
	Maze Generate() override;
};
