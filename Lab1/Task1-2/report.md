**`Lab1/Task1-2/report.md`（完整示範報告）**

```markdown
# 課題報告：RGB LED — Layering Three Inputs

- **學生姓名**：[余佳紜]
- **學生學號**：[114950005]
- **完成日期**：2026-09-17

---

### 1. 實驗目標(可參考課程投影片寫法)
- Control an RGB LED with three inputs, each layering on top of the last
- R = Button (digital input) 
- G = Serial input (from the Serial Monitor) 
- B = Variable resistor (analog input)

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- 接線*n
- RGB LED*1
- 可變電阻*1
- 按紐*1
- 220Ω 電阻*1
- 10KΩ 電阻*1

### 3. 操作說明與成果
1. 轉動可變電阻改藍光亮度
2. 按下按鈕使紅光混入成紫色
3. 輸入"1"混入綠色，輸入0可關閉綠色
4. 輸入"1"後，轉開藍光，按著按鈕可使LED顯示白色
