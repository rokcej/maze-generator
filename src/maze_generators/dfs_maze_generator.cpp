#include "dfs_maze_generator.h"
#include "src/util.h"
#include <stack>
#include <vector>

DfsMazeGenerator::DfsMazeGenerator(int width, int height)
	: MazeGenerator(width, height) {
}

Maze DfsMazeGenerator::Generate() {
	Maze maze(width_, height_);
	std::vector<bool> visited(maze.GetWidth() * maze.GetHeight(), false);
	std::stack<int> stack;

	const int i_root = util::GetRandomInt(maze.GetWidth() * maze.GetHeight() - 1);
	stack.push(i_root);
	visited[i_root] = true;

	while (!stack.empty()) {
		const int i_current = stack.top();

		std::vector<int> candidates;
		for (const auto& i_neighbor : maze.GetNeighbors(i_current)) {
			if (!visited[i_neighbor]) {
				candidates.push_back(i_neighbor);
			}
		}
		if (candidates.empty()) {
			stack.pop();
			continue;
		}

		const int i_next = candidates[util::GetRandomInt((int)candidates.size() - 1)];
		stack.push(i_next);
		visited[i_next] = true;
		maze.SetPath(i_current, i_next, true);
	}

	return maze;
}
