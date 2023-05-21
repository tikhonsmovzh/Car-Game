//
// Created by tikho on 07.05.2023.
//

#include "PlayerCar.h"

PlayerCar::PlayerCar(Vector2 pos, std::vector<Vector2*> *road): Car(pos, {75, 150},
                                       0.4, 35, 0.08, 75, 9, road) {
    static Texture2D texture2D = LoadTexture("../resources/texture/cars/car2.png");

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