//
// Created by voroncoved on 05.05.2023.
//

#include "SceneRoad.h"

SceneRoad::SceneRoad(int num) : Scene(num) {}

void SceneRoad::update() {
    //for(int i;
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        full_generate();
    }
    draw();
}

void SceneRoad::Load() {
    full_generate();
}

void SceneRoad::UnLoad() {

}

Vector2 SceneRoad::GetRand(Vector2 NowPos, bool** boolMatrix, int countSide) {
    side2 = GetRandomValue(1, 4);
    if(countSide > 20){
        reload();
        return sideAndCount;
    }
    if(!boolFirst){
        firstSide = side2;
        boolFirst = true;
        sideAndCount.x = firstSide;
        std::cout<< firstSide << "\n";
        sideAndCount.y = 0;
        return sideAndCount;
    }
    //std::cout << side << ' ' << int((NowPos.y-10)/10) << ' ' << int(NowPos.x+10)/10 << '\n';
    if(side2 == 1 && (boolMatrix[int((NowPos.y-10)/10)][int(NowPos.x+10)/10] || boolMatrix[int((NowPos.y-10)/10)][int(NowPos.x-10)/10] || boolMatrix[int((NowPos.y-20)/10)][int(NowPos.x)/10])){
        countSide++;
        sideAndCount = GetRand(NowPos, boolMatrix, countSide);
        countSide = sideAndCount.y;
    }
    else if(side2 == 2 && (boolMatrix[int((NowPos.y-10)/10)][int(NowPos.x+10)/10] || boolMatrix[int((NowPos.y+10)/10)][int(NowPos.x+10)/10] || boolMatrix[int((NowPos.y)/10)][int(NowPos.x+20)/10])){
        countSide++;
        sideAndCount = GetRand(NowPos, boolMatrix, countSide);
    }
    else if(side2 == 3 && (boolMatrix[int((NowPos.y+10)/10)][int(NowPos.x+10)/10] || boolMatrix[int((NowPos.y+10)/10)][int(NowPos.x-10)/10] || boolMatrix[int((NowPos.y+20)/10)][int(NowPos.x)/10])){
        countSide++;
        sideAndCount = GetRand(NowPos, boolMatrix, countSide);
    }
    else if(side2 == 4 && (boolMatrix[int((NowPos.y-10)/10)][int(NowPos.x-10)/10] || boolMatrix[int((NowPos.y+10)/10)][int(NowPos.x-10)/10] || boolMatrix[int((NowPos.y)/10)][int(NowPos.x-20)/10])){
        countSide++;
        sideAndCount = GetRand(NowPos, boolMatrix, countSide);
    }
    else {
        countSide = 0;
    }
    sideAndCount = {(float)side2, (float)countSide};
    return sideAndCount;
}

void SceneRoad::reload() {
    boolEnd = false;
    boolFirst = false;
    len = 0;
    for(int i = road.size(); i > 0;i--)
    {
        road.pop_back();
    }
    boolMatrix = new bool*[85];
    for (int i = 0; i < 85; i++) {
        boolMatrix[i] = new bool[150];
    }
    for (int i = 0; i < 85; ++i) {
        for (int j = 0; j < 150; ++j) {
            boolMatrix[i][j] = false;
        }
    }
    boolMatrix[scale/2][scale/2] = true;
    for(int i = 0;i < scale; i++){
        boolMatrix[0][i] = true;
        boolMatrix[scale-1][i] = true;
    }
    for(int i = 0;i < scale; i++){
        boolMatrix[i][0] = true;
        boolMatrix[i][scale-1] = true;
    }
    road.push_back(Start);
    NowPos = Start;
}

void SceneRoad::generate() {
    sideAndCount = GetRand(NowPos, boolMatrix, countSide);
    side = sideAndCount.x;
    //side = GetRandomValue(1, 4);
    if(side == 1 && oldSide != 3)   NowPos.y = NowPos.y - 10;
    if(side == 2 && oldSide != 4)   NowPos.x = NowPos.x + 10;
    if(side == 3 && oldSide != 1)   NowPos.y = NowPos.y + 10;
    if(side == 4 && oldSide != 2)   NowPos.x = NowPos.x - 10;
    road.push_back(NowPos);
    boolMatrix[int(NowPos.y/10)][int(NowPos.x/10)] = true;
//        for(int i = 0;i < road.size(); i++){
//            DrawRectangle(road[i].x, road[i].y, 10, 10, BLACK);
//        }
//        DrawRectangle(NowPos.x, NowPos.y, 10, 10, RED);
    oldSide = side;
    len++;
    //=i;
}

void SceneRoad::draw() {
//    for(int i = 0;i < road.size(); i++){
//        DrawRectangle(road[i].x, road[i].y, 10, 10, BLACK);
//    }
    for (int i = 0; i < 85; ++i) {
        for (int j = 0; j < 150; ++j) {
            if(boolMatrix[i][j]){
                DrawRectangle(i*10,j*10,10,10,BLACK);
            }
        }
    }
    //DrawRectangle(NowPos.x, NowPos.y, 10, 10, RED);
}

void SceneRoad::full_generate() {
    reload();
    while(!boolEnd){
        if(len < maxlen)
            //=;i++)
        {
            if(firstSide == 0){
                generate();
            }
            else if(firstSide == 1 && ((NowPos.x == Start.x - 20 && NowPos.y == Start.y) || (NowPos.x == Start.x + 20 && NowPos.y == Start.y) || (NowPos.x == Start.x && NowPos.y == Start.y - 20))&&minLen < len && !boolEnd){
                draw();
                boolEnd = true;
                std::cout << firstSide << " end" << "\n";
                if(Start.x == NowPos.x){
                    boolMatrix[(int)(Start.y+NowPos.y)/20][(int)Start.x/10] = true;
                }
                else{
                    boolMatrix[(int)Start.y/10][(int)(Start.x+NowPos.x)/20] = true;
                }
            }
            else if(firstSide == 2 && ((NowPos.x == Start.x && NowPos.y == Start.y + 20) || (NowPos.x == Start.x + 20 && NowPos.y == Start.y) || (NowPos.x == Start.x && NowPos.y == Start.y - 20))&&minLen < len && !boolEnd){
                draw();
                boolEnd = true;
                std::cout << firstSide << " end" << "\n";
                if(Start.x == NowPos.x){
                    boolMatrix[(int)(Start.y+NowPos.y)/20][(int)Start.x/10] = true;
                }
                else{
                    boolMatrix[(int)Start.y/10][(int)(Start.x+NowPos.x)/20] = true;
                }
            }
            else if(firstSide == 3 && ((NowPos.x == Start.x - 20 && NowPos.y == Start.y) || (NowPos.x == Start.x + 20 && NowPos.y == Start.y) || (NowPos.x == Start.x && NowPos.y == Start.y + 20))&&minLen < len && !boolEnd){
                draw();
                boolEnd = true;
                std::cout << firstSide << " end" << "\n";
                if(Start.x == NowPos.x){
                    boolMatrix[(int)(Start.y+NowPos.y)/20][(int)Start.x/10] = true;
                }
                else{
                    boolMatrix[(int)Start.y/10][(int)(Start.x+NowPos.x)/20] = true;
                }
            }
            else if(firstSide == 4 && ((NowPos.x == Start.x && NowPos.y == Start.y + 20) || (NowPos.x == Start.x - 20 && NowPos.y == Start.y) || (NowPos.x == Start.x && NowPos.y == Start.y - 20))&&minLen < len && !boolEnd){
                draw();
                boolEnd = true;
                std::cout << firstSide << " end" << "\n";
                if(Start.x == NowPos.x){
                    boolMatrix[(int)(Start.y+NowPos.y)/20][(int)Start.x/10] = true;
                }
                else{
                    boolMatrix[(int)Start.y/10][(int)(Start.x+NowPos.x)/20] = true;
                }
            }
            else{
                generate();
            }
        }
    }
}
