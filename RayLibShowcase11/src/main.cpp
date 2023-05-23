#include <raylib.h>
#include "SceneManager.h"
#include "World.h"
#include "StartScene.h"

int main() {
    Vector2 screen {1500, 850};

    Camera2D camera{{screen.x / 2, screen.y / 2}, {0, 0}, 0, 1};

    InitWindow((int)screen.x, (int)screen.y, "Car game");
    SetTargetFPS(60);
    SetExitKey(KEY_TAB);

    SceneManager sceneManager(&camera, &screen, {
        new StartScene(0),
        new World(1)
    });

    while (!WindowShouldClose() && !sceneManager.update());

    CloseWindow();

	return 0;
}