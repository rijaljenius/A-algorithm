void loop() {
  scan();
  path3();
  kinematik();
  
  if (Sx <= 30)  //Sx = jarak sumbu x
  {
    pwm=100;
    Line();
  }
  else Stop();
  
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
