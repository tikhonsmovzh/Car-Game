//
// Created by tikho on 01.05.2023.
//

#include "Button.h"

Button::Button(Rectangle rect, std::string text, Font TextFont, int font, Color col) {
    rectangle = rect;

    fontSize = font;

    startPos = {rectangle.x, rectangle.y};

    rectangle.x -= rectangle.width / 2;
    rectangle.y -= rectangle.height / 2;

    drawRectangle = rectangle;

    this->text = text;
    this->TextFont = TextFont;

    this->col = col;
}

void Button::update(Vector2 camera) {
    Color drawCol = col;
    isTouch = false;

    if (!CheckCollisionPointRec({(float)GetMouseX() + camera.x, (float)GetMouseY() + camera.y}, drawRectangle)) {
        if(scale > 0)
            scale--;
    } else{
        if(scale < maxScale)
            scale++;

        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            drawCol = { (unsigned char)(col.r - 30), col.g, col.b, col.a } ;

        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            isTouch = true;
    }

    drawRectangle = {rectangle.x - scale + camera.x, rectangle.y - scale + camera.y, rectangle.width + scale * 2, rectangle.height + scale * 2};

    DrawRectanglePro({drawRectangle.x - shadowScale, drawRectangle.y - shadowScale,
                      drawRectangle.width + shadowScale * 2, drawRectangle.height + shadowScale * 2},
                     {0,0}, 0, {0,0,0, (unsigned char)(100 * ((float)scale / maxScale))});

    DrawRectanglePro(drawRectangle, {0, 0}, 0, drawCol);

    TextSize = {(float)((text.size()) * 20) , 40};

    DrawTextEx(TextFont, text.c_str(), {startPos.x + camera.x - TextSize.x / 2, startPos.y + camera.y - TextSize.y / 2}, fontSize, 3, BLACK);
    //DrawTextPro(TextFont, text.c_str(), {startPos.x + camera.x, startPos.y + camera.y}, {TextSize.x / 2, TextSize.y / 2},0, fontSize, 3, BLACK);
}