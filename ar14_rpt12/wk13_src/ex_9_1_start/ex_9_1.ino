/*
 예제 9.1
 피에조 부저를 이용한 소리 출력
*/

int buzzerPin = 9;
int songLength = 16;
int dopin=2;
int repin=2;
int mipin=3;
boolean dpp=false;
boolean rpp=false;
boolean mpp=false;
int duration=10;

void setup() 
{
  // 부저핀을 출력으로 설정한다
  pinMode(buzzerPin, OUTPUT);
  pinMode(dopin,INPUT_PULLUP);
  pinMode(repin,INPUT_PULLUP);
  pinMode(mipin,INPUT_PULLUP);
}


void loop() 
{
  // 부저 출력 시간에 사용할 변수 설정
  int dp=digitalRead(dopin);
  int rp=digitalRead(repin);
  int mp=digitalRead(mipin);
  
  // 노래 길이 데이터 갯수만큼 반복한다

    if (dp=LOW){      // 공란일 경우 음을 출력하지 않는다
     dpp=true;
     rpp=false;
     mpp=false; 
    }
    else if(rp==LOW) {
        dpp=false;
     rpp=true;
     mpp=false; 
    }
    else if(mp==LOW) {
        dpp=false;
     rpp=false;
     mpp=true; 
    }
    else {
        dpp=false;
     rpp=false;
     mpp=false; 
    }
    // 음이 바뀔 때 잠시 쉬어준다
    
  }


int frequency(char note){
  // 노래 데이터를 주파수 값으로 변경하기 위한 함수

  int i;
  // 음계의 갯수 설정
  int notes = 8;

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // 노래 데이터를 주파수 값으로 변경하기 위해 반복하여 비교한다  
  for (i = 0; i < notes; i++){
    if (names[i]==note ){
      // 맞는 값을 찾았을 경우 이 값을 회신한다
      return(frequencies[i]);
    };
  };
  // 앞의 for문에서 맞는 값을 못찾았을 경우 0을 회신한다
  return(0);
}
