
int analogPinLeft = A0;
int analogPinRight = A1;
int left = 0;
int right = 0;

void setup() {
   Serial.begin(9600);
   pinMode(analogPinLeft,INPUT);
   pinMode(analogPinRight, INPUT);

}

void loop() {
  left = analogRead(analogPinLeft);  // read the input pin
  Serial.println(left);
  right = analogRead(analogPinRight);
  Serial.println(right);
}
