#include "Wire.h"               // importing the wire library to talk over I2C
#include "Adafruit_BMP085.h"    //importing the pressure sensor library from adafruit
Adafruit_BMP085 mySensor;       //Creating the sensor object called mySensor

float tempC;                    //variable for temperature in degree celcius
float tempF;                    //variable for temperature in degree fahrenheit
float pressure;                 //variable for measuring the pressure
float pressureHG;               //variable for pressure in mmHG or Torr
int chipSelect=4;               //setting the chip select
File mySensorData;              //variable for working with file object

void setup() {
 Serial.begin(9600);            //Serial monitor is started
 mysensor.begin();              //initializing the sensor

 pinMode(10,OUTPUT);            //reserving the pin10 as output
 SD.begin(chipSelect);          //initializing the chipselect
 

}

void loop() {
 tempC = mySensor.readTemperature();  // reading the temperature
 tempF = tempC*1.8+32.;               //converting celcius to fahrenheit
pressure = mySensor.readPressure();   //reading pressure
pressureHG = pressure*0.00750061683;  //converting pressure from pascal to Torr(mmHG)
mySensorData = SD.open("LoggedData.txt", FILE_WRITE); //opening a text file named LoggedData on a SDcard to write to

if(mySensorData)
{
  Serial.print("The temperature is: "); //print the results
  Serial.print(tempF);
  Serial.println("The pressure is: ");
  Serial.print(pressureHG);
  Serial,print(" mmHG. ");
  Serial.println("");
  delay(500);                           //creating the delay between the results

  mySensorData.print(tempF);            //write temperature in the SD card
  mySensorData.print(",");              //putting a comma to separate temperature and pressure
  mySensorData.println(pressureHG);       //print the pressure on the next line
  mySensorData.close();                 //close the file
  
  
}
}
