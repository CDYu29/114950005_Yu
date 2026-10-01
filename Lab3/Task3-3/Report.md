**`Lab3/Task3-3/report.md`（完整示範報告）**

```markdown
# 課題報告：HC-05 Wireless LED Control

- **學生姓名**：余佳紜
- **學生學號**：114950005
- **完成日期**：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)
- Using an HC05 module to implement LED control through wireless communication
- Complete the previous task again, but this time with Bluetooth communication.
- The Arduino receives commands from the host PC application using an HC-05 module.
- The key to completing this task is configuring the HC05 Bluetooth module.
- You may also need to revise the Arduino sketch and C# code accordingly

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- LED*1
- HC-05*1

### 3. 操作說明與成果
1. 使用SerialPort(序列埠)指定對應的 COM Port和Baud Rate（9600）建立連線
    - SerialPort（序列埠 / 串列埠）：電腦與微控制器之間的一條「專用單線道傳輸水管」
        - 關鍵特性：一次只能被一個程式佔用。如果 Arduino IDE 的 Serial Monitor 正開著，這條水管就被佔滿了，C# 就會被擋在門外跳出「Access Denied」
    - Baud Rate（9600）：水管傳送資料的「傳輸速度 / 節奏」，單位是每秒傳輸多少個符號（通常等於 bits per second, bps）
    - AT-mode Baud Rate：設定模式，固定通常為 38400，用來向模組下達指令（例如改名稱、改密碼、查詢或修改一般鮑率）

2. 透過藍芽連接電腦與硬體

3. 按下電腦頁面的按鈕後，LED隨按鈕指令變化
    - ON為亮，OFF為暗
    
