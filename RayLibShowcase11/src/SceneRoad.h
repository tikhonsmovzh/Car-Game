//
// Created by voroncoved on 05.05.2023.
//

#ifndef RAYLIBSHOWCASE_SCENEROAD_H
#define RAYLIBSHOWCASE_SCENEROAD_H

#include "Scene.h"
#include <iostream>

class SceneRoad: public Scene{
public:
    SceneRoad(int);
    void update();
    void Load();
    void UnLoad();
    int len, maxlen = 999999,minLen = 15, side, oldSide, side2, countSide = 0, firstSide = 0;
    bool boolFirst = false, boolEnd = false;
    std::vector<Vector2> road;
    bool** boolMatrix;
    void updateMatrix(bool** matrix){}
    const int scale =80;
    Vector2 NowPos ={(float)scale*5, (float)scale*5}, Start ={(float)scale*5, (float)scale*5}, sideAndCount = {0,0};
    void reload();
    void generate();
    void draw();
    void full_generate();

    Vector2 GetRand(Vector2 NowPos, bool** boolMatrix, int countSide);
};


#endif //RAYLIBSHOWCASE_SCENEROAD_H
