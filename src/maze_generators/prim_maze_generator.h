#pragma once

#include "maze_generator.h"

/**
 * Based on Prim's algorithm
 */
class PrimMazeGenerator : public MazeGenerator {
private:
	struct Edge {
		bool operator<(const Edge& other) const {
			return weight < other.weight;
		};

		int i_from;
		int i_to;
		float weight;
	};

public:
	PrimMazeGenerator(int width, int height);
	Maze Generate() override;
};
