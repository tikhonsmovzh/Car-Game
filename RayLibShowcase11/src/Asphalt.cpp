//
// Created by tikho on 08.05.2023.
//

#include "Asphalt.h"

Asphalt::Asphalt(Vector2 pos, Texture2D *texture): GameObject({pos.x, pos.y}, {300, 300}, "Asphalt", GRAY) {
    texture2D = texture;
}

void Asphalt::Shape(cp::Space *mSpace) {
    myBody = std::make_shared<cp::Body>(0.01, 0.01);

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                              std::vector<cp::Vect>{
                                                      cp::Vect(position.x, -position.y - scale.y),
                                                      cp::Vect(position.x + scale.x, -position.y - scale.y),
                                                      cp::Vect(position.x + scale.x, -position.y),
                                                      cp::Vect(position.x, -position.y),
                                              });

    mSpace->add(myShape);
}

void Asphalt::draw() {
    if(texture2D == nullptr)
        DrawRectangleV(position, scale, color);
    else
        DrawTexturePro(*texture2D, {0, 0, scale.x, scale.y}, {position.x, position.y, scale.x, scale.y}, {0,0}, 0, WHITE);
}