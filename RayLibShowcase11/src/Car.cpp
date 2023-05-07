//
// Created by smovzhta on 05.05.2023.
//

#include "Car.h"

Car::Car(Vector2 pos): GameObject(pos, {50, 100}, "Car", RED) {
    carTexture = LoadTexture("../resources/texture/cars/car green.png");
    carSource = {0, 0, (float)carTexture.width, (float)carTexture.height};
    carOrigin = {scale.x / 2, (float)axis};

    wheelLeft = wheelScale.x / 2 - scale.x / 2;
    wheelRight = wheelScale.x / 2 + scale.x / 2;
    wheelUp = wheelScale.y / 2 - wheelDistance + axis;
    wheelDown = wheelScale.y / 2 + wheelDistance - (scale.y - axis);
}

void Car::gas(float speeds) {
    rotation += wheelAngle;
    phisRotation -= wheelAngle;

    cpBodySetAngle(*myBody, (phisRotation + 180) / 180.0 * PI);

    float currentSpeed;

    if(speeds < 0)
        currentSpeed = speeds + 2;
    else
        currentSpeed = speeds;

    Vector2 veloc = degreesToVector(currentSpeed, rotation);
    myBody->setVelocity(cp::Vect(veloc.x, veloc.y));
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

    cp::Vect savePos = cpBodyGetPosition(*myBody);

    position = {(float)savePos.x, -(float)savePos.y};

    Rectangle wheelRect = {position.x, position.y, wheelScale.x, wheelScale.y};

    DrawRectanglePro(wheelRect, {wheelLeft, wheelUp}, rotation + wheelAngle, wheelColor);
    DrawRectanglePro(wheelRect, {wheelRight, wheelUp}, rotation + wheelAngle, wheelColor);
    DrawRectanglePro(wheelRect, {wheelLeft, wheelDown}, rotation, wheelColor);
    DrawRectanglePro(wheelRect, {wheelRight, wheelDown}, rotation, wheelColor);

    DrawRectanglePro({position.x, position.y, scale.x, scale.y}, carOrigin, rotation, color);
    DrawTextPro(Font(), "95", position, {scale.x / 2 - 7,scale.y / 2}, rotation, 30, 3, YELLOW);
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
}
