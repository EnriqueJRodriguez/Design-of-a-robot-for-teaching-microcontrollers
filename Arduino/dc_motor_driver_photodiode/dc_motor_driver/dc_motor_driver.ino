const int pinPWMA = 9;
const int pinPWMB = 10;
const int pinSTBY = 13;

const int pinAIN1 = 2;
const int pinAIN2 = 3;

const int pinBIN1 = 4;
const int pinBIN2 = 5;

const int left = 0;
const int right = 1;
 
const int waitTime = 2000;   //Waiting time
const int speed = 100;      //wheelspin speed
 
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
   Serial.begin(9600);
   pinMode(pinAIN2, OUTPUT);
   pinMode(pinAIN1, OUTPUT);
   pinMode(pinPWMA, OUTPUT);
   pinMode(pinBIN1, OUTPUT);
   pinMode(pinBIN2, OUTPUT);
   pinMode(pinPWMB, OUTPUT);
   pinMode(A0,INPUT);
   pinMode(A1, INPUT);
}
 
void loop()
{
   enableMotors();
 
   controlMovement();
 
   fullStop();
   delay(waitTime);
}
 
// Control robot movement functions
void controlMovement(){
  int leftRead = analogRead(A0);
  Serial.write(leftRead);
  int rightRead = analogRead(A1);
  if(leftRead > 500 && rightRead > 500){
    move(forward,100);
  }else{
    if(leftRead < 500 && rightRead < 500){
      move(backward,100); 
    }else{
      if(leftRead > rightRead){
         turn(clockwise, 100); 
      }else{
        turn(counterClockwise, 100);
      }
    }
  }
}

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
 
//Motors controls
void moveMotorForward(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], HIGH);
   digitalWrite(pinMotor[2], LOW);
 
   analogWrite(pinMotor[0], speed);
}
 
void moveMotorBackward(const int pinMotor[3], int speed)
{
   digitalWrite(pinMotor[1], LOW);
   digitalWrite(pinMotor[2], HIGH);
 
   analogWrite(pinMotor[0], speed);
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
