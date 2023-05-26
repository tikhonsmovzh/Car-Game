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

    Vector2 degreesToVector(double force, float alpha);

    World *world;

    Font textFont;

    int sign(float);

    Camera2D *camera;

    Vector2 *screen;

public:
    Vector2 position;
    Vector2 scale;
    std::string name;

    GameObject(Vector2, Vector2, std::string, Color);

    std::shared_ptr<cp::Shape> myShape = nullptr;
    std::shared_ptr<cp::Body> myBody = nullptr;

    virtual void Shape(cp::Space *){}
    virtual void Start(){}

    void Awake(World *, Font, Camera2D *, Vector2 *);

    virtual void update(){}
    virtual void draw(){}
    virtual void drawInterface(Vector2){}

    virtual void updateThread(){}

    virtual void destroy(){}

    virtual void Touch(GameObject *, cpContactPointSet){}
};


#endif //RAYLIBSHOWCASE_GAMEOBJECT_H
