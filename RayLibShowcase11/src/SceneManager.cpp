//
// Created by tikho on 03.05.2023.
//

#include "SceneManager.h"

bool SceneManager::update() {
    isExit = false;

    BeginDrawing();
    ClearBackground(WHITE);

    BeginMode2D(*camera);

    scenes.at(loadedScene)->update();

    EndMode2D();

    scenes.at(loadedScene)->updateInterface();

    DrawTextEx(TextFont, std::to_string(GetFPS()).c_str(), {3,3}, 30, 3, GREEN);

    EndDrawing();

    return isExit;
}

void SceneManager::LoadScene(int num) {
    for(int i = 0; i < scenes.size(); i++)
    {
        if(scenes.at(i)->number == num) {
            scenes.at(loadedScene)->UnLoad();

            loadedScene = i;

            camera->target = {0, 0};

            scenes.at(i)->Load();

            return;
        }
    }
}

SceneManager::SceneManager(Camera2D *camera2D, Vector2 *screen, std::vector<Scene*> sc) {
    camera = camera2D;

    Font TextFont {};// = LoadFont("../resources/found/technofosiano.ttf");

    this->TextFont = TextFont;

    if (TextFont.texture.id == 0) TextFont = GetFontDefault();

    for(int i = 0; i < sc.size(); i++) {
        scenes.push_back(sc.at(i));
        sc.at(i)->Start(this, TextFont, screen, camera2D);
    }

    scenes.at(0)->Load();

    loadedScene = 0;

    camera->target = {0, 0};
}

void SceneManager::StopGame() {isExit = true;}

SceneManager::~SceneManager() {
    scenes.at(loadedScene)->UnLoad();
}