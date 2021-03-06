// 
//    FILE: continuousDemo.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: demo app HMC6352 library - continuous mode for Arduino
//
// HISTORY: 
// 0.1.0  - 2011-04-12 initial version
// 0.1.1  - 2017-09-13 renamed to .ino
// 
// Released to the public domain
//
// All disclaimers apply use at own risk
//

#include <Wire.h>
#include <hmc6352.h>

hmc6352 Compass(0x21);  // 0x21 <==> 33  <==> 66 >> 1

void setup()
{
  Serial.begin(19200);
  Serial.println("HMC6352: Version ");
  Serial.println(HMC_LIB_VERSION);
  Serial.print("current output modus");
  Serial.println(Compass.getOutputModus());
  
  int x = Compass.askHeading();
  //Serial.print("Ask returns: ");
  //Serial.println(x);  
}
int x;

void loop()
{
  // in continuous mode it is not needed to ask for a new reading every time
  // as it will do a new reading continuously even when not asked for
  // Try making a fast turn and see the difference with the query mode
  x = Compass.readHeading();
  Serial.print("Degree : ");
  Serial.println(x);
  delay(1000);
}
// END OF FILE









