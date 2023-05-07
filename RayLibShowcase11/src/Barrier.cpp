//
// Created by tikho on 05.05.2023.
//

#include "Barrier.h"

Barrier::Barrier(Vector2 pos): GameObject({pos.x, -pos.y}, {50, 150}, "Barrier", BROWN) {}

void Barrier::Shape(cp::Space *mSpace) {
    myBody = std::make_shared<cp::Body>(4, INFINITY);

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                              std::vector<cp::Vect>{
                                                      cp::Vect(-scale.x / 2, -scale.y / 2),
                                                      cp::Vect(scale.x / 2, -scale.y / 2),
                                                      cp::Vect(scale.x / 2, scale.y / 2),
                                                      cp::Vect(-scale.x / 2, scale.y / 2),
                                              });

    myShape->setFriction(1);

    myBody->setPosition(cp::Vect(position.x, position.y));

    mSpace->add(myBody);
    mSpace->add(myShape);
}

void Barrier::draw() {
    cp::Vect saveVelocity = myBody->getVelocity();

    myBody->setVelocity(cp::Vect(saveVelocity.x * 0.9, saveVelocity.y * 0.9));

    position = {(float)cpBodyGetPosition(*myBody).x, -(float)cpBodyGetPosition(*myBody).y};

    DrawRectanglePro({position.x, position.y, (float)scale.x, (float)scale.y},
                     {(float)scale.x / 2, (float)scale.y / 2}, -cpBodyGetAngle(*myBody) / 2 / PI * 360, color);
}