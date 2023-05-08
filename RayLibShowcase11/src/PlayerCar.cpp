//
// Created by tikho on 07.05.2023.
//

#include "PlayerCar.h"

PlayerCar::PlayerCar(Vector2 pos): Car(pos, {50, 100}, 1, 18, 0.3, 75) {}

void PlayerCar::draw() {
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        gas(speed);
    else if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        gas(-speed);

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        Rotation(-wheel);
    else if (IsKeyDown((KEY_D)) || IsKeyDown(KEY_RIGHT))
        Rotation(wheel);
    else
        Rotation(0);

    camera->target = position;

    updateCar();
}

void PlayerCar::Start() {
    updateCar();
}