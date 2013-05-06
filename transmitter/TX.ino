/*
  Mega multple serial test
 
 Receives from the main serial port, sends to the others. 
 Receives from serial port 1, sends to the main serial (Serial 0).
 
 This example works only on the Arduino Mega
 
 The circuit: 
 * Any serial device attached to Serial port 1
 * Serial monitor open on Serial port 0:
 
 created 30 Dec. 2008
 modified 20 May 2012
 by Tom Igoe & Jed Roach
 
 This example code is in the public domain.
 
 */

#include <VirtualWire.h>
void setup() {
  // initialize Debug serial port
  Serial.begin(9600);
  
  // Transmission setup
  vw_set_tx_pin(4);
  //vw_set_ptt_inverted(true);
  vw_setup(1000);
}

void loop() {
  // read from port 1, send to port 0:
  //if (Serial1.available()) {
  //  int inByte = Serial1.read();
  //  Serial.write(inByte); 
  //}
  
  // read from port 0, send to port 1:
  //if (Serial.available()) {
  //  int inByte = Serial.read();
  //  Serial1.write(inByte); 
  //}
  
  int r = random(0,255);
  int g = random(0,255);
  int b = random(0,255);

  char msg[] = "000000";
  sprintf(msg, "%02X%02X%02X", r, g, b);
  Serial.println(msg);

  vw_send((uint8_t *)msg, strlen((const char *)msg));
  vw_wait_tx();

//  delay(100);
}
