//
// Created by smovzhta on 19.05.2023.
//

#include "BotCar.h"

BotCar::BotCar(Vector2 pos, std::vector<Vector2*> *road): Car(pos, {75, 150},
                                                                       0.4, 35, 0.08, 75, 9, 6, road) {
    static Texture2D texture2D;

    int choosing = GetRandomValue(0, 1);

    if(choosing == 1)
        texture2D = LoadTexture("../resources/texture/cars/car1.png");
    else if(choosing == 0)
        texture2D = LoadTexture("../resources/texture/cars/car2.png");

    settings(&texture2D);
}

void BotCar::update() {
    float targetDegree = std::atan2(position.y - checkpoints->at(currentCheckpoint)->y,
                                    position.x - checkpoints->at(currentCheckpoint)->x) * 180 / PI - 90;

    float difference = int(targetDegree - (float)rotation) % 360;

    if(difference == 0)
        Rotation(0);
    else if(difference > 0 && difference < 180 || difference < -180)
        Rotation(wheel);
    else
        Rotation(-wheel);

    gas(maxSpeed);

    updateCar();
}