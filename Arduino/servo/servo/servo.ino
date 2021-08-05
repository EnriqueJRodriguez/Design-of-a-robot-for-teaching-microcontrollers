#include <Servo.h>
/*
 * Program to test the servo of the sg90
 * used libary
 * 
 * Brown wire = GND
 * Red Wire = +5V
 * Yellow = Control
 */

int angle = 10;

Servo servo; // Object of the servo library

void setup() {
  servo.attach(6); // Attach to D6
  servo.write(angle); // Center the servo
}

void loop() {
  // scan from 0 to 180 degrees
  for(angle = 10; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 10; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 

}
