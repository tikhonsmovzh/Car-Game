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
    const int wheelRotSpeed = 1;
    const int wheelDistance = 18;

    const Color wheelColor = GRAY;

    const int axis = 75;

    const Vector2 wheelScale {15, 30};

    int wheelAngle = 0, rotation = 0, phisRotation = 0;

    Texture2D carTexture;
    Rectangle carSource;
    Vector2 carOrigin;

    float wheelUp, wheelDown, wheelLeft, wheelRight;

protected:
    void Rotation(int);

    void updateCar();

    void gas(float);

public:
    Car(Vector2);

    virtual void draw() = 0;

    void Shape(cp::Space *);
};


#endif //RAYLIBSHOWCASE_CAR_H
