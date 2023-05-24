//
// Created by voroncoved on 23.05.2023.
//

#include "SceneCharacterSelection.h"

SceneCharacterSelection::SceneCharacterSelection(int num): Scene(num) {
    Cars.push_back(LoadTexture("../resources/texture/cars/car1.png"));
    Cars.push_back(LoadTexture("../resources/texture/cars/car2.png"));
    maxFlag = Cars.size();
}

void SceneCharacterSelection::Load() {
    leftButton = new Button({screen->x / 2 - 300, screen->y / 2 + 150, 200, 100}, "Left", TextFont);
    rightButton = new Button({screen->x / 2 + 300, screen->y / 2 + 150, 200, 100}, "Right", TextFont);
    selectButton = new Button({screen->x / 2, screen->y / 2 + 300, 200, 100}, "Select", TextFont);
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
        sceneManager->LoadScene(0);

    if(flagCars >= maxFlag)
        flagCars = 0;
    if(flagCars < 0)
        flagCars = maxFlag - 1;

    DrawTexture(Cars[flagCars], 650, 250, WHITE);
    //DrawTexturePro(Cars[flagCars], {0,0, Cars[flagCars].width, Cars[flagCars].height}, {650, 300, Cars[flagCars].width, Cars[flagCars].height}, {0,0}, 0, WHITE);
}

