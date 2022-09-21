void loop() {
  scan();
  path3();

  if (Sx <= 28)  //Sx = jarak sumbu x
  {
    pwm=100;
  }
  else Stop();

  Serial.print("Sx: ");
  Serial.println(Sx);
  
}

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

void kinematik()
{ 
  float jaraksetengahsekon1 = step1*0.0666;  //dikarenakan waktu sampling setengah sekon, maka dicari jarak setengah sekon, yaitu jumlah step dikalikan 0.0666 cm
  float jaraksetengahsekon2 = stepp*0.0666;
  float kecepatan1 = jaraksetengahsekon1 / t;   //t adalah waktu sampling kecepatan dalam 0.5 sekon 
  float kecepatan2 = jaraksetengahsekon2 / t;

  float Vx = (0.5*cos(teta/57.2958)*kecepatan1)+(0.5*cos(teta/57.2958)*kecepatan2);  //rumus kinematik jalan lurus
  float Vy = (sin(teta/57.2958)*kecepatan1)+(sin(teta/57.2958)*kecepatan2);

  Sx = Vx*t;
  Sy = Vy*t;
}
