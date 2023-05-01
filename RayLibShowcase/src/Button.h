//
// Created by tikho on 01.05.2023.
//

#ifndef RAYLIBSHOWCASE_BUTTON_H
#define RAYLIBSHOWCASE_BUTTON_H

#include <raylib.h>
#include "string"

class Button {
    Rectangle rectangle, drawRectangle;

    int scale = 0, fontSize;

    const int maxScale = 5;

    Color col;

    const int shadowScale = 5;

    Font TextFont;

    Vector2 startPos {0,0};

    Vector2 TextSize;

public:
    Button(Rectangle, std::string, Font, int = 40, Color = RED);

    void update(Vector2 camera = {0, 0});

    bool isTouch = false;

    std::string text;
};


#endif //RAYLIBSHOWCASE_BUTTON_H
