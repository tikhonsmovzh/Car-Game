//
// Created by tikho on 03.05.2023.
//

#include "SceneManager.h"

bool SceneManager::update() {
    isExit = false;

    BeginDrawing();
    BeginMode2D(*camera);

    ClearBackground(WHITE);

    scenes.at(loadedScene)->update();

    EndMode2D();
    EndDrawing();

    return isExit;
}

void SceneManager::LoadScene(int num) {
    for(int i = 0; i < scenes.size(); i++)
    {
        if(scenes.at(i)->number == num) {
            scenes.at(loadedScene)->UnLoad();

            loadedScene = i;

            scenes.at(i)->Load();

            return;
        }
    }
}

SceneManager::SceneManager(Camera2D *camera2D, Vector2 *screen, std::vector<Scene*> sc) {
    camera = camera2D;
    Font TextFont {};// = LoadFont("../resources/found/technofosiano.ttf");

    if (TextFont.texture.id == 0) TextFont = GetFontDefault();

    for(int i = 0; i < sc.size(); i++) {
        scenes.push_back(sc.at(i));
        sc.at(i)->Start(this, &TextFont, screen, camera2D);
    }

    scenes.at(0)->Load();

    loadedScene = 0;
}

void SceneManager::StopGame() {isExit = true;}

SceneManager::~SceneManager() {
    scenes.at(loadedScene)->UnLoad();
}