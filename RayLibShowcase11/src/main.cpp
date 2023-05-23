#include "World.h"
#include <raylib.h>
#include "SceneManager.h"
#include "SceneCharacterSelection.h"

int main() {
    Vector2 screen{1500, 850};

    Camera2D camera{{screen.x / 2, screen.y / 2}, {0, 0}, 0, 1};

    InitWindow((int)screen.x, (int)screen.y, "game");
    SetTargetFPS(60);
    SetExitKey(KEY_TAB);
    SceneCharacterSelection *s = new SceneCharacterSelection(0);
    SceneManager sceneManager(&camera, &screen, {
        s,
        new World(1, &s->flagCars)
    });

    while (!WindowShouldClose() && !sceneManager.update());

    CloseWindow();

	return 0;
}