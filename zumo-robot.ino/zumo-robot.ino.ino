/*
Drive forward and turn left or right when border is detected
  - Only reflectionsensor 0 and 5 are used.
*/
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
 
#define LED 13
 
// this might need to be tuned for different lighting conditions, surfaces, etc.
#define QTR_THRESHOLD  1800 // 
  
// these might need to be tuned for different motor types
#define REVERSE_SPEED     200 // 0 is stopped, 400 is full speed
#define TURN_SPEED        200
#define FORWARD_SPEED     400
#define REVERSE_DURATION  200 // ms
#define TURN_DURATION     300 // ms
 
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
boolean done = false;
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
 
ZumoReflectanceSensorArray sensors;
int numbTurns = 4;

 
void setup()
{
   sensors.init();
   button.waitForButton();
}

boolean borderDetected(){
  if (sensor_values[0]  > QTR_THRESHOLD || sensor_values[1]  > QTR_THRESHOLD || sensor_values[2]  > QTR_THRESHOLD || sensor_values[3]  > QTR_THRESHOLD || sensor_values[4]  > QTR_THRESHOLD
  ||sensor_values[5]  > QTR_THRESHOLD)
  {
    return true;
  }
  return false;
}

void turn(int degrees){
  int x90 = (240);
  motors.setSpeeds(350,-350);
  delay(x90);
  motors.setSpeeds(0,0);
}

void loop()
{
  if (numbTurns > 0) {
    turn(180);
    delay(50);
    numbTurns --;
  }
  
  
  
  /*
  sensors.read(sensor_values);
  
if  (!done){
  if (borderDetected())
  {
    // if leftmost sensor detects line, reverse and turn to the right
    motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
    delay(200);
    motors.setSpeeds(0, 0);
    done = true;
  }
  else
  {
    // otherwise, go straight
    motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
  }
}*/
}
