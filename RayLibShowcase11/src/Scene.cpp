//
// Created by tikho on 03.05.2023.
//

#include "Scene.h"

Scene::Scene(int number) {
    this->number = number;
}

void Scene::Start(SceneManager *manager, Font *font, Vector2 *screen, Camera2D *camera) {
    sceneManager = manager;
    TextFont = font;
    this->screen = screen;
    this->camera = camera;
}