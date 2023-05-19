//
// Created by smovzhta on 19.05.2023.
//

#ifndef RAYLIBSHOWCASE_BOTCAR_H
#define RAYLIBSHOWCASE_BOTCAR_H

#include "GameObject.h"
#include "Car.h"

class BotCar: public Car {
    const float speed = 8;

    const int wheel = 3;

public:
    BotCar(Vector2, std::vector<GameObject*> *);

    void update();

    void draw();
};


#endif //RAYLIBSHOWCASE_BOTCAR_H
