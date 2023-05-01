//
// Created by fools on 8/7/2021.
//

#ifndef RAYLIBSHOWCASE_WORLD_H
#define RAYLIBSHOWCASE_WORLD_H

#include <raylib.h>
#include <chipmunk_types.h>
#include <chipmunk.h>
#include <vector>
#include "Scene.h"

class World : public Scene {
    Vector2 physicsToWorldCoord(float x, float y);

public:
	World(int);

	void update();

    void Load();

    void UnLoad();
};

#endif //RAYLIBSHOWCASE_WORLD_H
