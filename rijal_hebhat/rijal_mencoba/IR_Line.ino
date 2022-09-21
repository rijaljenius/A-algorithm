void Line() {
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW)){Forward();}
  if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == HIGH)){Forward();}
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == LOW)){Forward();}

  if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == LOW)){turnLeft2();}
  if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW)) {turnLeft2();}
//  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW)){turnLeft2();}


  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH)){turnRight2();}
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == HIGH)){turnRight2();}
//  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == HIGH)){turnRight2();}

  if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH))
  {
        Stoploss();
  }
}

void Go(){ //maju
analogWrite(speed1, pwm);//70(1), 80(2), 73(3)
analogWrite(speed2, pwm);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW); 

}

void Forward(){ //maju kecepatan 50
analogWrite(speed1, pwm);//70(1), 80(2), 73(3)
analogWrite(speed2, pwm);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW); 
}

void ForwardSlow(){
analogWrite(speed1, pwm-50);
analogWrite(speed2, pwm-50);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW);  
}

void turnRight2(){
analogWrite(speed1, pwm-50);
analogWrite(speed2, pwm);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW);  
}

void turnLeft2(){
analogWrite(speed1, pwm);
analogWrite(speed2, pwm-50);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW);
}
