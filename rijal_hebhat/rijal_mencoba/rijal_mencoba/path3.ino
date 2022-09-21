
void path3(){
  // coordinate (1;6)
  kinematik();
//route go
if((x == 1) && (y == 6)){//destination
  xy();
  setx();
  count = 5; //fungsi count?
  Break(); //perintah untuk berhenti?

  Go();  
}

if((x == 0 ) && (y < 6)){//forward until y = 6
  xy();
  setx();
  Go(); // maju kecepatan 90
}

if((blank == 0) && (x == 0 ) && (y == 6)){
  xy();
  setx();
  blank = 1;
  down();//fungsi untuk apa?
  delay(450);
  Break(); // kenapa pwm 0 tapi semua di set high?
  sharpLeft(); //belok kiri tajam
  Stop();
  delay(100);
}

if(( x >= 0 ) && (y == 6 ) && ( x < 3 )){//forward until x = 6
  xy();
  setx();
  Go(); // maju kecepatan 90
  
}

//route return
if((x >= 2) && (y == 6) ){
  xy();
  setx();
  blank = 0;
  down();//mundur sedikit
  delay(450);
  Break();
  sharpLeft();
  Stop();
  delay(100);
  Go();
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
