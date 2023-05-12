//
// Created by fools on 8/7/2021.
//

#ifndef RAYLIBSHOWCASE_WORLD_H
#define RAYLIBSHOWCASE_WORLD_H

#include "chipmunk.hpp"
#include <string>
#include <vector>
#include "Scene.h"
#include "GameObject.h"

#include "PlayerCar.h"
#include "Barrier.h"
#include "Asphalt.h"
#include "SceneRoad.h"

class World : public Scene {
    unsigned long long frameCount = 0;

    void DeleteObject(GameObject*);

    void LoadLevel(std::vector<GameObject*>);

    std::vector<GameObject*> *level;

    cp::Space *mSpace;

    SceneRoad sceneRoad;

public:
    World(int);

    void update();

    GameObject* FindName(std::string);

    GameObject *GetLetShape(std::shared_ptr<cp::Shape>);

    unsigned long long GetFrameCount();

    void Destroy(GameObject*);

    void SpawnObject(GameObject*);

    void Load();

    void UnLoad();

    void SceneLoad();

    bool isPause = false;
};

#endif //RAYLIBSHOWCASE_WORLD_H
