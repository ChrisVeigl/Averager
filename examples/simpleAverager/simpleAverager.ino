/*
 * SimpleAverage.ino
 * Demonstrates the use of the Averager class
 */


#include "Averager.h"

Averager avg5(5);
Averager avg10(10);
Averager avg50(50);

void setup() {
  Serial.begin(115200);
}


void loop() {
  static int count=0;

  // create a sine wave with some noise
  int actSignal	= (int) (sin((float)count++/50.0) * 500) + random (-50,50);

  // print raw and averaged signals
  Serial.print(actSignal); Serial.print(", ");
  Serial.print(avg5.process(actSignal)); Serial.print(", ");
  Serial.print(avg10.process(actSignal)); Serial.print(", ");
  Serial.println(avg50.process(actSignal));

  delay(10);  // about 100 Hz for the main loop
}