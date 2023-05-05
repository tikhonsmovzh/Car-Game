//
// Created by smovzhta on 05.05.2023.
//

#include "Car.h"

Car::Car(Vector2 pos): GameObject(pos, {50, 100}, "Car", RED) {
    carRect = {pos.x - scale.x / 2, pos.y - scale.y / 2, scale.x, scale.y};
}

void Car::draw() {
    if(IsKeyDown(KEY_W))
        gas(speed);
    else if(IsKeyDown(KEY_S))
        gas(-speed);

    if(IsKeyDown(KEY_A))
        rotation(-wheel);
    else if(IsKeyDown((KEY_D)))
        rotation(wheel);
    else
        rotation(0);

    updateCar();
}

void Car::gas(float speeds) {
    rot += wheelAngle;

    if(speeds < 0) {
        currentSpeed = speeds + 0.05;
        return;
    }

    currentSpeed = speeds;
}

void Car::rotation(int rot){
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
    Vector2 push = degreesToVector(currentSpeed, rot);

    carRect.x += push.x;
    carRect.y -= push.y;

    if(std::abs(currentSpeed) < 0.005)
        currentSpeed = 0;
    else if(currentSpeed > 0)
        currentSpeed -= 0.005;
    else if(currentSpeed < 0)
        currentSpeed += 0.005;
    else
        currentSpeed = 0;

    Rectangle wheelRect = {carRect.x, carRect.y, wheelScale.x, wheelScale.y};

    float left = wheelScale.x / 2 - carRect.width / 2, right = wheelScale.x / 2 + carRect.width / 2,
            up = wheelScale.y / 2 - wheelDistance + axis, down = wheelScale.y / 2 + wheelDistance - (scale.y - axis);

    DrawRectanglePro(wheelRect, {left, up}, rot + wheelAngle, wheelColor);
    DrawRectanglePro(wheelRect, {right, up}, rot + wheelAngle, wheelColor);
    DrawRectanglePro(wheelRect, {left, down}, rot, wheelColor);
    DrawRectanglePro(wheelRect, {right, down}, rot, wheelColor);

    DrawRectanglePro(carRect, {carRect.width / 2, (float)axis}, rot, color);

    DrawTextPro(Font(), "95", {carRect.x, carRect.y}, {carRect.width / 2 - 8, carRect.height / 2 - 8}, rot, 30, 3, YELLOW);
}