/*
 예제 2.2
 변수 유형별 Arduino에서 컴퓨터로 전송하기
*/

// 65란 숫자를 유형별 변수에 저장한다.
int    number = 0;

// 문자열 네가지를 설정한다.
String stringValue[]={"Binary:", "Hexadecimal:"}; // array

void setup() {
  // 9600bps로 시리얼 통신 설정
  Serial.begin(9600);
}

void loop() {

  // 'char Value'를 출력하고 문자열과 숫자를 변수 유형별로 출력한다.
  Serial.print("Number=");  
  Serial.print(number); 
  Serial.print(",");  
  Serial.print(stringValue[0]); 
  Serial.print(number,BIN);
  Serial.print(","); 
  Serial.print(stringValue[1]); 
  Serial.print(number,HEX);
  Serial.println(); 

  number++;


  delay(1000);  // 10초동안 지연시킨다.
}
