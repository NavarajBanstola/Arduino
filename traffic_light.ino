
/*pad and color for padestrians lights and veh and color for vehicle lights*/
int padred = 3; //pin defined for red light on or off for the padestrians
int padyellow = 5; //pin defined for yellow light on or off for the padestrians
int padgreen = 6;  //pin defined for green light on or off for the padestrians
int vehred = 12;  //pin defined for red light on or off for the vehicles
int vehyellow = 4;  //pin defined for yellow light on or off for the vehicles
int vehgreen = 2;  //pin defined for green light on or off for the vehicles

void setup() {
	
	pinMode(padred,OUTPUT);
	pinMode(padyellow,OUTPUT);
	pinMode(padgreen,OUTPUT);
	pinMode(padred,OUTPUT);
	pinMode(padyellow,OUTPUT);
	pinMode(padgreen,OUTPUT);
}

void loop() {
	
	digitalWrite(padgreen,HIGH); //padestrians light is turned green
	digitalWrite(vehred,HIGH); // whereas the vehicle light is turned red
	delay(11000);               // delay created of 11 seconds
	digitalWrite(padgreen,LOW); //padestrians green light is turned off
	digitalWrite(padyellow,HIGH);// padestrians yellow light is turned on
	delay(3000);                  // a delay of 3 seconds is made
	digitalWrite(padyellow,LOW);  //yellow light is turned off
	digitalWrite(padred,HIGH);     // red light for padestrian is turned on
	delay(2000);
	digitalWrite(vehred,LOW);     // red light for vehicle is turned off and green light turned on
	digitalWrite(vehyellow,HIGH);
	delay(1000);
	digitalWrite(vehyellow,LOW);
	digitalWrite(vehgreen,HIGH);
	delay(4000);
	digitalWrite(vehgreen,LOW);
	digitalWrite(vehyellow,HIGH);
	delay(3000);
	digitalWrite(vehyellow,LOW);
	digitalWrite(vehred,HIGH);
	delay(2000);
	digitalWrite(padred,LOW);
	delay(1000);
	digitalWrite(vehred,LOW);
}
