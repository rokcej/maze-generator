#pragma once

#include "maze_generator.h"
#include <vector>

/**
 * Wilson's algorithm for generating all possible spanning trees with equal probability
 */
class WilsonMazeGenerator : public MazeGenerator {
public:
	WilsonMazeGenerator(int width, int height);
	Maze Generate() override;

private:
	int GetRandomWalkStartIndex(const std::vector<bool>& is_in_tree, int offset);
};
