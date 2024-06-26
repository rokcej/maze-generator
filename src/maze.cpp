#include "maze.h"
#include <cassert>

Maze::Maze(int width, int height)
	: width_(width)
	, height_(height)
	, cells_(width * height) {
}

int Maze::GetWidth() const {
	return width_;
}

int Maze::GetHeight() const {
	return height_;
}

const Cell& Maze::GetCell(int i) const {
	return cells_[i];
}

const std::vector<Cell>& Maze::GetCells() const {
	return cells_;
}

std::vector<int> Maze::GetNeighbors(int i) const {
	const int y = i / width_;
	const int x = i % width_;

	std::vector<int> neighbors;
	if (y > 0) {
		neighbors.push_back(i - width_);
	}
	if (y < height_ - 1) {
		neighbors.push_back(i + width_);
	}
	if (x > 0) {
		neighbors.push_back(i - 1);
	}
	if (x < width_ - 1) {
		neighbors.push_back(i + 1);
	}
	return neighbors;
}

void Maze::SetPath(int i, int j, bool value) {
	auto& first = cells_[i];
	auto& second = cells_[j];

	const int delta = j - i;
	Direction direction;
	if (delta == +1) {
		direction = Direction::kRight;
	} else if (delta == -1) {
		direction = Direction::kLeft;
	} else if (delta == +width_) {
		direction = Direction::kUp;
	} else if (delta == -width_) {
		direction = Direction::kDown;
	} else {
		assert(false);
	}

	first.paths[(int)direction] = value;
	second.paths[((int)direction + 2) % 4] = value;
}
