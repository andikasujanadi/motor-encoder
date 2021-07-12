void jalan(int arah){
   switch(arah){
    case 0 : putar(0,1);putar(1,0);putar(2,0);putar(3,1);PID0();break;
    case 1 : putar(0,0);putar(1,0);putar(2,1);putar(3,1);break;
    case 2 : putar(0,0);putar(1,1);putar(2,1);putar(3,0);break;
    case 3 : putar(0,1);putar(1,1);putar(2,0);putar(3,0);break;
    case 4 : berhenti(0);berhenti(1);berhenti(2);berhenti(3);break;
  }
}
void putar(int a, int b){
  int c;
  switch(b){
    case 0:
    switch(a){
      case 0: c=pwm0[0];break;
      case 1: c=pwm0[1];break;
      case 2: c=pwm0[2];break;
      case 3: c=pwm0[3];break;
    }break;
    case 1:
    switch(a){
      case 0: c=pwm1[0];break;
      case 1: c=pwm1[1];break;
      case 2: c=pwm1[2];break;
      case 3: c=pwm1[3];break;
    }break;
  }
  putar_cstm(a,b,c);
}
void putar_cstm(int a, int b, int pwm){
  digitalWrite(motor[a],!b);
  digitalWrite(motor[a+4],b);
  analogWrite(motor_pwm[a],pwm);
}
void berhenti(int a){
  digitalWrite(motor[a],1);
  digitalWrite(motor[a+4],1);
  analogWrite(motor_pwm[a],0);
}
