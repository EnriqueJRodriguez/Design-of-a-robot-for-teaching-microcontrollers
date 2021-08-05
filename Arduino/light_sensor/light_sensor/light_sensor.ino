/*
 * Program for the luxometre BH1750 uses BH170 library. ADDR pin no needed as library works on the 0x_23 address by default 
 */

#include <BH1750.h>

BH1750 luxometer;

// BH1750::CONTINUOUS_HIGH_RES_MODE
// BH1750::CONTINUOUS_HIGH_RES_MODE_2
// BH1750::CONTINUOUS_LOW_RES_MODE
// BH1750::ONE_TIME_HIGH_RES_MODE
// BH1750::ONE_TIME_HIGH_RES_MODE_2
// BH1750::ONE_TIME_LOW_RES_MODE

void setup() {
   Serial.begin(9600);
   Serial.println("Initializing sensor...");
   luxometer.begin(BH1750::CONTINUOUS_HIGH_RES_MODE); // Initializing BH1750
}
void loop() {
   uint16_t lux = luxometer.readLightLevel(); // Read of BH1750
   Serial.print("Light level:  ");
   Serial.print(lux);
   Serial.println(" lx");
   delay(500);
}
