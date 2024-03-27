#include "Wheels2.h"

#define SET_MOVEMENT(side, f, b) \
    digitalWrite(side[0], f); \
    digitalWrite(side[1], b)

Wheels::Wheels(
    /* NO ARGUMENTS */
) {

}

void doBeep(
    /* NO ARGUMENTS */
) {
    digitalWrite(BEEPER, digitalRead(BEEPER) ^ 1);
}

void Wheels::attachRight(
    int pF,
    int pB,
    int pS
) {
    pinMode(pF, OUTPUT);
    pinMode(pB, OUTPUT);
    pinMode(pS, OUTPUT);

    this->pinsRight[0] = pF;
    this->pinsRight[1] = pB;
    this->pinsRight[2] = pS;
}

void Wheels::attachLeft(
    int pF,
    int pB,
    int pS
) {
    pinMode(pF, OUTPUT);
    pinMode(pB, OUTPUT);
    pinMode(pS, OUTPUT);

    this->pinsLeft[0] = pF;
    this->pinsLeft[1] = pB;
    this->pinsLeft[2] = pS;
}

void Wheels::setSpeedRight(
    uint8_t speed
) {
    this->speedR = speed;
    analogWrite(this->pinsRight[2], speed);
}

void Wheels::setSpeedLeft(
    uint8_t speed
) {
    this->speedL = speed;
    analogWrite(this->pinsLeft[2], speed);
}

void Wheels::setSpeed(
    uint8_t speed
) {
    setSpeedLeft(speed);
    setSpeedRight(speed);
}

void Wheels::attach(
    int pRF, 
    int pRB, 
    int pRS, 
    int pLF, 
    int pLB, 
    int pLS
) {
    this->attachRight(pRF, pRB, pRS);
    this->attachLeft(pLF, pLB, pLS);
}

void Wheels::forwardLeft(
    /* NO ARGUMENTS */
) {
    SET_MOVEMENT(pinsLeft, HIGH, LOW);
}

void Wheels::forwardRight(
    /* NO ARGUMENTS */
) {
    SET_MOVEMENT(pinsRight, HIGH, LOW);
}

void Wheels::backLeft(
    /* NO ARGUMENTS */
) {
    SET_MOVEMENT(pinsLeft, LOW, HIGH);
}

void Wheels::backRight(
    /* NO ARGUMENTS */
) {
    SET_MOVEMENT(pinsRight, LOW, HIGH);
}

void Wheels::forward(
  /* NO ARGUMENTS */  
) {
    this->forwardLeft();
    this->forwardRight();

    Timer1.detachInterrupt();
    digitalWrite(BEEPER, 0);
}

void Wheels::back(
    /* NO ARGUMENTS */  
) {
    this->backLeft();
    this->backRight();

    int speed = (this->speedL <= this->speedR) ? this->speedL : this->speedR;

    Timer1.detachInterrupt();
    Timer1.attachInterrupt(doBeep, this->intPeriodMult * speed);
}

void Wheels::stopLeft(
    /* NO ARGUMENTS */  
) {
    SET_MOVEMENT(pinsLeft, LOW, LOW);
}

void Wheels::stopRight(
    /* NO ARGUMENTS */  
) {
    SET_MOVEMENT(pinsRight, LOW, LOW);
}

void Wheels::stop(
    /* NO ARGUMENTS */  
) {
    this->stopLeft();
    this->stopRight();

    Timer1.detachInterrupt();
    digitalWrite(BEEPER, 0);
}

void Wheels::goForward(
    int cm
) {
    int prevSpeedR = this->speedR;
    int prevSpeedL = this->speedL;

    this->setSpeed(100);
    this->forward();

    delay(33 * cm);

    this->stop();
    this->setSpeedLeft(prevSpeedL);
    this->setSpeedRight(prevSpeedR);
}

void Wheels::goBack(
    int cm
) {
    int prevSpeedR = this->speedR;
    int prevSpeedL = this->speedL;

    this->setSpeed(100);
    this->back();

    delay(33 * cm);
    
    this->stop();
    this->setSpeedLeft(prevSpeedL);
    this->setSpeedRight(prevSpeedR);
}