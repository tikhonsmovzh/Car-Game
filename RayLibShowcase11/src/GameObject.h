//
// Created by tikho on 03.05.2023.
//

#ifndef RAYLIBSHOWCASE_GAMEOBJECT_H
#define RAYLIBSHOWCASE_GAMEOBJECT_H

#include <chipmunk.hpp>
#include <string>
#include <raylib.h>
#include <cmath>

class World;

class GameObject {
protected:
    Color color;

    Vector2 physicsToWorldCoord(float x, float y);

    Vector2 degreesToVector(double force, int alpha);
public:
    Vector2 position;
    Vector2 scale;
    std::string name;

    GameObject(Vector2, Vector2, std::string, Color);

    std::shared_ptr<cp::Shape> myShape;
    std::shared_ptr<cp::Body> myBody;

    virtual void Shape(cp::Space *){}
    virtual void Start(World *){}

    virtual void draw(){}
    virtual void drawInterface(Vector2){}

    virtual void Touch(GameObject *, cpContactPointSet){}
};


#endif //RAYLIBSHOWCASE_GAMEOBJECT_H
