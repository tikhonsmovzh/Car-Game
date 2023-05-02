//
// Created by fools on 8/7/2021.
//

#ifndef RAYLIBSHOWCASE_WORLD_H
#define RAYLIBSHOWCASE_WORLD_H

#include <raylib.h>
#include <chipmunk_types.h>
#include <chipmunk_private.h>
#include <chipmunk.h>
#include <string>
#include <vector>
#include "Scene.h"
#include "GameObject.h"

class World : public Scene {
    Vector2 physicsToWorldCoord(float x, float y);

    unsigned long long frameCount = 0;

    void DeleteObject(GameObject*);

    void LoadLevel(std::vector<GameObject*>);

    std::vector<GameObject*> *level;

    cpSpace *mSpace;

public:
	World(int);

	void update();

    GameObject* FindName(std::string);

    GameObject *GetLetShape(cpShape *);

    unsigned long long GetFrameCount();

    void Destroy(GameObject*);

    void SpawnObject(GameObject*);

    void Load();

    void UnLoad();

    void SceneLoad();

    bool isPause = false;
};

#endif //RAYLIBSHOWCASE_WORLD_H
