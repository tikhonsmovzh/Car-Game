//
// Created by smovzhta on 05.05.2023.
//

#ifndef RAYLIBSHOWCASE_CAR_H
#define RAYLIBSHOWCASE_CAR_H

#include "GameObject.h"
#include <raylib.h>
#include <string>
#include <iostream>

class Car : public GameObject {
    Rectangle carRect;

    const float speed = 0.14;

    const int wheel = 2;
    const int wheelRotSpeed = 1;
    const int wheelDistance = 18;

    const Color wheelColor = GRAY;

    const int axis = 75;

    const Vector2 wheelScale {15, 30};

    float currentSpeed = 0;

    void gas(float);

    int wheelAngle = 0, rot = 0;

    void rotation(int);

    void updateCar();

public:
    Car(Vector2);

    void draw();
};


#endif //RAYLIBSHOWCASE_CAR_H
