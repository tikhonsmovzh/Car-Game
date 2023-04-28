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
	int mScreenWidth = 800;
	int mScreenHeight = 450;

	std::vector<std::pair<cpVect, cpVect>> mFloorEnds{};
	std::vector<cpShape*> mFloors{};
	cpSpace* mSpace;
	cpShape* mBallOne;
	cpShape* mBallTwo;

	cpBody* mBallBodyOne;
	cpBody* mBallBodyTwo;
	Color playerColor;
public:
	World();

	Vector2 physicsToWorldCoord(float x, float y);

	~World();

	void update();
};

enum COLLISION_TYPES{
	PLAYER,
	OBJECT,
	WALL
};

#endif //RAYLIBSHOWCASE_WORLD_H
