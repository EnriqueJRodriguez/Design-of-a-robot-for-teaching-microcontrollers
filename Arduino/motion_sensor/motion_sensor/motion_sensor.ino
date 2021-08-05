/* HC-SR501 PIR 
   Sensitivity in this sensor is quite high, it can detect movement in a range between 
   7-3m dependeing on adjustments (in this sensor that option is not possible)
 */

/*
 * This example program allows you to detect movmeent in intervals of 1 second
 */
// Define connection pins:
#define pirPin 7
// Create variables:
int val = 0;
void setup() {
  // Configure the pins as input or output:
  pinMode(pirPin, INPUT);
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
}
void loop() {
  // Read out the pirPin and store as val:
  val = digitalRead(pirPin);
  // If motion is detected (pirPin = HIGH), do the following:
  if (val == HIGH) {
      Serial.println("Motion detected!");
      delay(1000);
    }
  // If no motion is detected (pirPin = LOW), do the following:
  else {
      Serial.println("Motion ended!");
      delay(1000);
    }
}
