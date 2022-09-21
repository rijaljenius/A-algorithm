void path2(){
  // coordinate (6;0)


   
  //line trace
  if ((digitalRead(L_S) == LOW)&&(digitalRead(S_S) == LOW)&&(digitalRead(R_S) == LOW)){ForwardSlow();}
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

//route go
if((x == 7) && (y == 6)){//destination
  xy();
  count = 5; //fungsi count?
  Break(); //perintah untuk berhenti?

  Go();  
}

if((x == 9 ) && (y < 6)){//forward until y = 6
  xy();
  Go(); // maju kecepatan 90
}

if((blank == true) && (x == 9 ) && (y == 6)){
  xy();
  blank = false;
  down();//fungsi untuk mundur sedikit
  delay(450);
  Break(); // kenapa pwm 0 tapi semua di set high?
  sharpRight(); //belok kiri tajam
  Stop();
  delay(100);
}

if(( x > 6 ) && (y == 6 ) && ( x < 9 )){//forward until x = 6
  xy();
  Go(); // maju kecepatan 90
}

//route return
if((x == 6) && (y == 6) ){
  xy();
  blank = 0;
  down();//mundur sedikit
  delay(450);
  Break();
  sharpRight();
  Stop();
  delay(100);
  Go();
}
if ((x <= 6) && (y < 6) && (y > 0) && (count > 1)){
  xy();
  Go();
  }
  
if ((x == 6) && (y == 0)&& (count > 1)){
  xy();
  endline = 1;
  down();
  delay(450);
  Break();
  Stop();
  }


if ((x == 6) && (y == 0) && (endline == 1)){
  xy();
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


//scan
kode = Serial2.readString();
kode.trim();
Serial.print("Coordinate: ");
Serial.println(kode);

if(kode.substring(0) == "0.0"){x = 0;y = 0;}
if(kode.substring(0) == "0.1"){x = 0;y = 1;}
if(kode.substring(0) == "0.2"){x = 0;y = 2;}
if(kode.substring(0) == "0.3"){x = 0;y = 3;}
if(kode.substring(0) == "0.4"){x = 0;y = 4;}
if(kode.substring(0) == "0.5"){x = 0;y = 5;}
if(kode.substring(0) == "0.6"){x = 0;y = 6;}

if(kode.substring(0) == "1.0"){x = 1;y = 0;}
if(kode.substring(0) == "2.0"){x = 2;y = 0;}
if(kode.substring(0) == "3.0"){x = 3;y = 0;}
if(kode.substring(0) == "4.0"){x = 4;y = 0;}
if(kode.substring(0) == "5.0"){x = 5;y = 0;}
if(kode.substring(0) == "6.0"){x = 6;y = 0;}
if(kode.substring(0) == "7.0"){x = 7;y = 0;}
if(kode.substring(0) == "8.0"){x = 8;y = 0;}
if(kode.substring(0) == "9.0"){x = 9;y = 0;}
if(kode.substring(0) == "10.0"){x = 10;y = 0;}
if(kode.substring(0) == "11.0"){x = 11;y = 0;}
if(kode.substring(0) == "12.0"){x = 12;y = 0;}
if(kode.substring(0) == "13.0"){x = 13;y = 0;}
if(kode.substring(0) == "14.0"){x = 14;y = 0;}

if(kode.substring(0) == "1.1"){x = 1;y = 1;}
if(kode.substring(0) == "1.2"){x = 1;y = 2;}//flip3
if(kode.substring(0) == "1.3"){x = 1;y = 3;}
if(kode.substring(0) == "1.4"){x = 1;y = 4;}//flip2
if(kode.substring(0) == "1.5"){x = 1;y = 5;}
if(kode.substring(0) == "1.6"){x = 1;y = 6;}//flip1

if(kode.substring(0) == "2.1"){x = 2;y = 1;}
if(kode.substring(0) == "2.2"){x = 2;y = 2;}
if(kode.substring(0) == "2.3"){x = 2;y = 3;}
if(kode.substring(0) == "2.4"){x = 2;y = 4;}
if(kode.substring(0) == "2.5"){x = 2;y = 5;}
if(kode.substring(0) == "2.6"){x = 2;y = 6;}

if(kode.substring(0) == "3.1"){x = 3;y = 1;}
if(kode.substring(0) == "3.2"){x = 3;y = 2;}
if(kode.substring(0) == "3.3"){x = 3;y = 3;}
if(kode.substring(0) == "3.4"){x = 3;y = 4;}
if(kode.substring(0) == "3.5"){x = 3;y = 5;}
if(kode.substring(0) == "3.6"){x = 3;y = 6;}

if(kode.substring(0) == "4.1"){x = 4;y = 1;}
if(kode.substring(0) == "4.2"){x = 4;y = 2;}//flip6
if(kode.substring(0) == "4.3"){x = 4;y = 3;}
if(kode.substring(0) == "4.4"){x = 4;y = 4;}//flip5
if(kode.substring(0) == "4.5"){x = 4;y = 5;}
if(kode.substring(0) == "4.6"){x = 4;y = 6;}//flip4

if(kode.substring(0) == "5.1"){x = 5;y = 1;}
if(kode.substring(0) == "5.2"){x = 5;y = 2;}
if(kode.substring(0) == "5.3"){x = 5;y = 3;}
if(kode.substring(0) == "5.4"){x = 5;y = 4;}
if(kode.substring(0) == "5.5"){x = 5;y = 5;}
if(kode.substring(0) == "5.6"){x = 5;y = 6;}

if(kode.substring(0) == "6.1"){x = 6;y = 1;}
if(kode.substring(0) == "6.2"){x = 6;y = 2;}
if(kode.substring(0) == "6.3"){x = 6;y = 3;}
if(kode.substring(0) == "6.4"){x = 6;y = 4;}
if(kode.substring(0) == "6.5"){x = 6;y = 5;}
if(kode.substring(0) == "6.6"){x = 6;y = 6;}

if(kode.substring(0) == "7.1"){x = 7;y = 1;}
if(kode.substring(0) == "7.2"){x = 7;y = 2;}//flip9
if(kode.substring(0) == "7.3"){x = 7;y = 3;}
if(kode.substring(0) == "7.4"){x = 7;y = 4;}//flip8
if(kode.substring(0) == "7.5"){x = 7;y = 5;}
if(kode.substring(0) == "7.6"){x = 7;y = 6;}//flip7

if(kode.substring(0) == "8.1"){x = 8;y = 1;}
if(kode.substring(0) == "8.2"){x = 8;y = 2;}
if(kode.substring(0) == "8.3"){x = 8;y = 3;}
if(kode.substring(0) == "8.4"){x = 8;y = 4;}
if(kode.substring(0) == "8.5"){x = 8;y = 5;}
if(kode.substring(0) == "8.6"){x = 8;y = 6;}

if(kode.substring(0) == "9.1"){x = 9;y = 1;}
if(kode.substring(0) == "9.2"){x = 9;y = 2;}
if(kode.substring(0) == "9.3"){x = 9;y = 3;}
if(kode.substring(0) == "9.4"){x = 9;y = 4;}
if(kode.substring(0) == "9.5"){x = 9;y = 5;}
if(kode.substring(0) == "9.6"){x = 9;y = 6;}

if(kode.substring(0) == "10.1"){x = 10;y = 1;}
if(kode.substring(0) == "10.2"){x = 10;y = 2;}//flip12
if(kode.substring(0) == "10.3"){x = 10;y = 3;}
if(kode.substring(0) == "10.4"){x = 10;y = 4;}//flip11
if(kode.substring(0) == "10.5"){x = 10;y = 5;}
if(kode.substring(0) == "10.6"){x = 10;y = 6;}//flip10

if(kode.substring(0) == "11.1"){x = 11;y = 1;}
if(kode.substring(0) == "11.2"){x = 11;y = 2;}
if(kode.substring(0) == "11.3"){x = 11;y = 3;}
if(kode.substring(0) == "11.4"){x = 11;y = 4;}
if(kode.substring(0) == "11.5"){x = 11;y = 5;}
if(kode.substring(0) == "11.6"){x = 11;y = 6;}

if(kode.substring(0) == "12.1"){x = 12;y = 1;}
if(kode.substring(0) == "12.2"){x = 12;y = 2;}
if(kode.substring(0) == "12.3"){x = 12;y = 3;}
if(kode.substring(0) == "12.4"){x = 12;y = 4;}
if(kode.substring(0) == "12.5"){x = 12;y = 5;}
if(kode.substring(0) == "12.6"){x = 12;y = 6;}

if(kode.substring(0) == "13.1"){x = 13;y = 1;}
if(kode.substring(0) == "13.2"){x = 13;y = 2;}//flip15
if(kode.substring(0) == "13.3"){x = 13;y = 3;}
if(kode.substring(0) == "13.4"){x = 13;y = 4;}//flip14
if(kode.substring(0) == "13.5"){x = 13;y = 5;}
if(kode.substring(0) == "13.6"){x = 13;y = 6;}//flip13

if(kode.substring(0) == "14.1"){x = 14;y = 1;}
if(kode.substring(0) == "14.2"){x = 14;y = 2;}
if(kode.substring(0) == "14.3"){x = 14;y = 3;}
if(kode.substring(0) == "14.4"){x = 14;y = 4;}
if(kode.substring(0) == "14.5"){x = 14;y = 5;}
if(kode.substring(0) == "14.6"){x = 14;y = 6;}

 }
