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
    float overclocking, wheelAngle = 0, rotation = 0, phisRotation = 0, wheelUp, wheelDown, wheelLeft, wheelRight, speed = 0, wheelRotSpeed;

    const Color wheelColor {105, 105, 105, 255};

    int axis;

    const Vector2 wheelScale {15, 30};

    const float checkDist = 250;

    bool isGas = false, isAsphaltTouch = false;

    Vector2 carOrigin;

    Texture2D *carTexture;
    Rectangle carSource;

protected:
    void Rotation(int);

    void updateCar();
    void drawCar();

    void gas(float);

    void settings(Texture2D *);

    std::vector<GameObject *> checkpoints;

    int currentCheckpoint = 0;

public:
    Car(Vector2 pos, Vector2 scale, float wheelRotSpeed, int wheelDistance, float overclocking, int axis, int deepening, std::vector<GameObject*> *);

    virtual void update();
    virtual void draw();

    void Shape(cp::Space *);

    void Touch(GameObject *, cpContactPointSet);
};


#endif //RAYLIBSHOWCASE_CAR_H
