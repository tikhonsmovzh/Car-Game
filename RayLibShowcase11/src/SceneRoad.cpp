//
// Created by voroncoved on 05.05.2023.
//

#include "SceneRoad.h"

SceneRoad::SceneRoad(int num) : Scene(num) {}

void SceneRoad::update() {
    if(len < maxlen){
        side = GetRand(NowPos, boolMatrix);
        //side = GetRandomValue(1, 4);
        if(side == 1 && oldSide != 3)   NowPos.y = NowPos.y - 10;
        if(side == 2 && oldSide != 4)   NowPos.x = NowPos.x + 10;
        if(side == 3 && oldSide != 1)   NowPos.y = NowPos.y + 10;
        if(side == 4 && oldSide != 2)   NowPos.x = NowPos.x - 10;
        road.push_back(NowPos);
        boolMatrix[int(NowPos.y/10)][int(NowPos.x/10)] = true;
        for(int i = 0;i < road.size(); i++){
            DrawRectangle(road[i].x, road[i].y, 10, 10, BLACK);
        }
        DrawRectangle(NowPos.x, NowPos.y, 10, 10, RED);
        oldSide = side;
        len++;
    }
}

void SceneRoad::Load() {
    road.push_back(NowPos);
    boolMatrix = new bool*[85];
    for (int i = 0; i < 85; i++) {
        boolMatrix[i] = new bool[150];
    }
    for (int i = 0; i < 85; ++i) {
        for (int j = 0; j < 150; ++j) {
            boolMatrix[i][j] = false;
        }
    }
}

void SceneRoad::UnLoad() {

}

int SceneRoad::GetRand(Vector2 NowPos, bool** boolMatrix) {
    side2 = GetRandomValue(1, 4);
    std::cout << side << ' ' << int((NowPos.y-10)/10) << ' ' << int(NowPos.x+10)/10 << '\n';
    if(side2 == 1 && (boolMatrix[int((NowPos.y-10)/10)][int(NowPos.x+10)/10] || boolMatrix[int((NowPos.y-10)/10)][int(NowPos.x-10)/10] || boolMatrix[int((NowPos.y-20)/10)][int(NowPos.x)/10])){
        side2 = GetRand(NowPos, boolMatrix);
    }
    if(side2 == 2 && (boolMatrix[int((NowPos.y-10)/10)][int(NowPos.x+10)/10] || boolMatrix[int((NowPos.y+10)/10)][int(NowPos.x+10)/10] || boolMatrix[int((NowPos.y)/10)][int(NowPos.x+20)/10])){
        side2 = GetRand(NowPos, boolMatrix);
    }
    if(side2 == 3 && (boolMatrix[int((NowPos.y+10)/10)][int(NowPos.x+10)/10] || boolMatrix[int((NowPos.y+10)/10)][int(NowPos.x-10)/10] || boolMatrix[int((NowPos.y+20)/10)][int(NowPos.x)/10])){
        side2 = GetRand(NowPos, boolMatrix);
    }
    if(side2 == 4 && (boolMatrix[int((NowPos.y-10)/10)][int(NowPos.x-10)/10] || boolMatrix[int((NowPos.y+10)/10)][int(NowPos.x-10)/10] || boolMatrix[int((NowPos.y)/10)][int(NowPos.x-20)/10])){
        side2 = GetRand(NowPos, boolMatrix);
    }
    return side2;
}
