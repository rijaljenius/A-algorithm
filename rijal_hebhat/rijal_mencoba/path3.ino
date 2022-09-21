void path3(){
  // coordinate (1;6)



//route go
if((x == 1) && (y == 6)){//destination
  xy();
  if (count == 5) { //fungsi count?
      setx();
      Go();  //perintah untuk berhenti?
     }
 else {
  count++ ;
  }
}

if((x == 0 ) && (y < 6)){//forward until y = 6
  xy();
  setx();
  Go(); // maju kecepatan 90
  
}

if((blank == true) && (x == 0 ) && (y == 6)){
  xy();
  blank = false;
  down();//fungsi untuk apa?
  delay(450);
  Break(); // kenapa pwm 0 tapi semua di set high?
  sharpLeft(); //belok kiri tajam
  Stop();
  delay(100);
}

if(( x == 0 ) && (y == 6 )){//forward until x = 6
  xy();
  setx();
  Go(); // maju kecepatan 90
  
}

//route return
if((blank == false) && (x >= 2) && (y == 6) ){
  xy();
  blank = true;
  down();//mundur sedikit
  delay(450);
  Break();
  sharpLeft();
  Stop();
  delay(100);
  Go();
}
if(( x == 2 ) && (y == 6 )){//forward until x = 6
  xy();
  setx();
  Go(); // maju kecepatan 90
  
}

if ((x >= 2) && (y < 6) && (y > 0) && (count > 1)){
  xy();
  setx();
  Go();
  }
  
if ((x == 2) && (y == 0)&& (count > 1)){
  xy();
  setx();
  endline = 1;
  down();
  delay(450);
  Break();
  sharpLeft();
  Forwardlast();
  }


if ((x == 1) && (y == 0) && (endline == 1)){
  xy();
  setx();
  Forward();
  delay(1400);
  Break();
  count = 0;
  endline = 0;
  blank = 0;
  endLeft();
  delay(500);
  Stop();
  delay(6000);
  } 
if(kode.substring(0) == "1.5"){
  xy();
  setx();
  Forward();
  delay(1400);
  Break();
  endLeft();
  delay(500);
  Stop();
  delay(1000);
}
}
void line(){
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW)){Forward();}
  if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == HIGH)){Forward();}
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == LOW)){Forward();}

  if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == LOW)){turnLeft2();}
  if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW)) {turnLeft2();}
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW)){turnLeft2();}


  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH)){turnRight2();}
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == HIGH)){turnRight2();}
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == HIGH)){turnRight2();}

  if ((digitalRead(L_S) == HIGH)&&(digitalRead(S_S) == HIGH)&&(digitalRead(R_S) == HIGH))
  {
    Stoploss();
  }
}
