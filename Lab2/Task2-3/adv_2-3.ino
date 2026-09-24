// --- 腳位定義 ---
const int buttonPinA = 2; // Button A: 外部中斷腳位（Uno 限 Pin 2 或 3）
const int ledPinA = 8;    // LED A: 中斷控制

const int buttonPinB = 4; // Button B: 一般數位腳位（輪詢）
const int ledPinB = 9;    // LED B: 輪詢控制

// --- 狀態變數 ---
// 中斷內會修改的變數必須宣告為 volatile
volatile bool ledStateA = LOW;

// 輪詢組變數
bool ledStateB = LOW;
bool lastButtonBState = HIGH; // INPUT_PULLUP 平時為 HIGH

// --- 中斷服務常式 (ISR) ---
void buttonISR() {
  ledStateA = !ledStateA;           // 切換 LED A 狀態
  digitalWrite(ledPinA, ledStateA);
}

void setup() {
  // LED 輸出設定
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);

  // 按鈕輸入設定（使用內建上拉電阻，未按下為 HIGH，按下為 LOW）
  pinMode(buttonPinA, INPUT_PULLUP);
  pinMode(buttonPinB, INPUT_PULLUP);

  // 註冊 Button A 的外部中斷：按鈕按下瞬間（HIGH -> LOW）觸發 FALLING
  attachInterrupt(digitalPinToInterrupt(buttonPinA), buttonISR, FALLING);
}

void loop() {
  // 1. 輪詢檢查 Button B 的狀態
  bool currentButtonBState = digitalRead(buttonPinB);

  // 邊緣偵測 (Edge Detection)：只有在「由放開變成按下」的瞬間才切換
  if (lastButtonBState == HIGH && currentButtonBState == LOW) {
    ledStateB = !ledStateB;           // 切換 LED B 狀態
    digitalWrite(ledPinB, ledStateB);
  }
  lastButtonBState = currentButtonBState; // 更新狀態記錄

  // 2. 投影片要求：模擬忙碌或被阻塞的系統
  delay(2000); // 卡住 2 秒
}