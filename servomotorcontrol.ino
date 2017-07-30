#include <Servo.h> // loading the servo library
int pos=0; 
int servopin = 9;
int servodelay = 25;
//int potpin = A0;// for using the potentiometer
//int potreading;// for using the potentiometer

Servo myPointer;

void setup() {

	//Serial.begin(9600); // for using the potentiometer
	myPointer.attach(servopin);
	
}

void loop() {
	//potreading = analogRead(potpin); // for using the potentiometer
	//pos = (155./1023.)*potreading; // for using the potentiometer

	for(pos=0; pos<=180; pos=pos+1) //defining the rotating angle from 0 to 180 degrees
	{
		myPointer.write(pos);
		delay(servodelay); //delay created
	}
	for(pos=180; pos>=0; pos=pos-1) //defining the rotating angle from 180 degrees to 0 degrees
	{
		myPointer.write(pos);
		delay(servodelay);
	}
}

