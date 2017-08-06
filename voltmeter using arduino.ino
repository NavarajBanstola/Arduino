int potpin=A0;
int readvalue;
float voltage;

void setup() {
	// put your setup code here, to run once:
	pinMode(potpin,INPUT);
	Serial.begin(9600);
}

void loop() {
	// put your main code here, to run repeatedly:
	readvalue = analogRead(potpin);
	voltage = (5./1023.)*readvalue;
	Serial.println(voltage);
	delay(250);
}
