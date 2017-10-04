/**************************************************************************************

This is example for ClosedCube TCA9546A 4-Channel I2C Multiplexer With Reset breakout booard

Initial Date: 20-Jun-2017

Hardware connections for Arduino Uno:
 VDD to 3.3V DC
 SCL to A5
 SDA to A4
 GND to common ground

 SDx/SCx (where x = 0,1,2 or 3) - connect your I2C devices
 
Written by AA for ClosedCube

MIT License

**************************************************************************************/


#include <Wire.h>
#include "ClosedCube_TCA9546A.h"

ClosedCube_TCA9546A tca9546a;

void setup()
{
	Serial.begin(9600);
	Serial.println("ClosedCube TCA9546 Arduino Test");

	// I2C address is 0x77
	tca9546a.begin(0x77);

}

void loop()
{
	Serial.print("processing I2C channels...");

	tca9546a.selectChannel(0);
	// select channel 0 
	// @TODO - your code here and remove delay
	delay(250);
	Serial.print(tca9546a.getChannel());
	Serial.print("...");

	tca9546a.selectChannel(1);
	// select channel 1
	// @TODO - your code here and remove delay
	delay(250);
	Serial.print(tca9546a.getChannel());
	Serial.print("...");

	tca9546a.selectChannel(2);
	// select channel 2 
	// @TODO - your code here and remove delay
	delay(250);
	Serial.print(tca9546a.getChannel());
	Serial.print("...");

	tca9546a.selectChannel(3);
	// select channel 3 
	// @TODO - your code here and remove delay
	delay(250);
	Serial.print(tca9546a.getChannel());
	Serial.println();


	// NOTE: you can use .nextChannel method to select the following channel as follows: 0->1, 1->2, 2->3, 3->0
}

