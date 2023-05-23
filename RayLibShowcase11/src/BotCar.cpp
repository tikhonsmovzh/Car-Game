//
// Created by smovzhta on 19.05.2023.
//

#include "BotCar.h"

BotCar::BotCar(Vector2 pos, std::vector<Vector2*> *road): Car(pos, {75, 150},
                                                                       0.4, 42, 0.08, 75, 10, road) {
    static Texture2D texture2D = LoadTexture("../resources/texture/cars/car1.png");

    settings(&texture2D);
}

void BotCar::update() {
    float targetDegree = std::atan2(position.y - checkpoints->at(currentCheckpoint)->y,
                                    position.x - checkpoints->at(currentCheckpoint)->x) * 180 / PI - 90;

    float difference = int(targetDegree - (float)rotation) % 360;

    //std::cout << targetDegree << ' ' << difference << '\n';

    if(difference == 0)
        Rotation(0);
    else if(difference > 0 && difference < 180 || difference < -180)
        Rotation(wheel);
    else
        Rotation(-wheel);

    gas(maxSpeed);

    updateCar();
}