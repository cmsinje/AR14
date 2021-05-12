/*
 예제 5.2.2
 스위치 입력마다 LED On/Off 바꾸기
 바운싱 없는 스위치 입력 받기
 스위치 입력 횟수를 시리얼 통신으로 전송하기
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
// 내장된 LED 사용을 위해 13번핀을 출력으로 설정
  
// 2번핀을 스위치 입력으로 설정
const int inputPin = 2;
// 실제 스위치가 눌린 후 지연되는 시간


// 스위치 입력 횟수 저장 변수
long startTime=0;
// 실제 스위치가 눌린 시간을 계산하기 위한 변수
long swCountTimer=0;

void setup() {
  // 13번 핀에 내장된 LED를 출력으로 설정한다
Serial.begin(9600);
  // 스위치 입력을 위하여 2번핀을 입력으로 설정하고 풀업시킨다
  pinMode(inputPin, INPUT_PULLUP);
  // 시리얼 통신을 설정한다  
  lcd.init();
  lcd.backlight();
}

void loop(){

 if(digitalRead(inputPin)==LOW){
  lcd.clear();
  startTime=millis();
  while(digitalRead(inputPin)==LOW);
  swCountTimer=millis()-startTime;
  lcd.setCursor(0,0);
  lcd.print("AR07 time");
  lcd.setCursor(0,1);
  lcd.print(swCountTimer);
  delay(100);
  lcd.print("ms");
 };
}
