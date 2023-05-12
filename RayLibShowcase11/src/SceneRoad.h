//
// Created by voroncoved on 05.05.2023.
//

#ifndef RAYLIBSHOWCASE_SCENEROAD_H
#define RAYLIBSHOWCASE_SCENEROAD_H

#include <iostream>
#include <raylib.h>
#include <vector>
#include "WorldObject.h"
#include "Asphalt.h"

class SceneRoad{
    const float step = 300;
public:
    void update();
    void Load();
    void UnLoad();
    int len, maxlen = 999999,minLen = 100, side, oldSide, side2, countSide = 0, firstSide = 0;
    bool boolFirst = false, boolEnd = false;
    std::vector<WorldObject*> road;
    WorldObject*** boolMatrix;
    void updateMatrix(WorldObject*** matrix){}
    const int scale =80;
    Vector2 NowPos ={(float)scale*5, (float)scale*5}, Start ={(float)scale*5, (float)scale*5}, sideAndCount = {0,0};
    void reload();
    void generate();
    void draw();
    void full_generate();

    Vector2 GetRand(Vector2 NowPos, WorldObject*** boolMatrix, int countSide);

};


#endif //RAYLIBSHOWCASE_SCENEROAD_H
