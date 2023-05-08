//
// Created by tikho on 08.05.2023.
//

#ifndef RAYLIBSHOWCASE_ASPHALT_H
#define RAYLIBSHOWCASE_ASPHALT_H

#include "GameObject.h"
#include <chipmunk.hpp>

class Asphalt: public GameObject {
public:
    Asphalt(Vector2);

    void Shape(cp::Space*);

    void draw();
};


#endif //RAYLIBSHOWCASE_ASPHALT_H
