#include "World.h"
#include <raylib.h>

int main() {
    Vector2 screen {1500, 850};

	InitWindow(screen.x, screen.y, "game");
	SetTargetFPS(60);
    SetExitKey(KEY_TAB);

	auto w = World();

	while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        w.update();

        EndDrawing();
    }

	CloseWindow();

	return 0;
}