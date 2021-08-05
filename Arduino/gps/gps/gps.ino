#include <SoftwareSerial.h> // Own software serial port
#include <TinyGPS.h> // Library to handle the data provided

TinyGPS gps; 
SoftwareSerial serialgps(11,12);

char data= ' '; // Read from module

void setup() {
  Serial.begin(115200); // Microcontroller serial port 
  serialgps.begin(9600); // Serial module port

}

void loop() {
  if(serialgps.available()){ // Check data available
    data = serialgps.read(); // Obtain the data
    Serial.print(data); // Display data to the serial console
    if(gps.encode(data)){ // Librrty interprets data
      // Calls to tiny GPS libary
    }
    delay(100);
  }
}
