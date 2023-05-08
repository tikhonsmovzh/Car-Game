//
// Created by smovzhta on 05.05.2023.
//

#ifndef RAYLIBSHOWCASE_CAR_H
#define RAYLIBSHOWCASE_CAR_H

#include "GameObject.h"
#include <raylib.h>
#include <string>
#include <iostream>

class World;

class Car : public GameObject {
    float overclocking, wheelAngle = 0, rotation = 0, phisRotation = 0, wheelUp, wheelDown, wheelLeft, wheelRight, speed = 0, wheelRotSpeed;

    const Color wheelColor = GRAY;

    int axis;

    const Vector2 wheelScale {15, 30};

    bool isGas = false;

    Vector2 carOrigin;

protected:
    void Rotation(int);

    void updateCar();

    void gas(float);

public:
    Car(Vector2 pos, Vector2 scale, float wheelRotSpeed, int wheelDistance, float overclocking, int axis);

    virtual void draw() = 0;

    void Shape(cp::Space *);
};


#endif //RAYLIBSHOWCASE_CAR_H
