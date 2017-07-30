#include <Servo.h>
Servo myservo; // create servo object to control a servo
int sensorOne=2; //digital pin 2 has connected to the resistor of first sensor
int sensorTwo=3; //digital pin 3 has connected to the resistor of second sensor
int inputOne=0; //variable to store the values from the analog pin 0
int inputTwo=1; //variable to store the values form the analog pin1
int currPos=0; // variable to store the servo position
void setup()
{
pinMode(sensorOne,OUTPUT); //initialize the digital pin as output
pinMode(sensorTwo,OUTPUT); //initialize the digital pin as output
digitalWrite(sensorOne,HIGH);
digitalWrite(sensorTwo,HIGH);
myservo.attach(9); // attaches the servo on pin 9 to the servo object
myservo.write(currPos); // tell servo to go to position in variable 'pos'
}
void loop()
{
int valueOne=analogRead(inputOne); //reads the value from the right sensor
int valueTwo=analogRead(inputTwo); //reads the value from the left sensor
int diff=valueOne-valueTwo; //difference of two values from the sensors
if(valueOne<950 || valueTwo<950) //if light is present
{
if(diff>=100) //if light source is towards right
{
currPos=currPos+2;
myservo.write(currPos); // tell servo to go to position in variable 'pos'
delay(30); // waits 30ms for the servo to reach the position
}
else if(diff<=-100) //if light source is towards left
{
currPos=currPos-2;
myservo.write(currPos); // tell servo to go to the defined position
delay(30); // delay of 30ms created
}
}
}
