//
// Created by tikho on 03.05.2023.
//

#include "GameObject.h"
#include "World.h"

GameObject::GameObject(Vector2 pos, Vector2 sc, std::string name, Color col) {
    color = col;
    position = pos;
    scale = sc;
    this->name = name;
}

Vector2 GameObject::physicsToWorldCoord(float x, float y) {
    return {x, y};
}

Vector2 GameObject::degreesToVector(double force, int alpha)
{
    double yC = alpha * PI / 180;

    return {(float)(force * std::sin(yC) * 180 / PI), (float)(force * std::cos(yC) * 180 / PI)};
}