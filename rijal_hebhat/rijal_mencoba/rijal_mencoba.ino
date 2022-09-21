#include <Servo.h>
#include <Wire.h>
#define LENCA 2 // interrupt motor kiri1 encoder digunakan untuk menambah atau mengurangi step saat roda maju atau mundur
#define LENCB 4 // interrupt motor kiri2 encoder
#define RENCA 3 // interrupt motor kanan1 encoder
#define RENCB 5 // interrupt motor kanan2 encoder
int pos = 0;
String kode;

int speed1 = 11; // pwm kanan
int speed2 = 6; //pwm kiri
int MA1 = 9; //input kanan
int MA2 = 10; //input kanan
int MB1 = 8; //input kiri
int MB2 = 7; //input kiri

float Sx;
float Sy;
int pwm;

int stepp; //variabel baru untuk perkalian step2 dengan -1
int step1 = 0;
int step2 = 0;
float t = 0.5; //waktu sampling
float teta=0;

int R_S = A1; //Right sensor
int S_S = A2; //center sensor
int L_S = A3; //Left sensor

int st = 10, i = 0;

boolean state = true;
int count = 0;
int x ;
int y ;
int xa;
int ya;
int endline = 0;
bool blank=true;

// Timers
unsigned long timer = 0;
float timeStep = 0.01;

void setup() 
{
Serial.begin(9600);//115200
Serial2.begin(9600);
Serial2.setTimeout(100);

pinMode(MB2, OUTPUT);//left
pinMode(MB1, OUTPUT);
pinMode(MA1, OUTPUT);//right
pinMode(MA2, OUTPUT);
pinMode(LENCA,INPUT); // sets the Encoder_output_A pin as the input
pinMode(LENCB,INPUT); // sets the Encoder_output_B pin as the input
pinMode(RENCA,INPUT); // sets the Encoder_output_A pin as the input
pinMode(RENCB,INPUT); // sets the Encoder_output_B pin as the input
pinMode(speed2, OUTPUT);//speed2
pinMode(speed1, OUTPUT);//speed1
//digitalWrite(speed2, LOW);
//digitalWrite(speed1, LOW);

pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);

attachInterrupt(digitalPinToInterrupt(LENCA),encoderKiri,RISING);
attachInterrupt(digitalPinToInterrupt(RENCA),encoderKanan,RISING);

delay(5000);
}
