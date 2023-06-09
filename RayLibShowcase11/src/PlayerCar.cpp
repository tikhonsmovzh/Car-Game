//
// Created by tikho on 07.05.2023.
//

#include "PlayerCar.h"
#include "World.h"

PlayerCar::PlayerCar(Vector2 pos, std::vector<Vector2*> *road, int choosing): Car(pos, {75, 150},
                                       0.4, 35, 0.08, 75, 9, 6, road) {
    static Texture2D texture2D;

    if(choosing == 0)
        texture2D = LoadTexture("../resources/texture/cars/car1.png");
    else if(choosing == 1)
        texture2D = LoadTexture("../resources/texture/cars/car2.png");

    settings(&texture2D);
}

void PlayerCar::update() {
    camera->target = position;

    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        gas(maxSpeed);
    else if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        gas(-maxSpeed);

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        Rotation(-wheel);
    else if (IsKeyDown((KEY_D)) || IsKeyDown(KEY_RIGHT))
        Rotation(wheel);
    else
        Rotation(0);

    updateCar();

    camera->zoom = 1 - std::abs(GetSpeed() / 100);
}

void PlayerCar::Start() {

}

void PlayerCar::draw() {
    drawCar();

    DrawRectangleV({checkpoints->at(currentCheckpoint)->x - 25,
                    checkpoints->at(currentCheckpoint)->y - 25},
                   {50, 50}, BLACK);
}

void PlayerCar::drawInterface(Vector2) {
    if(world->countCircle - passedCircle != 0)
        DrawTextEx(textFont, ("remaining circles: " + std::to_string(world->countCircle - passedCircle)).c_str(), {500, 10}, 60, 3, BLACK);
}