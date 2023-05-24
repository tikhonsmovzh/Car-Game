//
// Created by smovzhta on 23.05.2023.
//

#include "StartScene.h"

StartScene::StartScene(int num): Scene(num) {}

void StartScene::updateInterface() {
    DrawTextEx(TextFont, "Car game", {screen->x / 2 - 160, 70}, 80, 3, BLACK);

    StartButton->update();
    ExitButton->update();
    ChoiceButton->update();

    if(StartButton->isTouch) {
        sceneManager->LoadScene(2);
        return;
    }

    if(ExitButton->isTouch){
        sceneManager->StopGame();
        return;
    }

    if(ChoiceButton->isTouch) {
        sceneManager->LoadScene(1);
        return;
    }
}

void StartScene::Load() {
    StartButton = new Button({screen->x / 2, screen->y / 2 - 70, 300, 90}, "Start", TextFont);
    ExitButton = new Button({screen->x / 2,  screen->y / 2 + 150, 300, 90}, "Exit", TextFont);
    ChoiceButton = new Button({screen->x / 2, screen->y / 2 + 40, 300, 90}, "Choice car", TextFont);
}

void StartScene::UnLoad() {
    delete StartButton;
    delete ExitButton;
}