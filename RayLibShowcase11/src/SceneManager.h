//
// Created by tikho on 03.05.2023.
//

#ifndef RAYLIBSHOWCASE_SCENEMANAGER_H
#define RAYLIBSHOWCASE_SCENEMANAGER_H

#include <raylib.h>
#include <vector>
#include "Scene.h"
#include <string>

class Scene;

class SceneManager {
    std::vector<Scene *> scenes;

    int loadedScene = 0;

    Camera2D *camera;

    bool isExit = false;

    Font TextFont;

public:
    bool update();

    void LoadScene(int);

    SceneManager(Camera2D *, Vector2 *, std::vector<Scene*>);

    void StopGame();

    ~SceneManager();
};


#endif //RAYLIBSHOWCASE_SCENEMANAGER_H
