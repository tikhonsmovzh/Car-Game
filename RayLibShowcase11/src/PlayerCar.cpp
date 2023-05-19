//
// Created by tikho on 07.05.2023.
//

#include "PlayerCar.h"

PlayerCar::PlayerCar(Vector2 pos, std::vector<GameObject*> *road): Car(pos, {75, 150},
                                       1, 35, 0.3, 75, 9, road) {
    static Texture2D texture2D = LoadTexture("../resources/texture/cars/car2.png");

    settings(&texture2D);
}

void PlayerCar::update() {
    camera->target = position;

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

    updateCar();
}

void PlayerCar::Start() {
    updateCar();
}

void PlayerCar::draw() {
    drawCar();

    DrawRectangleV({checkpoints.at(currentCheckpoint)->position.x + 125,
                    checkpoints.at(currentCheckpoint)->position.y + 125},
                   {50, 50}, BLACK);
}