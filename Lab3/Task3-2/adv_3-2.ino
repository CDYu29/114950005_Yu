// Advanced Task 3-2: UART 控制 LED
// 可以使用板載 LED (Pin 13)，也可以外接 LED 到 Pin 8
const int LED_PIN = 13; 

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // 開機預設關燈
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();

    // 檢查收到的字元
    if (c == '1') {
      digitalWrite(LED_PIN, HIGH); // 開燈
    } 
    else if (c == '0') {
      digitalWrite(LED_PIN, LOW);  // 關燈
    }
  }
}
