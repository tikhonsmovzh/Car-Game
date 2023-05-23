//
// Created by voroncoved on 23.05.2023.
//

#include "SceneCharacterSelection.h"

SceneCharacterSelection::SceneCharacterSelection(int num): Scene(num) {
}

void SceneCharacterSelection::Load() {
    leftButton = new Button({screen->x / 2 - 300, screen->y / 2 + 150, 200, 100}, "LEFT", TextFont);
    rightButton = new Button({screen->x / 2 + 300, screen->y / 2 + 150, 200, 100}, "RIGHT", TextFont);
    selectButton = new Button({screen->x / 2, screen->y / 2 + 300, 200, 100}, "SELECT", TextFont);
    Cars.push_back(LoadTexture("../resources/texture/cars/car1.png"));
    Cars.push_back(LoadTexture("../resources/texture/cars/car2.png"));
    maxFlag = Cars.size();
}

void SceneCharacterSelection::UnLoad() {
    delete leftButton;
    delete rightButton;
    delete selectButton;
}

void SceneCharacterSelection::updateInterface() {
    leftButton->update();
    rightButton->update();
    selectButton->update();
    if(leftButton->isTouch)
        flagCars--;
    if(rightButton->isTouch)
        flagCars++;
    if(selectButton->isTouch)
        sceneManager->LoadScene(1);
    if(flagCars >= maxFlag)
        flagCars = 0;
    if(flagCars < 0)
        flagCars = maxFlag - 1;
    DrawTexture(Cars[flagCars], 650, 300, WHITE);
}

