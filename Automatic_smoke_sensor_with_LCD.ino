/*Automatic smoke detector for detecting the smoke using the smoke sensor and the Arduino */
#include <LiquidCrystal.h> // defining the liquid crystal display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define buzzer 9  // defining the pin for alarm
#define sensor A0    //defining pins for sensor
#define load_Res 10    defining the value of load resistor
#define air_factor 9.83  //defining the constant value of air_factor
                                                    
float SmokeCurve[3] ={2.3,0.53,-0.44};    // (x, y, slope) x,y coordinate of one point and the slope between two points
                                                                                        
float Res=0;                
void setup()
{   
  lcd.begin(16,2);  //LCD initialized
  lcd.print("Calibrating.....");                
  Res = SensorCalibration();         //calibrating the sensor                                                                                 
  lcd.print("Calibration done.");    //showing the status of the calibration
  lcd.setCursor(0,1);                 // setting the cursor position for the display
  lcd.print("Res=");
  lcd.print(Res);
  lcd.print("kohm");
  delay(2000);  //making the delay of 2 seconds
  lcd.clear();  // data is cleared after the delay
  pinMode(buzzer, OUTPUT); 
}
void loop()
{  
   lcd.setCursor(0,0); // again setting the cursor position for display
   lcd.print("SMOKE:"); 
   float res=resistance(5,50);
   res/=Res;
   int result=pow(10,(((log(res)-SmokeCurve[1])/SmokeCurve[2]) + SmokeCurve[0])); // calculating the result
   lcd.print(result);
   lcd.print( " ppm        ");
   if(result>1000)
   {
      digitalWrite(buzzer, HIGH); // comparing the value of the result and if greater than 1000 then the buzzer is turned on
      delay(2000); // creating a delay of 2 seconds
   }
   else
   digitalWrite(buzzer, LOW); // while compaing if the value is less than 1000 then the buzzer is turned off
   delay(500);
}
float resistance(int samples, int interval) //defining a function for the value of resistance
{
   int i;
   float res=0; 
   for (i=0;i<samples;i++) 
   {
      int adc_value=analogRead(sensor); //converting the analog sensor value to digital
      res+=((float)load_Res*(1023-adc_value)/adc_value);
      delay(interval);
   }
   res/=samples;
   return res;
}
 
 
float SensorCalibration() // defining the function for the calibration of the sensor
{
  int i;
  float val=0;    
  val=resistance(50,500);                
  val = val/air_factor;  
  return val; 
}
