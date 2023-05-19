//
// Created by kachalovkyu on 19.05.2023.
//

#include "Tree.h"

Tree::Tree(Vector2 pos): GameObject({pos.x, pos.y}, {300, 300}, "Tree", BROWN) {
    static Texture2D texture = LoadTexture("../resources/texture/tree/tree.png");
    texture2D = texture;
}

void Tree::Shape(cp::Space *mSpace) {
    myBody = mSpace->staticBody;

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                              std::vector<cp::Vect>{
                                                      cp::Vect(position.x, -position.y - scale.y),
                                                      cp::Vect(position.x + scale.x, -position.y - scale.y),
                                                      cp::Vect(position.x + scale.x, -position.y),
                                                      cp::Vect(position.x, -position.y),
                                              });
//    myShape->setFriction(1);
//
//    myBody->setPosition(cp::Vect(position.x, position.y));
//
//    mSpace->add(myBody);
    mSpace->add(myShape);
}

void Tree::draw() {
    DrawTexturePro(texture2D, {0, 0, texture2D.width, texture2D.height}, {position.x, position.y, scale.x, scale.y}, {0, 0}, 0, WHITE);
}