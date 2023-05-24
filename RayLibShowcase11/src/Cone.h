//
// Created by kachalovkyu on 19.05.2023.
//

#ifndef RAYLIBSHOWCASE_CONE_H
#define RAYLIBSHOWCASE_CONE_H

#include "GameObject.h"
class cone: public GameObject {
public:
    cone(Vector2);

    void Shape(cp::Space*);

    void draw();

};


#endif //RAYLIBSHOWCASE_COIN_H
