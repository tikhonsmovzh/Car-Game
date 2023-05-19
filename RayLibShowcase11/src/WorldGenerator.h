//
// Created by voroncoved on 05.05.2023.
//

#ifndef RAYLIBSHOWCASE_WORLDGENERATOR_H
#define RAYLIBSHOWCASE_WORLDGENERATOR_H

#include <iostream>
#include <raylib.h>
#include <vector>
#include "Asphalt.h"
#include "GameObject.h"
#include "Barrier.h"

class WorldGenerator{
    const float step = 300;

    const int maxlen = 999999;
    const int  minLen = 100;

    const Vector2 scale = {85, 150};

    int len, side, oldSide, side2, countSide = 0, firstSide = 0;

    bool boolFirst = false, boolEnd = false;

    GameObject*** Matrix;

    Vector2 NowPos ={85*5, 85*5}, Start ={85*5, 85*5}, sideAndCount = {0,0};

    Vector2 GetRand(Vector2, GameObject***, int);
    void reload();
    void generate();

public:
    std::vector<GameObject*> full_generate();
    ~WorldGenerator();

    std::vector<GameObject *> road;
};


#endif //RAYLIBSHOWCASE_WORLDGENERATOR_H
