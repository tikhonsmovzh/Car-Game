//
// Created by smovzhta on 05.05.2023.
//

#include "Car.h"
#include "World.h"

Car::Car(Vector2 pos, Vector2 scale, float wheelRotSpeed, int wheelDistance, float overclocking, int axis, int deepening): GameObject(pos, scale, "Car", WHITE) {
    wheelLeft = wheelScale.x / 2 - scale.x / 2 + deepening;
    wheelRight = wheelScale.x / 2 + scale.x / 2 - deepening;
    wheelUp = wheelScale.y / 2 - wheelDistance + axis;
    wheelDown = wheelScale.y / 2 + wheelDistance - (scale.y - axis);

    this->wheelRotSpeed = wheelRotSpeed;
    this->overclocking = overclocking;
    this->axis = axis;

    carOrigin = {scale.x / 2, (float)axis};
}

void Car::settings(Texture2D *texture) {
    carTexture = texture;

    carSource = {0,0, (float)carTexture->width, (float)carTexture->height};
}

void Car::gas(float speedes) {
    isGas = true;

    float speeds = speedes;

    if(isAsphaltTouch)
        speeds *= 1.6;

    float wheelRotation = wheelAngle * (speed / speeds) * sign(speed);

    rotation += wheelRotation;
    phisRotation -= wheelRotation;

    cpBodySetAngle(*myBody, (phisRotation + 180) / 180.0 * PI);

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
    int differenceRot = rot - wheelAngle;

    if(differenceRot == 0)
        return;

    if(differenceRot < 0) {
        wheelAngle -= wheelRotSpeed;
        return;
    }

    wheelAngle += wheelRotSpeed;
}

void Car::updateCar() {
    cp::Vect saveVelocity = myBody->getVelocity();

    myBody->setVelocity(cp::Vect(saveVelocity.x * 0.9, saveVelocity.y * 0.9));

    if(!isGas)
        speed *= 0.9;

    cp::Vect savePos = cpBodyGetPosition(*myBody);

    position = {(float)savePos.x, -(float)savePos.y};

    Rectangle wheelRect = {position.x, position.y, wheelScale.x, wheelScale.y};

    DrawRectanglePro(wheelRect, {wheelLeft, wheelUp}, rotation + wheelAngle, wheelColor);
    DrawRectanglePro(wheelRect, {wheelRight, wheelUp}, rotation + wheelAngle, wheelColor);
    DrawRectanglePro(wheelRect, {wheelLeft, wheelDown}, rotation, wheelColor);
    DrawRectanglePro(wheelRect, {wheelRight, wheelDown}, rotation, wheelColor);

    DrawTexturePro(*carTexture, carSource, {position.x, position.y, scale.x, scale.y}, carOrigin, rotation, color);

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
}

void Car::Touch(GameObject *object, cpContactPointSet points) {
    if(object->name == "Asphalt")
        isAsphaltTouch = true;
}