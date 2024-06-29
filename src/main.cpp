#include "maze.h"
#include "maze_generators/prim_maze_generator.h"
#include "maze_generators/dfs_maze_generator.h"
#include "maze_generators/wilson_maze_generator.h"
#include "raylib.h"

void DrawMaze(const Maze& maze) {
	// Configuration
	constexpr Color path_color{ 240, 240, 240, 255 };
	constexpr Color wall_color{ 16, 16,16, 255 };
	constexpr float path_thickness = 0.5f;

	// Draw walls
	ClearBackground(wall_color);

	// Draw path
	constexpr float wall_thickness = 0.5f * (1.0f - path_thickness);
	const int cell_width = GetScreenWidth() / maze.GetWidth();
	const int cell_height = GetScreenHeight() / maze.GetHeight();
	for (int y = 0; y < maze.GetHeight(); ++y) {
		for (int x = 0; x < maze.GetWidth(); ++x) {
			// The y axis should be flipped when drawing, but it's not necessary in this case
			const auto& cell = maze.GetCell(y * maze.GetWidth() + x);

			// Horizontal
			const float dx_min = cell.paths[(int)Direction::kLeft] ? 0.0f : wall_thickness;
			const float dx_max = cell.paths[(int)Direction::kRight] ? 1.0f : 1.0f - wall_thickness;
			DrawRectangle(
				(x + dx_min) * cell_width,
				(y + wall_thickness) * cell_height,
				(dx_max - dx_min) * cell_width,
				path_thickness * cell_height,
				path_color
			);

			// Vertical
			const float dy_min = cell.paths[(int)Direction::kDown] ? 0.0f : wall_thickness;
			const float dy_max = cell.paths[(int)Direction::kUp] ? 1.0f : 1.0f - wall_thickness;
			DrawRectangle(
				(x + wall_thickness) * cell_width,
				(y + dy_min) * cell_height,
				path_thickness * cell_width,
				(dy_max - dy_min) * cell_height,
				path_color
			);
		}
	}
}

int main() {
	constexpr int maze_width = 16;
	constexpr int maze_height = 16;

	// const Maze maze = PrimMazeGenerator(maze_width, maze_height).Generate();
	// const Maze maze = DfsMazeGenerator(maze_width, maze_height).Generate();
	const Maze maze = WilsonMazeGenerator(maze_width, maze_height).Generate();

	InitWindow(512, 512, "Maze Generator");
	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawMaze(maze);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
