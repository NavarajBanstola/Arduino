#include <SD.h>                 //loading the SD card library
#include <SPI.h>                //loading the SPI library
#include <Adafruit_GPS.h>       //loading the adafruit GPS library
#include <SoftwareSerial.h>     //loading the serial library
SoftwareSerial mySerial(3,2);   //initializing the serial port
Adafruit_GPS GPS(&mySerial);    //Creating the object called GPS

String NMEA1; //Variable for first NMEA sentence
String NMEA2; //Variable for second NMEA sentence
char c;       //reading characters from GPS

int chipSelect = 4; //Connecting the chip select to arduino pin 4
File mySensorData;  //variable for SD card object

  
  void setup() {

 Serial.begin(115200);                          //Turn the serial monitor on
 GPS.begin(9600);                               //Define the GPS baud rate at 9600 baud
 GPS.sendCommand("$PGCMD,33,0*6D");             //Antenna nuisance data is turned off
 GPS.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ);    //Set update rate to 10 hertz
 GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); //RMC and GGA sentences are requested only
 delay(1000);
 
pinMode(10, OUTPUT);   //Declaring the pin 10 as an output for SD card
SD.begin(chipSelect);  //Initializing the SD card and be sure that it is connected to chipSelect

if(SD.exists("NMEA.txt")){ // Check to see if NMEA.txt is on the SD card, if so delete it
  SD.remove("NMEA.txt");
}
if(SD.exists("GPSData.txt")){ // Check to see if NMEA.txt is on the SD card, if so delete it
  SD.remove("GPSData.txt");
}
  
}

void loop() {
 
 readGPS(); //Function defined for reading two NMEA sentences from GPS

 if(GPS.fix==1){ //only log data after you have a fix
  mySensorDaata=SD.open("NMEA.txt",FILE_WRITE); //open text file NMEA.txt for writing
  mySensorData.println(NMEA1); //Write first sentence to the SD card
  mySensorData.println(NMEA2); //Write second sentence to the SD card
  mySensorData.close(); //Close the file

  mySensorData= SD.open("GPSData.txt",FILE_WRITE); //Open a text file named GPSData.txt on SD card
  /*mySensorData.print(GPS.latitude,4); //writing latitude on GPS file
  mySensorData.print(GPS.lat); //showing north or south hemisphere
  mySensorData.print(","); // Placing a comma between the latitude and longitude values
  mySensorData.print(GPS.longitude,4); //write longitude to the GPS file
  mySensorData.print(GPS.lon); //Showing the east or west hemisphere
  mySensorData.print(","); //placing the comma
  mySensorData.print(GPS.altitude); //Write altitude*/
  
  // the above code is used to see the value obtained in combined values for degrees and minutes 
  
  datadeg = float(int(GPS.longitude/100)); //obtaining only the degree part
  degDec = (GPS.longitude - datadeg*100)/60; //obtaining the fractional part of longitude
  deg = datadeg + degDec; // Gives the complete correct decimal form of longitude degrees
  if(GPS.lon=='W'){ //if you are in the western hemisphere then the value is negative
    deg= (-1)*deg;
  }
  mySensorData.print(deg,4); //writing decimal degree longitude value to SD card
  mySensorData.print(","); //placing comma 
  
  datadeg = float(int(GPS.latitude/100)); //obtaining only the degree part
  degDec = (GPS.latitude - datadeg*100)/60; //obtaining the fractional part of latitude
  deg = datadeg + degDec; // Gives the complete correct decimal form of latitude degrees
  if(GPS.lat=='S'){ // if you are in the southern, latitude the value should be negative
    deg= (-1)*deg;
  }
  mySensorData.print(deg,4); //writing decimal degree latitude value to SD card
  mySensorData.print(","); //Write comma to SD card

  mySensorData.print(GPS.altitude); //Gives the GPS altitide
  mySensorData.print(" "); //placing a single white space between two data

  mySensorData.close(); //close the file
 }

}
void readGPS()
{
  clearGPS();
  while(!GPS.newNMEAreceived()){ //Loop until a good NMEA sentence is obtained
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());      //Parse that last good NMEA sentence
  NMEA1=GPS.lastNMEA();

  while(!GPS.newNMEAreceived()){ //Loop until a good NMEA sentence is obtained
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());      //Parse that last good NMEA sentence
  NMEA2=GPS.lastNMEA();

  Serial.println(NMEA1);
  Serial.println(NMEA2);
  Serial.println("");
}

void clearGPS() //clear olda and corrupt data from serial port
{
  while(!GPS.newNMEAreceived()){ //Loop until a good NMEA sentence is obtained
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());      //Parse that last good NMEA sentence
  while(!GPS.newNMEAreceived()){ //Loop until a good NMEA sentence is obtained
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());      //Parse that last good NMEA sentence
  while(!GPS.newNMEAreceived()){ //Loop until a good NMEA sentence is obtained
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());      //Parse that last good NMEA sentence
}

