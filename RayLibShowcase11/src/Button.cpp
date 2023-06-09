//
// Created by tikho on 03.05.2023.
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

void Button::update() {
    Color drawCol = col;
    isTouch = false;

    if (!CheckCollisionPointRec({(float)GetMouseX(), (float)GetMouseY()}, drawRectangle)) {
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

    drawRectangle = {rectangle.x - scale, rectangle.y - scale, rectangle.width + scale * 2, rectangle.height + scale * 2};

    DrawRectanglePro({drawRectangle.x - shadowScale, drawRectangle.y - shadowScale,
                      drawRectangle.width + shadowScale * 2, drawRectangle.height + shadowScale * 2},
                     {0,0}, 0, {0,0,0, (unsigned char)(100 * ((float)scale / maxScale))});

    DrawRectanglePro(drawRectangle, {0, 0}, 0, drawCol);

    TextSize = {(float)((text.size()) * 20) , 40};

    DrawTextPro(TextFont, text.c_str(), {startPos.x, startPos.y}, {TextSize.x / 2, TextSize.y / 2},0, fontSize, 3, BLACK);
}
