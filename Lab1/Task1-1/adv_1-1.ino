const int potPin = A0;  // 可變電阻中間腳
const int ledPin = 9;   // 支援 PWM 的腳位

void setup() {
  Serial.begin(9600);   // 初始化序列埠傳輸
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(potPin);        // 讀取 0 ~ 1023
  int brightness = map(sensorValue, 0, 1023, 0, 255); // 轉成 0 ~ 255
  
  analogWrite(ledPin, brightness);             // 控制 LED 亮度
  
  // 印到 Serial Monitor
  Serial.print("Data is ");
  Serial.println(sensorValue);
  
  delay(1000); // 每秒更新一次
}
