//
// Created by tikho on 01.05.2023.
//

#include "Scene.h"

Scene::Scene(int number) {
    this->number = number;
}

void Scene::Start(SceneManager *manager, Font font, Vector2 *screen) {
    sceneManager = manager;
    TextFont = font;
    this->screen = screen;
}