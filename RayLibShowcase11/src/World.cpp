//
// Created by fools on 8/7/2021.
//

#include "World.h"

//
// Created by fools on 8/7/2021.
//

#include "World.h"

World::World(int num): Scene(num) {
    level = new std::vector<GameObject*>;

    PhisThread = new std::thread([&](){
        while(isWork) {
            if(isLoad) {
                for (int i = 0; i < level->size() - 1; i++) {
                    if (isLoad && level->at(i)->myShape != nullptr) {
                        for (int j = i + 1; j < level->size(); j++) {
                            if (isLoad && level->at(j)->myShape != nullptr &&
                                std::abs(level->at(i)->position.x - level->at(j)->position.x) +
                                std::abs(level->at(i)->position.y - level->at(j)->position.y) <
                                distanceTouch) {
                                auto points = cpShapesCollide(*(level->at(j)->myShape),
                                                          *(level->at(i)->myShape));

                                if (isLoad && points.count > 0) {
                                    int saveSize = level->size();

                                    level->at(i)->Touch(level->at(j), points);

                                    if (saveSize == level->size())
                                        level->at(j)->Touch(level->at(i), points);
                                }
                            }
                        }
                    }
                }
            }
        }
    });
}

void World::update() {
    frameCount++;
    frameCount %= UINT64_MAX;

    if(GetFPS() != 0)
        mSpace->step(1.0 / GetFPS());

    for (int i = 0; i < level->size(); i++)
        level->at(i)->update();

    for(int i = 0; i < level->size(); i++)
        level->at(i)->draw();

    for(int i = 0; i < level->size(); i++)
        level->at(i)->drawInterface(camera->target);
}

void World::Load() {
    camera->target = {0, 0};

    mSpace = new cp::Space();
    mSpace->setGravity(cp::Vect(0, 0));

    worldGenerator = new WorldGenerator();

    LoadLevel(worldGenerator->full_generate());

    SpawnObject(new PlayerCar({12850, 12850}, &worldGenerator->road));

    isLoad = true;
}

GameObject* World::FindName(std::string name) {
    for(int i = 0; i < level->size(); i++)
    {
        if(level->at(i)->name == name)
            return level->at(i);
    }
}

GameObject* World::GetLetShape(std::shared_ptr<cp::Shape> Shape) {
    for(int i = 0; i < level->size(); i++)
    {
        if(level->at(i)->myShape == Shape)
            return level->at(i);
    }

    return nullptr;
}

unsigned long long World::GetFrameCount() { return frameCount;}

void World::Destroy(GameObject *obj) {
    for (int i = 0; i < level->size(); i++) {
        if(level->at(i) == obj) {
            level->erase(level->begin() + i);

            DeleteObject(obj);

            break;
        }
    }
}

void World::SpawnObject(GameObject* obj) {
    level->push_back(obj);

    obj->Shape(mSpace);
    obj->Awake(this, TextFont, camera, screen);
    obj->Start();
}

void World::DeleteObject(GameObject *obj) {
    if(obj->myBody != nullptr && obj->myBody != mSpace->staticBody && cpSpaceContainsBody(*mSpace, *(obj->myBody)))
        mSpace->remove(obj->myBody);

    if(obj->myShape != nullptr && cpSpaceContainsShape(*mSpace, *(obj->myShape)))
        mSpace->remove(obj->myShape);

    obj->destroy();

    delete obj;
}

void World::LoadLevel(std::vector<GameObject *> level1) {
    for(int i = 0; i < level1.size(); i++)
        level->push_back(level1.at(i));

    for (int i = 0; i < level1.size(); i++) {
        level1.at(i)->Shape(mSpace);
        level1.at(i)->Awake(this, TextFont, camera, screen);
        level1.at(i)->Start();
    }
}

void World::UnLoad() {
    isLoad = false;

    camera->target = {0, 0};

    while (level->size() != 0) {
        DeleteObject(level->at(0));
        level->erase(level->begin());
    }

    delete mSpace;
    delete worldGenerator;
}

World::~World() {
    isWork = false;
}