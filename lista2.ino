#include "Wheels.h"

Wheels w;

void setup(
    /* NO ARGUMENTS */    
) {
  delay(2000);
  w.attach(8,7,6,5,4,3); //green, blue, yellow, grey, purple, white

  pinMode(BEEPER, OUTPUT);
  Timer1.initialize();

  Serial.begin(9600);
  w.setSpeed(150);
}

void loop(
    /* NO ARGUMENTS */    
) {
  w.goForward(10);
  w.goBack(10);
}