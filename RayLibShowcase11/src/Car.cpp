//
// Created by smovzhta on 05.05.2023.
//

#include "Car.h"
#include "World.h"

Car::Car(Vector2 pos, Vector2 scale, float wheelRotSpeed, int wheelDistance, float overclocking, int axis, int deepening, std::vector<GameObject *> *check): GameObject(pos, scale, "Car", WHITE) {
    wheelLeft = wheelScale.x / 2 - scale.x / 2 + deepening;
    wheelRight = wheelScale.x / 2 + scale.x / 2 - deepening;
    wheelUp = wheelScale.y / 2 - wheelDistance + axis;
    wheelDown = wheelScale.y / 2 + wheelDistance - (scale.y - axis);

    this->wheelRotSpeed = wheelRotSpeed;
    this->overclocking = overclocking;
    this->axis = axis;

    for(int i = 0; i < check->size(); i++)
        checkpoints.push_back(check->at(i));

    carOrigin = {scale.x / 2, (float)axis};

    rotation = -(std::atan2(position.x - checkpoints.at(0)->position.x - 125, position.y - checkpoints.at(0)->position.y - 125) * 180 / PI);
}

void Car::settings(Texture2D *texture) {
    carTexture = texture;

    carSource = {0,0, (float)carTexture->width, (float)carTexture->height};
}

void Car::drawCar() {
    Rectangle wheelRect = {position.x, position.y, wheelScale.x, wheelScale.y};

    DrawRectanglePro(wheelRect, {wheelLeft, wheelUp}, rotation + wheelAngle, wheelColor);
    DrawRectanglePro(wheelRect, {wheelRight, wheelUp}, rotation + wheelAngle, wheelColor);
    DrawRectanglePro(wheelRect, {wheelLeft, wheelDown}, rotation, wheelColor);
    DrawRectanglePro(wheelRect, {wheelRight, wheelDown}, rotation, wheelColor);

    DrawTexturePro(*carTexture, carSource, {position.x, position.y, scale.x, scale.y}, carOrigin, rotation, color);
}

void Car::gas(float speedes) {
    isGas = true;

    float speeds = speedes;

    if(isAsphaltTouch)
        speeds *= 1.6;

    float wheelRotation = wheelAngle * (speed / speeds) * sign(speed);

    rotation += wheelRotation;

    cpBodySetAngle(*myBody, (-rotation + 180) / 180.0 * PI);

    float currentSpeed;

    if(speeds < 0)
        currentSpeed = speeds + 2;
    else
        currentSpeed = speeds;

    if(signbit(speed) != signbit(speeds))
        speed = 0;

    if(speed != currentSpeed) {
        if (speed > currentSpeed)
            speed -= overclocking;
        else
            speed += overclocking;
    }

    Vector2 velocity = degreesToVector(speed, rotation);

    myBody->setVelocity(cp::Vect(velocity.x, velocity.y));
}

void Car::Rotation(int rot){
    float differenceRot = rot - wheelAngle;

    if(differenceRot == 0)
        return;

    if(differenceRot < 0) {
        wheelAngle -= wheelRotSpeed;
        return;
    }

    wheelAngle += wheelRotSpeed;
}

void Car::updateCar() {
    if(!isGas) {
        speed *= 0.9;
        cp::Vect saveVelocity = myBody->getVelocity();

        myBody->setVelocity(cp::Vect(saveVelocity.x * (1.0 - overclocking), saveVelocity.y * (1.0 - overclocking)));
    }

    Vector2 leg {checkpoints.at(currentCheckpoint)->position.x + 150 - position.x,
                 checkpoints.at(currentCheckpoint)->position.y + 150 - position.y};

    if(leg.x * leg.x + leg.y * leg.y < checkDist * checkDist) {
        currentCheckpoint ++;
        currentCheckpoint %= checkpoints.size();
    }

    cp::Vect savePos = cpBodyGetPosition(*myBody);

    position = {(float)savePos.x, -(float)savePos.y};

    isGas = false;
    isAsphaltTouch = false;
}

void Car::Shape(cp::Space *mSpace) {
    myBody = std::make_shared<cp::Body>(4, INFINITY);

    myShape = std::make_shared<cp::PolyShape>(myBody,
                                              std::vector<cp::Vect>{
                                                      cp::Vect(-scale.x / 2 , -axis),
                                                      cp::Vect(scale.x / 2, -axis),
                                                      cp::Vect(scale.x / 2, scale.y - axis),
                                                      cp::Vect(-scale.x / 2, scale.y - axis),
                                              });

    myShape->setFriction(1);

    myBody->setPosition(cp::Vect(position.x, -position.y));

    mSpace->add(myBody);
    mSpace->add(myShape);

    myBody->setVelocity(cpvzero);
    cpBodySetAngle(*myBody, (-rotation + 180) / 180.0 * PI);
}

void Car::Touch(GameObject *object, cpContactPointSet points) {
    if(object->name == "Asphalt")
        isAsphaltTouch = true;
}

void Car::draw() {drawCar();}
void Car::update() {updateCar();}