#include "World.h"
#include <raylib.h>
#include "SceneManager.h"

int main() {
    Vector2 screen {1500, 850};

    Camera2D camera {{screen.x / 2, screen.y / 2}, {0, 0}, 0, 0.5};

	InitWindow(screen.x, screen.y, "game");
	SetTargetFPS(60);
    SetExitKey(KEY_TAB);

	SceneManager sceneManager(&camera, &screen, {
        new World(0)
    });

	while (!WindowShouldClose() && !sceneManager.update());

	CloseWindow();

	return 0;
}