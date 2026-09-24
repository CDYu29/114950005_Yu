**`Lab2/Task2-1/report.md`（完整示範報告）**

```markdown
# 課題報告：Potentiometer Direction & Speed Control

- **學生姓名**：[余佳紜]
- **學生學號**：[114950005]
- **完成日期**：2026-09-24

---

### 1. 實驗目標(可參考課程投影片寫法)
- Add a variable resistor to the previous circuit, and use its angle to control both the motor's direction and speed.

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- motor driver IC: L293D*1
- DC motor*1

### 3. 操作說明與成果
1. 使用L293D控制直流電馬達運轉
2. 加入可變電阻改變馬達轉動方向和速度
    a. 方向：以置中設定一段死區，向右和向左轉動分別使馬達的轉動為不同方向
    b. 速度：轉動越大則轉速越快
