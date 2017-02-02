#include <Servo.h>
#include <NewPing.h> 

#define EnableServo 12
#define BuzzerPin 4
#define ButtonPin 2
#define Red 3
#define PING_TRIGGER 5 //yellow
#define PING_ECHO 6 //green
#define MAX_DISTANCE 200

#define RF_OFFSET 15

NewPing sonar(PING_TRIGGER, PING_ECHO, MAX_DISTANCE);

Servo Lleg;  // create servo object to control a servo 
Servo Rleg;
Servo Lfoot;
Servo Rfoot;

//constantes para posição central
int LLcenter = 80;  //gira o pé esquerdo sentido anti-horário(referência de pé)
int RLcenter = 80;  //gira o pé direito sentido anti-horário
int LFcenter = 95; //abaixa o pé esquerdo
int RFcenter = 80; //levanta o pé direito

int tAngle = 30; //tilt angle
int uAngle = 35; //turn angle
int sAngle = 35; //swing angle

void setup(){
  Lleg.attach(11);  // attaches the servo on pin x to the servo object 
  Rleg.attach(10);  // attaches the servo on pin x to the servo object 
  Lfoot.attach(8);  // attaches the servo on pin x to the servo object 
  Rfoot.attach(9);  // attaches the servo on pin x to the servo object 

  pinMode(EnableServo,OUTPUT); 
  digitalWrite(EnableServo,HIGH); //this turns on the power to the servos
  CenterServos(); //center the servos
  delay(500);
  digitalWrite(EnableServo,LOW); //turn power off after centering
  
  pinMode(BuzzerPin, OUTPUT);
  digitalWrite(BuzzerPin, LOW);
  //Buzzer.PlayMelody();
  
  pinMode(ButtonPin, INPUT);
  digitalWrite(ButtonPin, HIGH); //pull up activated
  
  Serial.begin(19200);
  Serial.print("Ready");

  //while (digitalRead(ButtonPin) != LOW){ 
    //do nothing until the button pressed
  //}
  BuzzerBeep();
  pinMode(13, OUTPUT);
}

// 4 vermelho
// 7 branco verde amarelo laranja

void loop(){
  //CenterServos();
  dance();
}



int getDistance() {
  int distance = 0;

  for (int i = 0; i < 10; ++i) {
    delay(10);
    if (distance = sonar.ping_cm())
      return distance;
  }
  return -1;
}

void repeat(int times, void (*func)(), int interval) {
  while (times--) {
    func();
    delay(interval);
  }
}

void dance() {
  /*
  repeat(1, leftStep, 300);
  repeat(1, rightStep, 300);
  repeat(1, rightTap, 200);
  repeat(1, leftTap, 200);
  */
  leftHead();
  rightHead();
  //CenterServos();
}


int stepPrecision = 1;
int stepBackPrecision = 5;

void leftStep() {
  int ang = 20;
  int sp = 30;
  //tilt right up
  for (int i=0; i<=ang; i+=stepPrecision){
    Lfoot.write(LFcenter+i);
    delay(sp);
  }
  Lfoot.write(LFcenter);
}

void leftTap() {
  int ang = 20;
  int sp = 30;
  //tilt left up
  //tilt left down
  for (int i=0; i<ang; i+=stepPrecision){
    Lfoot.write(LFcenter-i);
    delay(sp);
  }
  Lfoot.write(LFcenter);
}


void rightStep() {
  int ang = 20;
  int sp = 30;
  //tilt right up
  for (int i=0; i<=ang; i+=stepPrecision){
    Rfoot.write(RFcenter-i);
    delay(sp);
  }
  Rfoot.write(RFcenter);
}

void rightTap() {
  int ang = 20;
  int sp = 30;
  //tilt left up
  //tilt left down
  //tilt right down
  for (int i=0; i<ang; i+=stepPrecision){
    Rfoot.write(RFcenter+i);
    delay(sp);
  }
  Rfoot.write(RFcenter);
}

void leftHead(){
  int ang = 20;
  int sp = 30;
  for (int i=0; i<=ang; i+=stepPrecision){
    Lleg.write(LLcenter+i);
    Rleg.write(RLcenter+i);
    delay(sp);
  }
  Lleg.write(LLcenter);
  Rleg.write(RLcenter);
  for (int i=ang; i>0; i-=stepPrecision){
    Lleg.write(LLcenter+i);
    Rleg.write(RLcenter+i);
    delay(sp);
  }
  Lleg.write(LLcenter);
  Rleg.write(RLcenter);
}

void rightHead(){
  int ang = 20;
  int sp = 30;
  for (int i=0; i>(-ang); i-=stepPrecision){
    Lleg.write(LLcenter+i);
    Rleg.write(RLcenter+i);
    delay(sp);
  }
  Lleg.write(LLcenter);
  Rleg.write(RLcenter);
  for (int i=(-ang); i<0; i+=stepPrecision){
    Lleg.write(LLcenter+i);
    Rleg.write(RLcenter+i);
    delay(sp);
  }
  Lleg.write(LLcenter);
  Rleg.write(RLcenter);
}

void twerkIt() {
  
}


int sensible_distance = 10;

void turnAroundObstacle(){
  int distance = getDistance();
  if (distance < 0) {
    delay(1000);
    return;
  }
  
  if (distance < sensible_distance)
    TurnLeft(2, 30);

  distance = getDistance();
  if (distance < sensible_distance) {
    delay(1000);
    return;
  }

  if (distance < sensible_distance)
    TurnRight(4, 30);
}

void IR38Write(byte LedPin) {
  for(int i = 0; i <= 384; i++) { //10ms burst of 38kHz signal
    digitalWrite(LedPin, HIGH);
    delayMicroseconds(13);
    digitalWrite(LedPin, LOW);
    delayMicroseconds(13);
  }
}

void CenterServos() 
{ 
    Lleg.write(LLcenter);              // tell servo to go to position in variable 'center' 
    Rleg.write(RLcenter);              // tell servo to go to position in variable 'center' 
    Lfoot.write(LFcenter);              // tell servo to go to position in variable 'center' 
    Rfoot.write(RFcenter);              // tell servo to go to position in variable 'center' 
    delay(100);                     // waits 100ms for the servos to reach the position 
}

void BuzzerBeep(){
    digitalWrite(BuzzerPin, HIGH);
    delay(100);
    digitalWrite(BuzzerPin, LOW);
}



void adjust() {
    
  /*
  //check for obstacles, if none, go Forward, if found, turn the other way
  delay(beat);
  //BuzzerBeep();
  delay(beat/2);
  CenterServos();
  //turnAroundObstacle();
  dance();
  CenterServos();
  delay(beat/2);
  CenterServos();
 
  if (getDistance() > 30)
    Forward(1, 30);
    */

  //Serial.println(getDistance());

  int interval = 2000;

  long previousMillis = millis(); 
  unsigned long currentMillis;
 
  while((currentMillis = millis()) - previousMillis <= interval) {
    // save the last time you blinked the LED 
    Lfoot.write(LFcenter);
    Rfoot.write(RFcenter);
    Lleg.write(LLcenter);
    Rleg.write(RLcenter);

    delay(10);
  }

  for (int i=0; i<=40; i+=5){
    Lfoot.write(LFcenter+i);
    Rfoot.write(RFcenter-i);
    delay(30);
  }

  

  delay(100);

  for (int i=0; i<=40; i+=1){
    Lleg.write(LLcenter+i);
    Rleg.write(RLcenter-i);
    delay(30);
  }

  for (int i=40; i>=0; i-=5){
    Lleg.write(LLcenter+i);
    Rleg.write(RLcenter-i);
    delay(30);
  }

  delay(100);

  /*
  for (int i=0; i<=40; i+=5){
    Lfoot.write(LFcenter+i);
    Rfoot.write(RFcenter-i);
    delay(30);
  }
  delay(300);
  Lfoot.write(LFcenter);
  Rfoot.write(RFcenter);
  
  delay(300);
  */
}
