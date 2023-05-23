//
// Created by fools on 8/7/2021.
//

#include "World.h"

World::World(int num, int *flagChoose): Scene(num) {
    level = new std::vector<GameObject*>;

    this->flagChoose = flagChoose;
    PhisThread = new std::thread([&](){
        while(isWork) {
            if(isLoad && !isPause) {
                for (int i = 0; i < level->size() - 1; i++) {
                    if (isLoad && !isPause && level->at(i)->myShape != nullptr) {
                        for (int j = i + 1; j < level->size(); j++) {
                            if (isLoad && !isPause && level->at(j)->myShape != nullptr &&
                                std::abs(level->at(i)->position.x - level->at(j)->position.x) +
                                std::abs(level->at(i)->position.y - level->at(j)->position.y) <
                                distanceTouch) {
                                auto points = cpShapesCollide(*(level->at(j)->myShape),
                                                          *(level->at(i)->myShape));

                                if (isLoad && !isPause && points.count > 0) {
                                    int saveSize = level->size();

                                    level->at(i)->Touch(level->at(j), points);

                                    if (isLoad && !isPause && saveSize == level->size())
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
    if(!isPause) {
        frameCount++;
        frameCount %= UINT64_MAX;

        mSpace->step(1.0 / 60.0);

        for (int i = 0; i < level->size(); i++)
            level->at(i)->update();
    }

    for(int i = 0; i < level->size(); i++)
        level->at(i)->draw();

    if(IsKeyPressed(KEY_ESCAPE))
        isPause = !isPause;
}

void World::updateInterface() {
    for(int i = 0; i < level->size(); i++)
        level->at(i)->drawInterface(camera->target);

    if(isPause) {
        DrawRectangle(0, 0, screen->x, screen->y, {0, 0, 0, 90});
      

    
     if(isPause) {
        DrawRectangle(0, 0, screen->x, screen->y, {0, 0, 0, 110});
        DrawTextEx(TextFont, "Pause",{screen->x / 2 - 90, screen->y / 2 - 250}, 65, 3, BLACK);

        startButton->update();
        restartButton->update();
        BackButton->update();

        if(startButton->isTouch)
            isPause = false;

        if(restartButton->isTouch) {
            sceneManager->LoadScene(number);
            return;
        }

        if(BackButton->isTouch)
        {
            sceneManager->LoadScene(0);
            return;
        }
    }
    else
    {
        for(int i = 0; i < CarLevel.size(); i++){
          if((int)(worldGenerator->road.size()/40) <= CarLevel[i]->passedCircle){
            if(i = 0)   
              DrawText("You win, lol!", camera->target.x, camera->target.y, 100, BLACK);
     }
    }
      }
}

void World::Load() {
    isPause = false;

    mSpace = new cp::Space();
    mSpace->setGravity(cp::Vect(0, 0));

    worldGenerator = new WorldGenerator();

    startButton = new Button({screen->x / 2, screen->y / 2 + 50, 200, 100}, "continue", TextFont);
    restartButton = new Button({screen->x / 2 - 250, screen->y / 2 + 50, 200, 100}, "restart", TextFont);
    BackButton = new Button({screen->x / 2 + 250, screen->y / 2 + 50, 200, 100}, "menu", TextFont);

    LoadLevel(worldGenerator->full_generate());

    SpawnObject(new PlayerCar(*worldGenerator->road.at(worldGenerator->road.size() - 1), &worldGenerator->road, *flagChoose));
    SpawnObject(new BotCar(*worldGenerator->road.at(0), &worldGenerator->road, *flagChoose));

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

    while (level->size() != 0) {
        DeleteObject(level->at(0));
        level->erase(level->begin());
    }

    delete startButton;
    delete restartButton;
    delete BackButton;
    delete mSpace;
    delete worldGenerator;
}

World::~World() {
    isWork = false;
}