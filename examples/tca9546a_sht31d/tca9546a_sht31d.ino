/*

This is example for four ClosedCube SHT31-D sensors boards connect to ClosedCube TCA9546A I2C Multiplexer

Initial Date: 30-Jan-2017

Hardware connections for Arduino Uno and ClosedCube TCA9546A boards
	VDD to 3.3V DC
	SDA to A4
	SCL to A5
	GND to common ground

Hardware connections for ClosedCube SHT31-D and ClosedCube TCA9546A boards
  TCA9546A        SHT31-D 
  SC0/SD0         SCL/SDA (sensor 1)
  SC1/SD1         SCL/SDA (sensor 2)
  SC2/SD2         SCL/SDA (sensor 3)
  SC3/SD3         SCL/SDA (sensor 4)

  for each SHT31-D board connect to 3.3V DC and GND

  
MIT License

*/

#include <Wire.h>
#include <ClosedCube_SHT31D.h>

ClosedCube_SHT31D sht31d;

void setup()
{
	Serial.begin(9600);
	Serial.println("ClosedCube SHT31-D T/RH and TCA9546A Switch boards");
  Wire.begin();
  
  for( int channel=0; channel<4; channel++ ) {
    selectChannel(channel);
    Serial.print("CHANNEL=");
    Serial.print(channel);
    Serial.print(" ");
    sht31d.begin(0x44);
    Serial.print("SHT31 Serial #");
    Serial.println(sht31d.readSerialNumber());  

    if (sht31d.periodicStart(REPEATABILITY_HIGH, FREQUENCY_10HZ) != NO_ERROR)
      Serial.println("[ERROR] Cannot start periodic mode");
  }  
	
}

void loop()
{
  for( int channel=0; channel<4; channel++ ) {
    selectChannel(channel);
    Serial.print("CHANNEL=");
    Serial.print(channel);
    Serial.print(" ");
   	printResult("Periodic Mode", sht31d.periodicFetchData());
  }
	delay(1000);
}

void selectChannel(uint8_t channel)
{
  if( channel >= 0 && channel < 4 ) {
    Wire.beginTransmission(0x77);
    switch(channel) {
      case 0:
        Wire.write(0x01);
        break;
      case 1:
        Wire.write(0x02);
        break;
      case 2:
        Wire.write(0x04);
        break;
      case 3:
        Wire.write(0x08);
        break;
    }
    Wire.endTransmission();
  } else {
    Serial.print("TCA9546A ERROR - Wrong channel selected: ");
    Serial.print(channel);
    Serial.print(" (available channels 0,1,2 and 3)");
  }
}

void printResult(String text, SHT31D result) {
	if (result.error == NO_ERROR) {
		Serial.print(text);
		Serial.print(": T=");
		Serial.print(result.t);
		Serial.print("C, RH=");
		Serial.print(result.rh);
		Serial.println("%");
	}
	else {
		Serial.print(text);
		Serial.print(": [ERROR] Code #");
		Serial.println(result.error);
	}
}