ClosedCube Arduino Library for
ClosedCube TCA9546A 4-Channel I2C Multiplexer/Switch With Reset Function Breakout Board
======================================================================================================

This is breakout board for [Texas Instruments TCA9546A](http://www.ti.com/product/TCA9546A) 4-Channel I2C Multiplexer/Switch With Reset Function

**Features:**

 - Active-Low Reset Input
 - Three Address Pins, default I2C address is 0x77
 - Channel Selection Via I2C Bus, in Any Combination
 - Power-up With All Switch Channels Deselected
 - Allows Voltage-Level Translation Between 1.8-V, 2.5-V, 3.3-V, and 5-V Buses
 - No Glitch on Power-up 
 - Supports Hot Insertion
 - Low Standby Current

[![](https://github.com/closedcube/ClosedCube_TCA9546A_Arduino/blob/master/images/B360_TCA9546A_Pic1.jpg)](https://www.tindie.com/stores/closedcube/)
[![](https://github.com/closedcube/ClosedCube_TCA9546A_Arduino/blob/master/images/B360_TCA9546A_Pic2.jpg)](https://www.tindie.com/stores/closedcube/)

<b>Alternative, you can use the following Arduino code fragment:</b>
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


### Where to Buy?

[![](http://images.closedcube.uk/logo/github/ebay.gif)](http://www.ebay.co.uk/itm/182438394905)(UK Store)

<a href="https://www.tindie.com/stores/closedcube/?ref=offsite_badges&utm_source=sellers_closedcube&utm_medium=badges&utm_campaign=badge_medium"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a>




