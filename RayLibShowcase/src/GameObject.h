//
// Created by tikho on 02.05.2023.
//

#ifndef RAYLIBSHOWCASE_GAMEOBJECT_H
#define RAYLIBSHOWCASE_GAMEOBJECT_H

#include <chipmunk_types.h>
#include <chipmunk_private.h>
#include <chipmunk.h>
#include <string>
#include "World.h"
#include <raylib.h>
#include "GameObject.h"

class GameObject {
public:
    cpShape *myShape;
    cpBody *myBody;

    std::string name;

    virtual void Shape(cpSpace *);
    virtual void Start(World *);

    virtual void draw();
    virtual void drawInterface(Vector2);

    virtual void Touch(GameObject *, cpContactPointSet);
};

#endif //RAYLIBSHOWCASE_GAMEOBJECT_H
