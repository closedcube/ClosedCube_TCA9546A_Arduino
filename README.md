ClosedCube Arduino Library for
ClosedCube TCA9546A 4-Channel I2C Multiplexer/Switch With Reset Function Breakout Board
======================================================================================================

This is breakout board for [Texas Instruments TCA9546A](http://www.ti.com/product/TCA9546A) 4-Channel I2C Multiplexer/Switch With Reset Function

[![](https://github.com/closedcube/ClosedCube_TCA9546A_Arduino/blob/master/images/B360_TCA9546A_Pic1.jpg)](https://www.tindie.com/stores/closedcube/)
[![](https://github.com/closedcube/ClosedCube_TCA9546A_Arduino/blob/master/images/B360_TCA9546A_Pic2.jpg)](https://www.tindie.com/stores/closedcube/)

<b>Arduino code fragment:</b>
<pre>
<code>

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

</code>
</pre>







