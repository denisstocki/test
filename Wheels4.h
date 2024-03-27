#include <Arduino.h>
#include "TimerOne.h"

#ifndef Wheels4_h
#define Wheels4_h

#define BEEPER 13

class Wheels {

    private:
        int pinsRight[3];
        int pinsLeft[3];

    public:
        Wheels();

        void attach(int pinRightForward, int pinRightBack, int pinRightSpeed,
                    int pinLeftForward, int pinLeftBack, int pinLeftSpeed);
        void forward();
        void back();
        void stop();
        void setSpeed(uint8_t);

        void attachRight(int pinForward, int pinBack, int pinSpeed);
        void forwardRight();
        void backRight();
        void stopRight();
        void setSpeedRight(uint8_t);

        void attachLeft(int pinForward, int pinBack, int pinSpeed);
        void forwardLeft();
        void backLeft();
        void stopLeft();
        void setSpeedLeft(uint8_t);

        void goForward(int cm);
        void goBack(int cm);

        volatile int cnt0, cnt1;
};

#endif