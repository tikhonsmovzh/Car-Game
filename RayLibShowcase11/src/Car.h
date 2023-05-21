//
// Created by smovzhta on 05.05.2023.
//

#ifndef RAYLIBSHOWCASE_CAR_H
#define RAYLIBSHOWCASE_CAR_H

#include "GameObject.h"
#include <raylib.h>
#include <string>
#include <iostream>
#include <vector>

class World;

class Car : public GameObject {
    float overclocking, wheelUp, wheelDown, wheelLeft, wheelRight, speed = 0, axis;

    const Color wheelColor {105, 105, 105, 255};

    const Vector2 wheelScale {15, 30};

    float wheelRotSpeed, wheelAngle;

    const float checkDist = 260;

    bool isGas = false, isAsphaltTouch = false;

    Vector2 carOrigin;

    Texture2D *carTexture;
    Rectangle carSource;

protected:
    void Rotation(float);

    void updateCar();
    void drawCar();

    void gas(float);

    void settings(Texture2D *);

    std::vector<Vector2 *> *checkpoints;

    float rotation = 0;
    int currentCheckpoint = 0;

    float GetSpeed();

public:
    Car(Vector2 pos, Vector2 scale, float wheelRotSpeed, int wheelDistance, float overclocking, int axis, int deepening, std::vector<Vector2 *> *);

    virtual void update();
    virtual void draw();

    void Shape(cp::Space *);

    void Touch(GameObject *, cpContactPointSet);
};


#endif //RAYLIBSHOWCASE_CAR_H
