#include <SoftwareSerial.h>

// 定義軟體序列埠：RX 接 Pin 10，TX 接 Pin 11
SoftwareSerial BTSerial(10, 11); 

const int ledPin = 8; // 或 13

void setup() {
  pinMode(ledPin, OUTPUT);
  BTSerial.begin(9600); // HC-05 預設傳輸鮑率為 9600
}

void loop() {
  if (BTSerial.available() > 0) {
    char cmd = BTSerial.read();
    if (cmd == '1') {
      digitalWrite(ledPin, HIGH);
    } else if (cmd == '0') {
      digitalWrite(ledPin, LOW);
    }
  }
}