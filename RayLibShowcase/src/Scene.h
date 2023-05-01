//
// Created by tikho on 01.05.2023.
//

#ifndef RAYLIBSHOWCASE_SCENE_H
#define RAYLIBSHOWCASE_SCENE_H

#include <raylib.h>
#include "SceneManager.h"

class SceneManager;

class Scene {
protected:
    SceneManager *sceneManager;

    Font TextFont;

    Vector2 *screen;
public:
    int number;

    Scene(int);

    virtual void update(){}

    virtual void Load(){}

    virtual void UnLoad(){}

    void Start(SceneManager *, Font, Vector2 *);
};


#endif //RAYLIBSHOWCASE_SCENE_H
