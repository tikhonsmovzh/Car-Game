//
// Created by kachalovkyu on 12.05.2023.
//

#ifndef RAYLIBSHOWCASE_WORLDOBJECT_H
#define RAYLIBSHOWCASE_WORLDOBJECT_H

#include <raylib.h>


class WorldObject {
public:
    Vector2 posit;
    WorldObject(Vector2);
    virtual void draw(){}
};


#endif //RAYLIBSHOWCASE_WORLDOBJECT_H
