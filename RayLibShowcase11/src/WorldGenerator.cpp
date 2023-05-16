//
// Created by voroncoved on 05.05.2023.
//

#include "WorldGenerator.h"

WorldGenerator::~WorldGenerator() {
    if(Matrix != nullptr) {
        for (int i = 0; i < scale.x; i++)
            delete Matrix[i];

        delete Matrix;
    }
}

Vector2 WorldGenerator::GetRand(Vector2 NowPos, GameObject*** worldMatrix, int countSide) {
    side2 = GetRandomValue(1, 4);

    if(countSide > 20){
        reload();

        return sideAndCount;
    }
    if(!boolFirst){
        firstSide = side2;

        boolFirst = true;

        sideAndCount.x = firstSide;

       // std::cout<< firstSide << "\n";

        sideAndCount.y = 0;

        return sideAndCount;
    }
    //std::cout << side << ' ' << int((NowPos.y-10)/10) << ' ' << int(NowPos.x+10)/10 << '\n';
    if(side2 == 1 && (worldMatrix[int((NowPos.y-10)/10)][int(NowPos.x+10)/10] != nullptr || worldMatrix[int((NowPos.y-10)/10)][int(NowPos.x-10)/10] != nullptr|| worldMatrix[int((NowPos.y-20)/10)][int(NowPos.x)/10] != nullptr)){
        countSide++;
        sideAndCount = GetRand(NowPos, worldMatrix, countSide);
        countSide = sideAndCount.y;
    }
    else if(side2 == 2 && (worldMatrix[int((NowPos.y-10)/10)][int(NowPos.x+10)/10] != nullptr || worldMatrix[int((NowPos.y+10)/10)][int(NowPos.x+10)/10] != nullptr || worldMatrix[int((NowPos.y)/10)][int(NowPos.x+20)/10] != nullptr)){
        countSide++;
        sideAndCount = GetRand(NowPos, worldMatrix, countSide);
    }
    else if(side2 == 3 && (worldMatrix[int((NowPos.y+10)/10)][int(NowPos.x+10)/10] != nullptr || worldMatrix[int((NowPos.y+10)/10)][int(NowPos.x-10)/10] != nullptr || worldMatrix[int((NowPos.y+20)/10)][int(NowPos.x)/10] != nullptr)){
        countSide++;
        sideAndCount = GetRand(NowPos, worldMatrix, countSide);
    }
    else if(side2 == 4 && (worldMatrix[int((NowPos.y-10)/10)][int(NowPos.x-10)/10] != nullptr || worldMatrix[int((NowPos.y+10)/10)][int(NowPos.x-10)/10] != nullptr || worldMatrix[int((NowPos.y)/10)][int(NowPos.x-20)/10] != nullptr)){
        countSide++;
        sideAndCount = GetRand(NowPos, worldMatrix, countSide);
    }
    else {
        countSide = 0;
    }
    sideAndCount = {(float)side2, (float)countSide};
    return sideAndCount;
}

void WorldGenerator::reload() {
    boolEnd = false;
    boolFirst = false;
    len = 0;

    if(Matrix != nullptr)
    {
        for (int i = 0; i < scale.x; ++i) {
            for (int j = 0; j < scale.y; ++j)
                //if(Matrix[i][j] != nullptr)
                    delete Matrix[i][j];
        }

        for (int i = 0; i < scale.x; i++)
            delete Matrix[i];

        delete Matrix;
    }

    Matrix = new GameObject **[(int)scale.x];

    for (int i = 0; i < scale.x; i++)
        Matrix[i] = new GameObject *[(int)scale.y];

    for (int i = 0; i < scale.x; ++i) {
        for (int j = 0; j < scale.y; ++j)
            Matrix[i][j] = nullptr;
    }

    Matrix[(int)scale.x/2][(int)scale.x/2] = new Asphalt({scale.x/2*step, scale.x/2*step});

    for(int i = 0;i < scale.x; i++){
        Matrix[0][i] = new Asphalt({0, step * i});
        Matrix[(int)scale.x-1][i] = new Asphalt({(scale.x-1)*step, i*step});
    }

    for(int i = 0;i < scale.x; i++){
        Matrix[i][0] = new Asphalt({step * i, 0});
        Matrix[i][(int)scale.x-1] = new Asphalt({step * i, step * (scale.x-1)});
    }

    NowPos = Start;
}

void WorldGenerator::generate() {
    sideAndCount = GetRand(NowPos, Matrix, countSide);
    side = sideAndCount.x;

    if(side == 1 && oldSide != 3)   NowPos.y = NowPos.y - 10;
    if(side == 2 && oldSide != 4)   NowPos.x = NowPos.x + 10;
    if(side == 3 && oldSide != 1)   NowPos.y = NowPos.y + 10;
    if(side == 4 && oldSide != 2)   NowPos.x = NowPos.x - 10;

    Matrix[int(NowPos.y/10)][int(NowPos.x/10)] = new Asphalt({NowPos.y/10*step, NowPos.x/10*step});
    road.push_back(Matrix[int(NowPos.y/10)][int(NowPos.x/10)]->position);


    oldSide = side;
    len++;
}

std::vector<GameObject*> WorldGenerator::full_generate() {
    reload();

    while(!boolEnd){
        if(len < maxlen)
        {
            if(firstSide != 0 && minLen < len &&
                    (((NowPos.x == Start.x + 20 || NowPos.x == Start.x - 20) && NowPos.y == Start.y) ||
                     ((NowPos.y == Start.y - 20 || NowPos.y == Start.y + 20) && NowPos.x == Start.x)))/*((((NowPos.x == Start.x + 20 && NowPos.y == Start.y) || (NowPos.x == Start.x && NowPos.y == Start.y - 20)) &&
            ((NowPos.x == Start.x - 20 && NowPos.y == Start.y) ||
            (NowPos.x == Start.x && NowPos.y == Start.y + 20))) ||
            ((NowPos.x == Start.x && NowPos.y == Start.y + 20) || (NowPos.x == Start.x - 20 && NowPos.y == Start.y) || (NowPos.x == Start.x && NowPos.y == Start.y - 20)) ||
            ((NowPos.x == Start.x - 20 && NowPos.y == Start.y) || (NowPos.x == Start.x + 20 && NowPos.y == Start.y) || (NowPos.x == Start.x && NowPos.y == Start.y + 20))))*/
            {
                boolEnd = true;

                if(Start.x == NowPos.x) {
                    Matrix[(int) (Start.y + NowPos.y) / 20][(int) Start.x / 10] = new Asphalt(
                            {(Start.y + NowPos.y) / 20 * step, Start.x / 10 * step});
                }
                else {
                    Matrix[(int) Start.y / 10][(int) (Start.x + NowPos.x) / 20] = new Asphalt(
                            {Start.y / 10 * step, (Start.x + NowPos.x) / 20 * step});
                }
            }
            else
                generate();
        }
    }

    std::vector<GameObject*> world;

    for (int i = 0; i < scale.x; ++i) {
        for (int j = 0; j < scale.y; ++j) {
            if(Matrix[i][j] != nullptr) {
                world.push_back(Matrix[i][j]);
            }
        }
    }



    return world;
}