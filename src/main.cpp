#include "raylib.h"

int main() {
	InitWindow(512, 512, "Maze Generator");
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
