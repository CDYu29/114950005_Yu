#include <TimerOne.h>

// 腳位分配
const int BUTTON_A_PIN = 2; // 中斷組按鍵
const int LED_A_PIN    = 8; // 中斷組 LED

const int BUTTON_B_PIN = 3; // 阻塞組按鍵
const int LED_B_PIN    = 9; // 阻塞組 LED

// TimerOne 中斷常式 (ISR)：每 50ms (0.05秒) 自動觸發一次
void timer_isr() {
  // 讀取 Button A 並即時更新 LED A
  // 因使用 INPUT_PULLUP，按下時為 LOW (接地)，放開時為 HIGH
  if (digitalRead(BUTTON_A_PIN) == LOW) {
    digitalWrite(LED_A_PIN, HIGH); // 按下亮燈
  } else {
    digitalWrite(LED_A_PIN, LOW);  // 放開熄滅
  }
}

void setup() {
  // 設定 LED 輸出
  pinMode(LED_A_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);

  // 設定按鍵為內部上拉輸入 (未按為 HIGH，按下一端通 GND 變 LOW)
  pinMode(BUTTON_A_PIN, INPUT_PULLUP);
  pinMode(BUTTON_B_PIN, INPUT_PULLUP);

  // 初始化 Timer1：50ms = 50,000 微秒 (投影片特別提醒單位是 microseconds)
  Timer1.initialize(50000);
  Timer1.attachInterrupt(timer_isr);
}

void loop() {
  // 讀取 Button B 並更新 LED B
  if (digitalRead(BUTTON_B_PIN) == LOW) {
    digitalWrite(LED_B_PIN, HIGH);
  } else {
    digitalWrite(LED_B_PIN, LOW);
  }

  // 投影片要求：在 loop 尾端強制延遲 1 秒造成阻塞
  delay(1000);
}
