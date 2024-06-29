#include "wilson_maze_generator.h"
#include "src/util.h"
#include <stack>

WilsonMazeGenerator::WilsonMazeGenerator(int width, int height)
	: MazeGenerator(width, height) {
}

Maze WilsonMazeGenerator::Generate() {
	Maze maze(width_, height_);
	const int maze_size = maze.GetWidth() * maze.GetHeight();

	std::vector<bool> is_in_tree(maze_size, false);
	std::vector<bool> is_in_walk(maze_size, false);
	std::stack<int> walk;

	// Pick random node and add it to the tree
	is_in_tree[util::GetRandomInt(maze_size - 1)] = true;

	int i_start = 0;
	while (true) {
		i_start = GetRandomWalkStartIndex(is_in_tree, i_start);
		if (i_start < 0) {
			break;
		}

		// Execute loop-erased random walk until a tree node is found
		int i_current = i_start;
		while (!is_in_tree[i_current]) {
			if (is_in_walk[i_current]) {
				for (int i = walk.top(); i != i_current; i = walk.top()) {
					is_in_walk[i] = false;
					walk.pop();
				}
			} else {
				is_in_walk[i_current] = true;
				walk.push(i_current);
			}

			const auto neighbors = maze.GetNeighbors(i_current);
			i_current = neighbors[util::GetRandomInt((int)neighbors.size() - 1)];
		}

		// Add the loop-erased random walk to the tree
		while (!walk.empty()) {
			const int i_previous = walk.top();
			walk.pop();

			maze.SetPath(i_previous, i_current, true);
			is_in_tree[i_previous] = true;
			is_in_walk[i_previous] = false;
			i_current = i_previous;
		}
	}

	return maze;
}

int WilsonMazeGenerator::GetRandomWalkStartIndex(const std::vector<bool>& is_in_tree, int offset) {
	int i_start = offset;
	while (is_in_tree[i_start]) {
		if (++i_start >= (int)is_in_tree.size()) {
			return -1;
		}
	}
	return i_start;
}
