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
  attachInterrupt(0, flag0, CHANGE);
  attachInterrupt(4, flag1, CHANGE);
}

void loop() {
  hitung();
}

void flag0(){
  flag(0);
}
void flag1(){
  flag(1);
}

void flag(int a){
  if(digitalRead(CHA[a])and!digitalRead(CHB[a])){
    count[a]++;
  }
  if(digitalRead(CHA[a])and digitalRead(CHB[a])){
    count[a]--;
  }
}

void hitung(){
  if(count_old[0]!=count[0] or count_old[1]!=count[1] or count_old[2]!=count[2]){
    Serial.print("enc 0 : ");Serial.print(count[0]);
    Serial.print("  ||  enc 1 : ");Serial.println(count[1]);
  }
  for(int i=0; i<3;i++){
    count_old[i]=count[i];
  }
}
