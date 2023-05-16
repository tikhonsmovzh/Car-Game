//
// Created by tikho on 08.05.2023.
//

#include "Asphalt.h"

Asphalt::Asphalt(Vector2 pos): GameObject({pos.x, pos.y}, {300, 300}, "Asphalt", GRAY) {}

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
    DrawRectangleV(position, scale, color);

    color = GRAY;
}

void Asphalt::Touch(GameObject *obj, cpContactPointSet) {
    if(obj->name == "Car")color = GREEN;
}