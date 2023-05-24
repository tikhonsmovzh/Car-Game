//
// Created by kachalovkyu on 16.05.2023.
//

#include "Grass.h"

Grass::Grass(Vector2 pos): GameObject({pos.x, pos.y}, {300, 300}, "Grass", DARKGREEN) {
    static Texture2D texture = LoadTexture("../resources/texture/grass/grass.png");
    texture2D = texture;
}

void Grass::draw() {
    DrawTexturePro(texture2D, {0, 0, texture2D.width, texture2D.height}, {position.x, position.y, scale.x, scale.y}, {0, 0}, 0, WHITE);
}