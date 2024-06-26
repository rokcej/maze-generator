#include "prim_maze_generator.h"
#include "src/util.h"
#include <vector>
#include <set>

PrimMazeGenerator::PrimMazeGenerator(int width, int height)
	: MazeGenerator(width, height) {
}

Maze PrimMazeGenerator::Generate() {
	Maze maze(width_, height_);

	const int i_root = util::GetRandom(maze.GetWidth() * maze.GetHeight() - 1);
	std::set<int> connected = { i_root };
	std::vector<Candidate> candidates;
	for (const auto& i_neighbor : maze.GetNeighbors(i_root)) {
		candidates.push_back({ i_root, i_neighbor });
	}

	while (!candidates.empty()) {
		const int i_candidate = util::GetRandom((int)candidates.size() - 1);
		const auto candidate = candidates[i_candidate];
		candidates.erase(candidates.begin() + i_candidate);

		if (connected.find(candidate.i_to) != connected.end()) {
			continue;
		}
		connected.insert(candidate.i_to);
		maze.SetPath(candidate.i_from, candidate.i_to, true);

		for (const auto& i_neighbor : maze.GetNeighbors(candidate.i_to)) {
			if (connected.find(i_neighbor) == connected.end()) {
				candidates.push_back({ candidate.i_to, i_neighbor });
			}
		}
	}

	return maze;
}
