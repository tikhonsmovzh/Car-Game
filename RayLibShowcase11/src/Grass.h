//
// Created by kachalovkyu on 16.05.2023.
//

#ifndef RAYLIBSHOWCASE_GRASS_H
#define RAYLIBSHOWCASE_GRASS_H

#include "GameObject.h"
#include "raylib.h"

class Grass: public GameObject {
    Texture2D texture2D;
public:
    void draw();
    Grass(Vector2);
};


#endif //RAYLIBSHOWCASE_GRASS_H
