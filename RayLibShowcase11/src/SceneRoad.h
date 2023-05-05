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
    int len, maxlen = 19999999, side, oldSide, side2;
    std::vector<Vector2> road;
    bool** boolMatrix;
    void updateMatrix(bool** matrix){}

    Vector2 NowPos = { 500,500};
    int GetRand(Vector2 NowPos, bool** boolMatrix);
};


#endif //RAYLIBSHOWCASE_SCENEROAD_H
