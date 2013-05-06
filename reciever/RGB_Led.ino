#include <VirtualWire.h>

int lred = 6;
int lgreen = 11;
int lblue = 12;

int r = 100;
int g = 56;
int b = 130;

char buffer[] = "000000";

void setup() {
  Serial.begin(9600);
  Serial.println("Setup done");
  vw_set_rx_pin(0);
  vw_setup(1000);
  //vw_set_ptt_inverted(true);
  vw_rx_start();
  
  pinMode(lred, OUTPUT);
  pinMode(lgreen, OUTPUT);
  pinMode(lblue, OUTPUT);
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) {
    
     int i;
     Serial.print("Got: ");
     
     for (i = 0; i < buflen; i++) {
       buffer[i] = buf[i];
//	    Serial.print(buf[0]);
//	    Serial.print(" ");
     }
     Serial.print(buffer);
    sscanf(buffer, "%2x%2x%2x", &r, &g, &b);

    Serial.print(" - ");
    Serial.print(r);
    Serial.print("|");
    Serial.print(g);
    Serial.print("|");
    Serial.print(b);
    Serial.println("");
    analogWrite(lred, r);
    analogWrite(lgreen, g);
    analogWrite(lblue, b);
  }
}
