//
// Created by smovzhta on 23.05.2023.
//

#ifndef RAYLIBSHOWCASE_STARTSCENE_H
#define RAYLIBSHOWCASE_STARTSCENE_H

#include "Scene.h"
#include "Button.h"

class StartScene: public Scene {
    Button *StartButton, *ExitButton, *ChoiceButton;

public:
    void Load();
    void UnLoad();

    void updateInterface();

    StartScene(int);
};


#endif //RAYLIBSHOWCASE_STARTSCENE_H
