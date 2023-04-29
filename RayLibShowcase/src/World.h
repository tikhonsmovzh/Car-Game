//
// Created by fools on 8/7/2021.
//

#ifndef RAYLIBSHOWCASE_WORLD_H
#define RAYLIBSHOWCASE_WORLD_H

#include <raylib.h>
#include <chipmunk_types.h>
#include <chipmunk.h>
#include <vector>

class World {
public:
	World();

	Vector2 physicsToWorldCoord(float x, float y);

	void update();
};

#endif //RAYLIBSHOWCASE_WORLD_H
