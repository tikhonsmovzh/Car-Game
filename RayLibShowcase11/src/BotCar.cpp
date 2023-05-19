//
// Created by smovzhta on 19.05.2023.
//

#include "BotCar.h"

BotCar::BotCar(Vector2 pos, std::vector<GameObject*> *road): Car(pos, {75, 150},
                                                                       0.4, 35, 0.05, 75, 9, road) {
    static Texture2D texture2D = LoadTexture("../resources/texture/cars/car2.png");

    settings(&texture2D);
}

void BotCar::update() {
    float targetDegree = std::atan2(position.y - checkpoints.at(currentCheckpoint)->position.y - 125,
                                    position.x - checkpoints.at(currentCheckpoint)->position.x - 125) * 180 / PI - 90;

    float difference = int(targetDegree - (float)rotation) % 360;

    //std::cout << targetDegree << ' ' << difference << '\n';

    if(difference == 0)
        Rotation(0);
    else if(difference > 0 && difference < 180 || difference < -180)
        Rotation(wheel);
    else
        Rotation(-wheel);

    gas(speed);

    updateCar();
}

void BotCar::draw() {
    drawCar();

    DrawRectangleV({checkpoints.at(currentCheckpoint)->position.x + 125,
                    checkpoints.at(currentCheckpoint)->position.y + 125},
                   {50, 50}, GREEN);
}