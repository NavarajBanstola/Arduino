//int count;
int redLED = 9;
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 1;

void setup()
{
	//count=0;
	pinMode(redLED,OUTPUT);
	// initialize the pushbutton pin as an input:
	pinMode(buttonPin, INPUT);
}

void loop()
{
	//count=count+1;
	//delay(100);
	// read the state of the pushbutton value:
	buttonState = digitalRead(buttonPin);
	
	// check if the pushbutton is pressed.
	// if it is, the buttonState is HIGH:
	if (buttonState == HIGH) {
		// turn LED on:
		digitalWrite(redLED, LOW);
	} else {
		// turn LED off:
		digitalWrite(redLED, HIGH);
	}
	
}

