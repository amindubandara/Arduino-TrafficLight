#include <Servo.h>


const int trigPin = 9;
const int echoPin = 8;
long duration;
int distance;
 
Servo myServo;//A gat
Servo myServo1;//B gate

void setup() {
  // put your setup code here, to run once:
myServo.attach(13);

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myServo1.attach(12);
  pinMode(3,OUTPUT);//A gate Green
   pinMode(4,OUTPUT);//A gate Red
   pinMode(5,OUTPUT); //B Red
   pinMode(6,OUTPUT);//B gren
 Serial.begin(9600);

}

void loop() {
  
distance = calculateDistance();
myServo1.attach(12);  
myServo.attach(13); 
myServo.write(0);
myServo1.write(90);

digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
    
delay(1000);

digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
    
myServo1.attach(12);  
myServo.attach(13);

myServo.write(0);
myServo1.write(0);




if ( distance <5)
{ myServo.attach(13);
myServo.detach();
myServo1.attach(12);
myServo1.detach();
myServo1.detach();


}
else {
  myServo.write(90);
  myServo.write(0);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}
Serial.println(distance);
}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
   //Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
