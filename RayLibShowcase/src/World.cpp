//
// Created by fools on 8/7/2021.
//

#include "World.h"
#include <iostream>
#include <memory>

World::World(int num): Scene(num) {

}

void World::update() {

}

Vector2 World::physicsToWorldCoord(float x, float y) {
    return {x, -y};
}

void World::Load() {

}

void World::UnLoad() {

}