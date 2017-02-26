#include "mbed.h"
#include "VL53L0X.h"

/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.
The range readings are in units of mm. */


Serial pc(SERIAL_TX, SERIAL_RX);

DigitalInOut sda_D(PB_9);
DigitalInOut scl_D(PB_8);

// mbed uses 8bit addresses shift address by 1 bit left
VL53L0X sensor_D(PB_9, PB_8);


int main() {
 pc.baud(115200);

  wait_ms(100); // delay .1s
    pc.printf("starting continuous\n");
  sda_D.mode(PullUp);
  scl_D.mode(PullUp);
  //sensor_D.getIdentification(&identification); // Retrieve manufacture info from device memory
  //printIdentification(&identification); // Helper function to print all the Module information

  sensor_D.init();
  sensor_D.setTimeout(500);

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor_D.startContinuous(50);
  while(1) {
    pc.printf("range  = %d\n",sensor_D.readRangeContinuousMillimeters());
//    if (sensor_D.timeoutOccurred()) { printf(" TIMEOUT\n"); }
  }
}
