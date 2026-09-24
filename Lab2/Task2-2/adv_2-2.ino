#include <Servo.h>
Servo myservo;
int trigPin = 11;    // 超音波感測器 Trig腳接 Arduino pin 11
int echoPin = 12;    //超音波感測器 Echo 腳接 Arduino pin 12
int motorPin = 9;  //馬達 + 腳接 Arduino pin 9
long duration, cm ;  //宣告計算距離時，需要用到的兩個實數

void setup()
{
  myservo.attach(9); //馬達接角
  myservo.write(0); //角度
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);      //Arduino 對外啟動距離感測器Trig腳，射出超音波 
  pinMode(echoPin, INPUT);       //超音波被障礙物反射後，Arduino讀取感測器Echo腳的時間差
  pinMode(motorPin, OUTPUT);   //Arduino對馬達作用
}

void loop() {

  //程式計算出距離值 cm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;  

  Serial.print(cm);     //印出距離值 cm 在序列埠監控顯示器 單位公分
  Serial.println(" cm");

  if (cm > 0) {
    cm = constrain(cm, 10, 40);
    int angle = map(cm, 10, 40, 0, 180); // 將 cm (10~40) 映射為角度 (0~180)
    myservo.write(angle);                 // 直接寫入計算好的角度

    delay(50);
  }

}
