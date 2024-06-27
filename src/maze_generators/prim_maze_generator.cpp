#include "prim_maze_generator.h"
#include "src/util.h"
#include <vector>
#include <set>
#include <queue>

PrimMazeGenerator::PrimMazeGenerator(int width, int height)
	: MazeGenerator(width, height) {
}

Maze PrimMazeGenerator::Generate() {
	Maze maze(width_, height_);

	const int i_root = util::GetRandomInt(maze.GetWidth() * maze.GetHeight() - 1);
	std::set<int> tree = { i_root };
	std::priority_queue<Edge> frontier;
	for (const auto& i_neighbor : maze.GetNeighbors(i_root)) {
		frontier.push({ i_root, i_neighbor, util::GetRandomFloat() });
	}

	while (!frontier.empty()) {
		const auto edge = frontier.top();
		frontier.pop();

		if (tree.find(edge.i_to) != tree.end()) {
			continue;
		}
		tree.insert(edge.i_to);
		maze.SetPath(edge.i_from, edge.i_to, true);

		for (const auto& i_neighbor : maze.GetNeighbors(edge.i_to)) {
			if (tree.find(i_neighbor) == tree.end()) {
				frontier.push({ edge.i_to, i_neighbor, util::GetRandomFloat() });
			}
		}
	}

	return maze;
}
