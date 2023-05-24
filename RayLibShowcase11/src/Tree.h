//
// Created by kachalovkyu on 19.05.2023.
//

#ifndef RAYLIBSHOWCASE_TREE_H
#define RAYLIBSHOWCASE_TREE_H

#include "GameObject.h"
#include <chipmunk.hpp>

class World;

class Tree: public GameObject{
    Texture2D texture2D;
public:
    Tree(Vector2);

    void Shape(cp::Space*);

    void draw();
};


#endif //RAYLIBSHOWCASE_BARRIER_H

