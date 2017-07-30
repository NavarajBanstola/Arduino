void setup() {

	pinMode(13,OUTPUT); //pin 13 defined as output
	digitalWrite(13,LOW);
	Serial.begin(9600); //baud rate defined at 9600 for serial communication
	
}

void loop() {

	if(Serial.available()>0)
	{
		char letter = Serial.read();
		if(letter == '1')
		{
			digitalWrite(13,HIGH);
			Serial.println("The LED is ON");
		}
		else if(letter == '0')
		{
			digitalWrite(13,LOW);
			Serial.println("The LED is OFF");
		}
	}
}
