#define trigPin 7
#define echoPin 6
#define buzzer 3
#include <Servo.h>
int sound = 250;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
 int tempo = 1;
int poten1 = 0;
int poten2 = 1;
int poten3 = 2;
int poten4 = 3;
int val1;
int val2;
int val3;
int val4;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  myservo1.attach(11);
  myservo2.attach(10);
  myservo3.attach(9);
  myservo4.attach(8);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance >= 30) {
    sound = 250;
  }

  if (distance < 25) {
      sound = 260;
  }
  if (distance < 20) {
      sound = 270;
}
  if (distance < 15) {
    sound = 280;
}
  if (distance < 10) {
     sound = 290;
}
  if (distance < 5) {
    sound = 300;
}
 
  if (distance > 30 || distance <= 0){
    Serial.println("Out of range");
    noTone(buzzer);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);
   
  }
  delay(500);
   val1 = analogRead(poten1);
  val2 = analogRead(poten2);
  val3 = analogRead(poten3);
  val4 = analogRead(poten4);
  val1 = map(val1, 0, 1080, 0, 180);
  val2 = map(val2, 0, 1080, 0, 180);
  val3 = map(val3, 0, 1080, 0, 180);
  val4 = mpa(val4, 0, 1080, 0, 180);
  myservo1.write(val1);
  myservo2.write(val1);
  myservo3.write(val2);
  myservo4.write(val4);
  delay(tempo);                         
}