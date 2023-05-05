#include "World.h"
#include <raylib.h>
#include "SceneManager.h"
#include "SceneRoad.h"

int main() {
    Vector2 screen {1500, 850};

    Camera2D camera {{0, 0}, {0, 0}, 0, 1};

	InitWindow(screen.x, screen.y, "game");
	SetTargetFPS(60);
    SetExitKey(KEY_TAB);

	SceneManager sceneManager(&camera, &screen, {
        new SceneRoad(0),
        new World(1)
    });

	while (!WindowShouldClose() && !sceneManager.update());

	CloseWindow();

	return 0;
}