**`Lab3/Task3-1/report.md`（完整示範報告）**

```markdown
# 課題報告：Timer Interrupt vs Blocking Delay

- **學生姓名**：[余佳紜]
- **學生學號**：[114950005]
- **完成日期**：2026-09-24

---

### 1. 實驗目標(可參考課程投影片寫法)
- download the external library “TimerOne”: from the library manager in Arduino IDE
- Button A + LED A Timer Interrupt (TimerOne)
    - TimerOne library sets up a periodic interrupt every 50ms
    - Read Button A's state and update LED A inside the ISR
- Button B + LED B Blocking Delay
    - Read Button B's state and update LED B every loop
    - Insert a 1 second at the end of“ void loop() ”function.

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- LED*2
- 按鈕*2
- 220Ω 電阻*2

### 3. 操作說明與成果
1. 分為A、B兩組不同感測方式的LED開關組合，要按著才會亮
2. A(紅色LED)為計時器中斷，類似於外部中斷，但是為"每隔固定時間"中斷主函式，執行外部中斷的函式(即感測按鈕是否按下)，適合用於可預期時間間隔的功能
3. B(藍色LED)為輪詢，即每隔固定時間，主動向伺服器或其他系統發送請求，因此較容易有delay的問題，但從運作邏輯上較單純

