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
