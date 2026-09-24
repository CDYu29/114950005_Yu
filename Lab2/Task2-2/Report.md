**`Lab2/Task2-2/report.md`（完整示範報告）**

```markdown
# 課題報告：Ultrasonic Sensor Drives Servo Angle

- **學生姓名**：[余佳紜]
- **學生學號**：[114950005]
- **完成日期**：2026-09-24

---

### 1. 實驗目標(可參考課程投影片寫法)
- Servo Motor Control with an Ultrasonic Sensor Controlling the angle of the servo motor according to the measured distance.
- Please investigate how to use the ultrasonic sensor module HC-SR04 by yourselves.

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- hc-sr04 超音波感測器*1
- sg90 伺服馬達*1

### 3. 操作說明與成果
1. 設定感測區間為10-40 cm
2. 從10 cm開始感測，若物體越靠遠離則伺服馬達轉動角越大
3. 若感測距離小於10 cm 或大於40 cm則轉動角為0
