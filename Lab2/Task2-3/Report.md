**`Lab2/Task2-3/report.md`（完整示範報告）**

```markdown
# 課題報告：External Interrupt vs Polling

- **學生姓名**：[余佳紜]
- **學生學號**：[114950005]
- **完成日期**：2026-09-24

---

### 1. 實驗目標(可參考課程投影片寫法)
- Build on Basic Task 2-3 by adding a second button + LED pair (Button B + LED B).
- Button A + LED A: keep using external interrupt to control the LED state
- Button B + LED B: use polling instead —
    - Continuously check Button B's state and detect press transitions (edge detection)
    - Toggle LED B when a press is detected
    - Add “ delay(2000) ” at the end of “ void loop() ”to simulate a busy/blocking system


### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- LED*2
- 按鈕*2
- 220Ω 電阻*2

### 3. 操作說明與成果
1. 分為A、B兩組不同感測方式的LED開關組合，按一下改變狀態
2. A(紅色LED)為外部中斷，即感測到按鈕被按下時便中斷主函式，執行外部中斷的函式
3. B(藍色LED)為輪詢，即每隔固定時間，主動向伺服器或其他系統發送請求，因此較容易有delay的問題，但從運作邏輯上較單純
