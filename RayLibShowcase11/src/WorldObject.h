//
// Created by kachalovkyu on 12.05.2023.
//

#ifndef RAYLIBSHOWCASE_WORLDOBJECT_H
#define RAYLIBSHOWCASE_WORLDOBJECT_H

#include <raylib.h>


class WorldObject {
public:
    virtual void draw(){}
    virtual bool IsPhysical(){return false;}
};


#endif //RAYLIBSHOWCASE_WORLDOBJECT_H
