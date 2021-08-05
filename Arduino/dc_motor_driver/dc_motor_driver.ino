#include <SoftwareSerial.h>
#define DEBUG 1
#define SECURE_BAND 10

const int pinPWMA = 9;
const int pinPWMB = 10;
const int pinSTBY = 13;

const int pinAIN1 = 2;
const int pinAIN2 = 3;

const int pinBIN1 = 4;
const int pinBIN2 = 5;

 
const int waitTime = 2000;   // waiting time
const int speedConfigured = 600;   // speed control
 
const int pinMotorA[3] = { pinPWMA, pinAIN2, pinAIN1 };
const int pinMotorB[3] = { pinPWMB, pinBIN1, pinBIN2 };
 
enum moveDirection {
   forward,
   backward
};
 
enum turnDirection {
   clockwise,
   counterClockwise
};


void setup()
{
   pinMode(pinAIN2, OUTPUT);
   pinMode(pinAIN1, OUTPUT);
   pinMode(pinPWMA, OUTPUT);
   pinMode(pinBIN1, OUTPUT);
   pinMode(pinBIN2, OUTPUT);
   pinMode(pinPWMB, OUTPUT);   
}
 
void loop()
{
   enableMotors();
   digitalWrite(pinMotorA[1], HIGH);
   digitalWrite(pinMotorA[2], LOW);
   analogWrite(pinMotorA[0], 300);
   digitalWrite(pinMotorB[1], HIGH);
   digitalWrite(pinMotorB[2], LOW);
   analogWrite(pinMotorB[0], 300);
   delay(50000);
   
   digitalWrite(pinMotorA[1], HIGH);
   digitalWrite(pinMotorA[2], LOW);
   analogWrite(pinMotorA[0], 300);
   digitalWrite(pinMotorB[1], LOW);
   digitalWrite(pinMotorB[2], HIGH);
   analogWrite(pinMotorB[0], 500);
   delay(3000);
   
   digitalWrite(pinMotorA[1], LOW);
   digitalWrite(pinMotorA[2], HIGH);
   analogWrite(pinMotorA[0], 300);
   digitalWrite(pinMotorB[1], LOW);
   digitalWrite(pinMotorB[2], HIGH);
   analogWrite(pinMotorB[0], 300);
   delay(6000);


   digitalWrite(pinMotorA[1], LOW);
   digitalWrite(pinMotorA[2], HIGH);
   analogWrite(pinMotorA[0], 500);
   digitalWrite(pinMotorB[1], HIGH);
   digitalWrite(pinMotorB[2], LOW);
   analogWrite(pinMotorB[0], 300);
   delay(3000);
   
   digitalWrite(pinMotorA[1], HIGH);
   digitalWrite(pinMotorA[2], LOW);
   analogWrite(pinMotorA[0], 300);
   digitalWrite(pinMotorB[1], HIGH);
   digitalWrite(pinMotorB[2], LOW);
   analogWrite(pinMotorB[0], 300);
   delay(4000);
   
   
   digitalWrite(pinMotorA[1], HIGH);
   digitalWrite(pinMotorA[2], LOW);
   analogWrite(pinMotorA[0], 300);
   digitalWrite(pinMotorB[1], HIGH);
   digitalWrite(pinMotorB[2], LOW);
   analogWrite(pinMotorB[0], 300);
   delay(1000);

   digitalWrite(pinMotorA[1], LOW);
   digitalWrite(pinMotorA[2], HIGH);
   analogWrite(pinMotorA[0], 300);
   digitalWrite(pinMotorB[1], LOW);
   digitalWrite(pinMotorB[2], HIGH);
   analogWrite(pinMotorB[0], 300);
   delay(8000);

   digitalWrite(pinMotorA[1], HIGH);
   digitalWrite(pinMotorA[2], LOW);
   analogWrite(pinMotorA[0], 300);
   digitalWrite(pinMotorB[1], HIGH);
   digitalWrite(pinMotorB[2], LOW);
   analogWrite(pinMotorB[0], 300);
   delay(1000);
     
}
 
//Control movement functions for the robot
void move(int direction, int speed)
{
   if (direction == forward)
   {
      moveMotorForward(pinMotorA, speed);
      moveMotorForward(pinMotorB, speed);
   }
   else
   {
      moveMotorBackward(pinMotorA, speed);
      moveMotorBackward(pinMotorB, speed);
   }
}
 
void turn(int direction, int speed)
{
   if (direction == forward)
   {
      moveMotorForward(pinMotorA, speed);
      moveMotorBackward(pinMotorB, speed);
   }
   else
   {
      moveMotorBackward(pinMotorA, speed);
      moveMotorForward(pinMotorB, speed);
   }
}
 
void fullStop()
{
   disableMotors();
   stopMotor(pinMotorA);
   stopMotor(pinMotorB);
}
 
//Motor controls
void moveMotorForward(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], HIGH);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], speed);
   delay(4000);
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], 0);
   
}
 
void moveMotorBackward(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], HIGH);
 
   analogWrite(pinMotor[0], speed);
   delay(4000);
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], 0);
}
 
void stopMotor(const int pinMotor[3])
{
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], 0);
}
 
void enableMotors()
{
   digitalWrite(pinSTBY, HIGH);
}
 
void disableMotors()
{
   digitalWrite(pinSTBY, LOW);
}
