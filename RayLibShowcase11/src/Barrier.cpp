//
// Created by tikho on 05.05.2023.
//

#include "Barrier.h"

Barrier::Barrier(Vector2 pos): GameObject({pos.x, pos.y}, {300, 300}, "Barrier", BROWN) {}

void Barrier::Shape(cp::Space *mSpace) {
    myBody = mSpace->staticBody;

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                              std::vector<cp::Vect>{
                                                      cp::Vect(position.x, -position.y - scale.y),
                                                      cp::Vect(position.x + scale.x, -position.y - scale.y),
                                                      cp::Vect(position.x + scale.x, -position.y),
                                                      cp::Vect(position.x, -position.y),
                                              });

    mSpace->add(myShape);
}

void Barrier::draw() {
    DrawRectangleV(position, scale, color);
}