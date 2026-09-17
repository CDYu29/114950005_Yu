// 定義腳位
const int redPin = 6;      // 紅光 (PWM)
const int greenPin = 9;    // 綠光 (PWM)
const int bluePin = 3;     // 藍光 (PWM)
const int potPin = A0;     // 可變電阻 (類比輸入)
const int buttonPin = 2;   // 按鈕 (數位輸入)

// 綠光狀態紀錄 (Serial 指令輸入後維持開啟)
bool greenEnabled = false;

void setup() {
  Serial.begin(9600);

  // 務必將三個顏色腳位皆設為 OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // 若使用麵包板外接下拉電阻接法 (沒按為 LOW，按下去為 HIGH)
  pinMode(buttonPin, INPUT);
}

void loop() {
  // 1. 藍光 (B)：由可變電阻控制亮度
  int sensorValue = analogRead(potPin);                  // 讀取 0 ~ 1023
  int blueBrightness = map(sensorValue, 0, 1023, 0, 255); // 轉為 0 ~ 255 PWM
  analogWrite(bluePin, blueBrightness);

  // 2. 紅光 (R)：按著才亮，放開就熄滅
  // 沒按是 LOW，按下去通電變 HIGH
  if (digitalRead(buttonPin) == HIGH) {
    analogWrite(redPin, 180); // 給予適當亮度，避免純紅蓋過藍光，混出明顯紫色
  } else {
    analogWrite(redPin, 0);
  }

  // 3. 綠光 (G)：序列埠輸入 '1' 疊加，輸入 '0' 關閉
  if (Serial.available() > 0) {
    char val = Serial.read();
    if (val == '1') {
      greenEnabled = true;
    } else if (val == '0') {
      greenEnabled = false;
    }
  }

  // 輸出綠光 (與目前的藍光、紅光疊加成白光)
  analogWrite(greenPin, greenEnabled ? 180 : 0);

  delay(10); // 穩定迴圈
}