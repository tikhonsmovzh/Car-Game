//
// Created by tikho on 05.05.2023.
//

#ifndef RAYLIBSHOWCASE_BARRIER_H
#define RAYLIBSHOWCASE_BARRIER_H

#include "GameObject.h"
#include <chipmunk.hpp>

class World;

class Barrier: public GameObject{
public:
    Barrier(Vector2);

    void Shape(cp::Space*);

    void draw();

    void Touch(GameObject *, cpContactPointSet);
};


#endif //RAYLIBSHOWCASE_BARRIER_H
