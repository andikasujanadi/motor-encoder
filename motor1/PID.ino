void PID0(){
  int a=count[0],b=count[1];
  if(b>a){
    pwm0[1]= pwm0[1]/2;
    pwm1[0]=pwm1_[0];
  }
  else if((a+1000)>b){
    pwm1[0]= pwm1[0]/2;
    pwm0[1]=pwm0_[1];
  }
  else{
    pwm0[1]=pwm0_[1];
    pwm1[0]=pwm1_[0];
  }
}
