/*

Arduino Library for Texas Instruments TCA9546A 4-Channel I2C Multiplexer/Switch With Reset
Written by AA for ClosedCube
---

The MIT License (MIT)

Copyright (c) 2017 ClosedCube Limited

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include <Wire.h>

#include "ClosedCube_TCA9546A.h"


ClosedCube_TCA9546A::ClosedCube_TCA9546A() {
}

void ClosedCube_TCA9546A::begin(uint8_t address) {
	_address = address;
	Wire.begin();

	selectChannel(0);
}

uint8_t ClosedCube_TCA9546A::getChannel() {
	return _currentChannel;
}

uint8_t ClosedCube_TCA9546A::selectChannel(uint8_t channel) {

	if (channel >= 0 && channel < 4) {
		Wire.beginTransmission(_address);
		switch (channel) {
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
		_currentChannel = channel;
		return Wire.endTransmission();
	}
	else {
		return 0xff;
	}
}


uint8_t ClosedCube_TCA9546A::nextChannel() {
	uint8_t nextChannel = _currentChannel + 1;
	if (nextChannel > 3)
		nextChannel = 0;

	selectChannel(nextChannel);
}
