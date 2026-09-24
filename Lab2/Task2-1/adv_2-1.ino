const int POT_PIN = A0;  // 可變電阻中間腳
const int PIN_1A = 5;    // L293D 1A (PWM 腳位)
const int PIN_2A = 6;    // L293D 2A (PWM 腳位)

void setup() {
  pinMode(PIN_1A, OUTPUT);
  pinMode(PIN_2A, OUTPUT);
}

void loop() {
  int potVal = analogRead(POT_PIN); // 讀取 0 ~ 1023

  // 設定中間停轉死區 (490 ~ 534)，避免旋鈕在中心時微幅跳動
  if (potVal >= 490 && potVal <= 534) {
    // 停轉 (Stop)
    analogWrite(PIN_1A, 0);
    analogWrite(PIN_2A, 0);
  } 
  else if (potVal > 534) {
    // 順時針 (Clockwise)：旋鈕往右轉越深，轉速越快 (PWM: 0 ~ 255)
    int speed = map(potVal, 535, 1023, 0, 255);
    analogWrite(PIN_1A, speed);
    analogWrite(PIN_2A, 0);
  } 
  else {
    // 逆時針 (Counterclockwise)：旋鈕往左轉越深，轉速越快 (PWM: 0 ~ 255)
    int speed = map(potVal, 489, 0, 0, 255);
    analogWrite(PIN_1A, 0);
    analogWrite(PIN_2A, speed);
  }
}
