//
// Created by tikho on 07.05.2023.
//

#ifndef RAYLIBSHOWCASE_PLAYERCAR_H
#define RAYLIBSHOWCASE_PLAYERCAR_H

#include "Car.h"

class PlayerCar: public Car {
    const float maxSpeed = 8;

    const int wheel = 3;

public:
    PlayerCar(Vector2, std::vector<Vector2*> *, int choosing);

    void update();

    void Start();

    void draw();
};


#endif //RAYLIBSHOWCASE_PLAYERCAR_H
