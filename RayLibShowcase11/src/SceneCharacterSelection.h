//
// Created by voroncoved on 23.05.2023.
//

#ifndef RAYLIBSHOWCASE_SCENECHARACTERSELECTION_H
#define RAYLIBSHOWCASE_SCENECHARACTERSELECTION_H

#include <raylib.h>
#include <string>
#include <iostream>
#include <vector>
#include "Scene.h"
#include "Button.h"

class SceneCharacterSelection: public Scene {
    Button *leftButton, *rightButton, *selectButton;

    std::vector <Texture2D> Cars;

    int maxFlag;

public:
    int flagCars = 0;
    SceneCharacterSelection(int);

    void Load();

    void UnLoad();

    void updateInterface();
};


#endif //RAYLIBSHOWCASE_SCENECHARACTERSELECTION_H
