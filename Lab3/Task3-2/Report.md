**`Lab3/Task3-2/report.md`（完整示範報告）**

```markdown
# 課題報告：LED Control with Serial Communication

- **學生姓名**：余佳紜
- **學生學號**：114950005
- **完成日期**：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)
- Host PC App (C#) (未來跟VR、Unity對接)
    - Design a GUI to control the LED
    - When a button is pressed, send the corresponding value through the
    serial port
- Arduino Firmware (.ino)
    -Initialize Serial.begin(9600)
    - Continuously listen for incoming serial strings
    - Turn the LED on / off according to the data received from the PC app

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- LED*1

### 3. 操作說明與成果
1. 使用SerialPort(序列埠)指定對應的 COM Port和Baud Rate（9600）建立連線
    - SerialPort（序列埠 / 串列埠）：電腦與微控制器之間的一條「專用單線道傳輸水管」
        - 關鍵特性：一次只能被一個程式佔用。如果 Arduino IDE 的 Serial Monitor 正開著，這條水管就被佔滿了，C# 就會被擋在門外跳出「Access Denied」
    - 水管傳送資料的「傳輸速度 / 節奏」，單位是每秒傳輸多少個符號（通常等於 bits per second, bps）（常用9600）

2.按下電腦頁面的按鈕後，LED隨按鈕指令變化
    - ON為亮，OFF為暗
    
