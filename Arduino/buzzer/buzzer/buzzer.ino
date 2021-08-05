/*
 * Buzzer
 */
 /*
  * Small program that allows you to make the buzzer sound every 3 seconds
  */
int buzzer = 7; // Arduino pin
void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(3000);
}
