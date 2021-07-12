/*manual

arah
            roda 0  ||  roda 1  ||  roda 2  ||  roda 3
0 = maju      PWM1  ||  PWM0    ||    PWM0  ||  PWM1
1 = kanan     PWM0  ||  PWM0    ||    PWM1  ||  PWM1
2 = mundur    PWM0  ||  PWM1    ||    PWM1  ||  PWM0
3 = kiri      PWM1  ||  PWM1    ||    PWM0  ||  PWM0

pasangan = 0 dan 2
           1 dan 3

putaran

0 = berlawanan
1 = searah

motor

0 = kanan depan
1 = kiri  depan
2 = kiri  belakang
3 = kanan belakang



*/

//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int
motor[8]    ={22,24,26,28,     //ini pin roda
              23,25,27,29},     
motor_pwm[4]={ 8, 9,10,11},
pwm1_[4]    ={50,50,50,60},
pwm0_[4]    ={50,55,60.5,50},
pwm1[4]     ={50,50,50,60},   //searah dgn jarum jam
pwm0[4]     ={50,55,60.5,50};   //berlawanan jarum jam

volatile int count[3]    ={0,0,0},
             count_old[3]={0,0,0};

const byte CHA[2]={2,18},
           CHB[2]={3,19};


void setup() {
  
  Serial.begin(9600);
  
  for(int i=0;i<2;i++){
    pinMode(CHA[i],INPUT);
    pinMode(CHB[i],INPUT);
  }
  for(int i=0;i<2;i++){
    digitalWrite(CHA[i],HIGH);
    digitalWrite(CHB[i],HIGH);
  }
  //RISING FALLING CHANGE
  attachInterrupt(0, flag0, CHANGE);
  attachInterrupt(4, flag1, CHANGE);
  
  for(int i=0;i<8;i++){
    pinMode(motor[i],OUTPUT);
  }
  for(int i=0;i<4;i++){
    pinMode(motor_pwm[i],OUTPUT);
  }
}

void loop() {
  hitung();  
  riset();
}
