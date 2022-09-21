
void encoderKiri(){
  int b = digitalRead(LENCB);
  if(b > 0){
    step1++;
  }
  else{
    step1--;
  }
}

void encoderKanan(){
  int d = digitalRead(RENCB);
  if(d > 0){
    step2++;
  }
  else{
    step2--;
  }
  stepp=step2*(-1);//step roda yg bernilai negatif harus dikalikan -1 agar menjadi positif, karena dimasukkan ke kinematik robot yg bergerak maju nilainya harus positif, sebaliknya ketika mundur encoder kedua roda sama sama negatif
}

void Stoploss(){ // stop 
analogWrite(speed1, 0);
analogWrite(speed2, 0);
digitalWrite(MA1, LOW);
digitalWrite(MA2, LOW);
digitalWrite(MB2, LOW);
digitalWrite(MB1, LOW);  
}

void Go2(){ //maju
  analogWrite(speed1, 93);//70(1), 80(2), 73(3)
analogWrite(speed2, 90);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW); 
  delay(400);
}

void Forwardlast(){
analogWrite(speed1, 85);
analogWrite(speed2, 85);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW);
delay(500);  
}

void ForwardSlow2(){
analogWrite(speed1, 0);
analogWrite(speed2, 0);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW);  
}

void down(){
analogWrite(speed1, 60);
analogWrite(speed2, 60);
digitalWrite(MA1, HIGH);
digitalWrite(MA2, LOW);
digitalWrite(MB2, LOW);
digitalWrite(MB1, HIGH);  
}

void turnRight(){
analogWrite(speed1, 50);
analogWrite(speed2, 50);
digitalWrite(MA1, LOW);
digitalWrite(MA2, LOW);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW);  
}

void turnLeft(){
analogWrite(speed1, 50);
analogWrite(speed2, 50);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, LOW);
digitalWrite(MB1, LOW);
}

void Stop(){
analogWrite(speed1, 0);
analogWrite(speed2, 0);
digitalWrite(MA1, HIGH);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, HIGH);
}

void Break(){
analogWrite(speed1, 0);
analogWrite(speed2, 0);
digitalWrite(MA1, HIGH);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, HIGH);
delay(300);
}

void sharpRight(){
analogWrite(speed1, 100);
analogWrite(speed2, 100);
digitalWrite(MA1, HIGH);
digitalWrite(MA2, LOW);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW);
delay(420);//
}

void sharpLeft(){
analogWrite(speed1, 100);
analogWrite(speed2, 100);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, LOW);
digitalWrite(MB1, HIGH);
delay(430);//430 //380
}

void endLeft(){
analogWrite(speed1, 100);
analogWrite(speed2, 100);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, LOW);
digitalWrite(MB1, HIGH);
//delay(400);//430 //380
}

void sharpRight2(){
analogWrite(speed1, 110);
analogWrite(speed2, 90);
digitalWrite(MA1, HIGH);
digitalWrite(MA2, LOW);
digitalWrite(MB2, HIGH);
digitalWrite(MB1, LOW);
delay(420);//
}

void sharpLeft2(){
if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == LOW)){Stop();}
else{
analogWrite(speed1, 50);
analogWrite(speed2, 50);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, LOW);
digitalWrite(MB1, HIGH);
}
}

void tracer(){
 analogWrite(speed1, 100);
analogWrite(speed2, 100);
digitalWrite(MA1, LOW);
digitalWrite(MA2, HIGH);
digitalWrite(MB2, LOW);
digitalWrite(MB1, HIGH);
delay(200);//430 //380
}

void xy(){
  x = -1;
  y = -1;
}

void setx(){
  Sx = 0;
  step1 = 0;
  step2 = 0;
}
