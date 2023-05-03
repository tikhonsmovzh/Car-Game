//
// Created by tikho on 03.05.2023.
//

#include "GameObject.h"

GameObject::GameObject(Vector2 pos, Vector2 sc, std::string name, Color col) {
    color = col;
    position = pos;
    scale = sc;
    this->name = name;
}