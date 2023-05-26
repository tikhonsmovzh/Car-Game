//
// Created by smovzhta on 05.05.2023.
//

#include "Car.h"
#include "World.h"

Car::Car(Vector2 pos, Vector2 scale, float wheelRotSpeed, int wheelDistance, float overclocking, int axis, int deepening, float driftSpeed, std::vector<Vector2 *> *check): GameObject(pos, scale, "Car", WHITE) {
    wheelLeft = wheelScale.x / 2 - scale.x / 2 + deepening;
    wheelRight = wheelScale.x / 2 + scale.x / 2 - deepening;
    wheelUp = wheelScale.y / 2 - wheelDistance + axis;
    wheelDown = wheelScale.y / 2 + wheelDistance - (scale.y - axis);

    this->wheelRotSpeed = wheelRotSpeed;
    this->overclocking = overclocking;
    this->axis = axis;

    this->driftSpeed = driftSpeed;

    checkpoints = check;

    carOrigin = {scale.x / 2, (float)axis};

    for(int i = 0; i < checkpoints->size(); i++){
        Vector2 leg {checkpoints->at(i)->x - position.x,
                     checkpoints->at(i)->y - position.y};

        if(leg.x * leg.x + leg.y * leg.y > checkDist * checkDist) {
            rotation = -(std::atan2(position.x - checkpoints->at(i)->x, position.y - checkpoints->at(i)->y) * 180 / PI);
            break;
        }
    }
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

    /*if(isAsphaltTouch)
        speeds *= 1.6;*/

    rotation += wheelAngle * sign(speed);

    cpBodySetAngle(*myBody, (-rotation + 180) / 180.0 * PI);

    float currentSpeed;

    if(speeds < 0)
        currentSpeed = speeds + 2;
    else
        currentSpeed = speeds;

    if(signbit(speed) != signbit(speedes))
        speed = 0;

    if(speed != currentSpeed) {
        if(std::abs(speed - currentSpeed) < overclocking)
            speed = currentSpeed;
        if (speed > currentSpeed)
            speed -= overclocking;
        else
            speed += overclocking;
    }

    if(speed > driftSpeed && std::abs(wheelAngle) > driftSensitivity) {
        if(std::abs(driftAngle) < maxDriftAngle) {
            if (driftAngle > -maxDriftAngle * sign(wheelAngle))
                driftAngle -= driftSensitivity;
            else
                driftAngle += driftSensitivity;
        }
    } else
        driftAngle = 0;

    Vector2 velocity = degreesToVector(speed, rotation + driftAngle);

    myBody->setVelocity(cp::Vect(velocity.x, velocity.y));
}

void Car::Rotation(float rot){
    float differenceRot = rot - wheelAngle;

    if(std::abs(differenceRot) < wheelRotSpeed) {
        wheelAngle = rot;
        return;
    }

    if(differenceRot < 0) {
        wheelAngle -= wheelRotSpeed;
        return;
    }

    wheelAngle += wheelRotSpeed;
}

void Car::updateCar() {
    if(!isGas) {
        speed *= 1.0 - overclocking;
        cp::Vect saveVelocity = myBody->getVelocity();

        myBody->setVelocity(cp::Vect(saveVelocity.x * (1.0 - overclocking), saveVelocity.y * (1.0 - overclocking)));
    }

    Vector2 leg {checkpoints->at(currentCheckpoint)->x - position.x,
                 checkpoints->at(currentCheckpoint)->y - position.y};

    if(leg.x * leg.x + leg.y * leg.y < checkDist * checkDist) {
        currentCheckpoint++;

        if(currentCheckpoint >= checkpoints->size()){
            passedCircle++;

            currentCheckpoint = 0;
        }
    }

    cp::Vect savePos = cpBodyGetPosition(*myBody);

    position = {(float)savePos.x, -(float)savePos.y};

    isGas = false;
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

/*void Car::Touch(GameObject *object, cpContactPointSet points) {
    if(object->name == "Asphalt") {
        isAsphaltTouch = true;
    }
}*/

void Car::draw() {drawCar();}
void Car::update() {updateCar();}

float Car::GetSpeed() {return speed;}