#pragma once

#include <vector>

enum class Direction {
	kUp = 0,
	kRight = 1,
	kDown = 2,
	kLeft = 3
};

struct Cell {
	bool paths[4] = { false, false, false, false };
};

class Maze {
public:
	Maze(int width, int height);

	int GetWidth() const;
	int GetHeight() const;
	const Cell& GetCell(int i) const;
	const std::vector<Cell>& GetCells() const;
	std::vector<int> GetNeighbors(int i) const;

	void SetPath(int i, int j, bool value);

private:
	int width_ = 0;
	int height_ = 0;
	std::vector<Cell> cells_;
};
