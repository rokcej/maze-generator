#pragma once

#include "maze_generator.h"

/**
 * Based on Prim's algorithm
 */
class PrimMazeGenerator : public MazeGenerator {
private:
	struct Candidate {
		int i_from;
		int i_to;
	};

public:
	PrimMazeGenerator(int width, int height);
	Maze Generate() override;
};
