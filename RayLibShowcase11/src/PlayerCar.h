//
// Created by tikho on 07.05.2023.
//

#ifndef RAYLIBSHOWCASE_PLAYERCAR_H
#define RAYLIBSHOWCASE_PLAYERCAR_H

#include "Car.h"

class PlayerCar: public Car {
    const float speed = 5;

    const int wheel = 2;

public:
    PlayerCar(Vector2);

    void draw();
};


#endif //RAYLIBSHOWCASE_PLAYERCAR_H
