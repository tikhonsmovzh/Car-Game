//
// Created by fools on 8/7/2021.
//

#include "World.h"
#include <iostream>
#include <memory>

void SetPlayerColorRed(cpArbiter *arb, cpSpace *space, void *data) {
    *((Color *) data) = (Color) {255, 0, 0, 255};
}

void SetPlayerColorGreen(cpArbiter *arb, cpSpace *space, void *data) {
    *((Color *) data) = (Color) {0, 255, 0, 255};
}

World::World() {
    playerColor = GREEN;

    mSpace = cpSpaceNew();
    cpSpaceSetGravity(mSpace, cpVect{0, -100});

    auto newEnds = std::make_pair(
            cpv(0, -(float) mScreenHeight / 2),
            cpv((float) mScreenWidth, -(float) mScreenHeight / 2 - 10));
    mFloorEnds.push_back(newEnds);

    mFloorEnds.push_back(std::make_pair(
            cpv((float) mScreenWidth / 3, 0),
            cpv((float) mScreenWidth / 3 + 10, -(float) mScreenHeight / 2)));

    mFloorEnds.push_back(std::make_pair(
            cpv((float) mScreenWidth / 3, -(float) mScreenHeight / 3),
            cpv((float) mScreenWidth / 3 + 100, -(float) mScreenHeight / 3 - 10)));

    for (auto ends: mFloorEnds) {
//        auto floor = cpSegmentShapeNew(cpSpaceGetStaticBody(mSpace),
//                                       cpVect{ends.first.x, ends.first.y},
//                                       cpVect{ends.second.x, ends.second.y}, 10);
        cpVect *verts = new cpVect[4]{
                cpVect{ends.first.x, ends.first.y},
                cpVect{ends.first.x, ends.second.y},
                cpVect{ends.second.x, ends.second.y},
                cpVect{ends.second.x, ends.first.y},
        };

        auto floor = cpPolyShapeNewRaw(cpSpaceGetStaticBody(mSpace),
                                       4,
                                       verts, 0);
        cpShapeSetFriction(floor, 0.5);
        cpShapeSetElasticity(floor, 0.6);
        cpSpaceAddShape(mSpace, floor);
        cpShapeSetCollisionType(floor, WALL);
        mFloors.push_back(floor);
    }


    mBallBodyOne = cpBodyNew(5, INFINITY);
    mBallBodyTwo = cpBodyNew(5, cpMomentForCircle(5, 0, 20, cpvzero));
    cpBodySetPosition(mBallBodyOne, cpv(mScreenWidth / 2, -mScreenHeight / 4));
    cpBodySetPosition(mBallBodyTwo, cpv(mScreenWidth / 2 + 1, -mScreenHeight / 3));

    cpSpaceAddBody(mSpace, mBallBodyOne);
    cpSpaceAddBody(mSpace, mBallBodyTwo);

    mBallOne = cpCircleShapeNew(mBallBodyOne, 10, cpvzero);
    mBallTwo = cpCircleShapeNew(mBallBodyTwo, 20, cpvzero);
    cpShapeSetFriction(mBallOne, 5);
    cpShapeSetFriction(mBallTwo, 0.5);
    cpShapeSetElasticity(mBallOne, 0.1);
    cpShapeSetElasticity(mBallTwo, 0.9);

    cpSpaceAddShape(mSpace, mBallOne);
    cpSpaceAddShape(mSpace, mBallTwo);

    cpShapeSetCollisionType(mBallOne, PLAYER);
    cpShapeSetCollisionType(mBallTwo, OBJECT);

    auto *handler = cpSpaceAddCollisionHandler(mSpace, PLAYER, OBJECT);
    handler->userData = &playerColor;
    handler->postSolveFunc = SetPlayerColorRed;
    handler->separateFunc = SetPlayerColorGreen;

    InitWindow(mScreenWidth, mScreenHeight, "raylib [core] example - keyboard input");
    SetTargetFPS(60);
}

void World::update() {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    bool checkCollision = false;

    for (auto floorEnd: mFloorEnds) {
        auto worldStart = physicsToWorldCoord(floorEnd.first.x, floorEnd.first.y);
        auto worldEnd = physicsToWorldCoord(floorEnd.second.x, floorEnd.second.y);
        auto radius = 0;
        DrawRectangleRec({
                                 worldStart.x,
                                 worldStart.y,
                                 worldEnd.x - worldStart.x,
                                 worldEnd.y - worldStart.y},
                         RED);
//        DrawLine(worldStart.x, worldStart.y, worldEnd.x, worldEnd.y, RED);
    }
    for (auto floor: mFloors) {
        if (abs(cpShapesCollide(mBallOne, floor).normal.y + 1) <= 0.1) {
            checkCollision = true;
        }
        std::cout << cpShapesCollide(mBallOne, floor).normal.y << '\n';
//        DrawLine(worldStart.x, worldStart.y, worldEnd.x, worldEnd.y, RED);
    }

    auto worldBall1 = physicsToWorldCoord(cpBodyGetPosition(mBallBodyOne).x, cpBodyGetPosition(mBallBodyOne).y);
    auto worldBall2 = physicsToWorldCoord(cpBodyGetPosition(mBallBodyTwo).x, cpBodyGetPosition(mBallBodyTwo).y);

    DrawCircle(worldBall1.x, worldBall1.y, 10, playerColor);
    DrawCircle(worldBall2.x, worldBall2.y, 20, BLUE);

//	cpBodySetAngularVelocity(mBallBodyOne, cpBodyGetAngularVelocity(mBallBodyOne) * 0.98);
    cpBodySetAngularVelocity(mBallBodyTwo, cpBodyGetAngularVelocity(mBallBodyTwo) * 0.98);

    auto velocity = cpvzero;

    if (IsKeyDown(KEY_RIGHT)) velocity.x = -100;
    if (IsKeyDown(KEY_LEFT)) velocity.x = 100;
    if (IsKeyPressed(KEY_UP) && checkCollision) {
        cpBodyApplyImpulseAtLocalPoint(mBallBodyOne, {0, 1000}, {});//velocity.y += 70;
    }
    cpShapeSetSurfaceVelocity(mBallOne, velocity);
//    cpBodySetVelocity(mBallBodyOne, velocity);
//	if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

    cpSpaceStep(mSpace, 1 / 60.0);;

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    EndDrawing();
}

World::~World() {
    CloseWindow();
}

Vector2 World::physicsToWorldCoord(float x, float y) {
    return {x, -y};
}
