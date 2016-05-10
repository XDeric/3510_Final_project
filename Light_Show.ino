// Eric Mei Alarm Project

#include <Adafruit_GFX.h>   //AdaFruit Core graphics library
#include <RGBmatrixPanel.h> //AdaFruit Hardware-specific library
#include <TimeLib.h> // Arduino Time library
#include <TimeAlarms.h> // Arduino Time library

// Pinout for 32x32 matrix
#define CLK 11  
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
// Pinout for pingsensor
#define TRIG  2 // Trigger connected to Pin #2
#define ECHO  3 // Echo connected to Pin #3
#define PULSE 5 // Milliseconds high
#define Pause 2 // Pause before pulsing

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

//ping sensor variables
long unsigned int duration = 0, inches = 0, cm = 0;

void setup() {
 Serial.begin(115200); //Communication Speed for monitor
 
 //starts the sensor
 pinMode(TRIG, OUTPUT); /* Trigger Pin */
 pinMode(ECHO, INPUT); /* Echo pin */
 
 // Setting time
 setTime(7,1,0,10,5,16);  //hours, minutes, seconds, days, months, years
 
 matrix.begin();
 matrix.drawPixel(0, 0, matrix.Color333(7, 7, 7)); // First led is white
 delay(500);
 matrix.fillScreen(matrix.Color333(0, 0, 0)); // Clear screen
  
 matrix.setCursor(1, 0);    // start at top left, with one pixel of spacing
 matrix.setTextSize(1);     // size 1 == 8 pixels high
 matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
 matrix.setTextColor(matrix.Color333(0,4,7)); 
 matrix.println("Start");
 delay(500); //1/2 sec delay
 matrix.fillScreen(matrix.Color333(0, 0, 0)); //clear screen
}
void loop() 
 {
 //Ping sensor loop
 digitalWrite(TRIG, LOW); // Ensure pin is LOW 
 delayMicroseconds(Pause); // Pause 
 digitalWrite(TRIG, HIGH); // Trigger HIGH 
 delayMicroseconds(PULSE); // HIGH Pulse Pause  
 digitalWrite(TRIG, LOW); // Trigger LOW 
 delayMicroseconds(Pause); // Pause 

 // Listen for an echo on ECHO pin 
 duration = pulseIn(ECHO, HIGH); // Time signal on echo pin 
 Serial.print(" \nDuration = ");
 Serial.println(duration, DEC);
  
 // Convert the time into a distance
 inches = ((duration / 74) / 2); // Distance in inches
 cm = ((duration / 29) / 2); // Distance in cm
 // Print output into serial monitor
 Serial.print(" \n Distance in inches = ");
 Serial.println(inches, DEC);
 Serial.print(" Distance in cm = ");
 Serial.println(cm, DEC);
 delay(10 * Pause); // Pause before next pulse
 
 //light Show 
 if (cm <= 5) // display light show 1 if object less than 5 cm away
  {
    Serial.print("5 cm away");
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.setCursor(1, 0); // start at top left, with one pixel of spacing
    matrix.print("5 cm");
    delay(1000); 
    matrix.fillRect(0, 10, 32, 32, matrix.Color333(0, 0, 0)); //black
    delay(100);
    matrix.fillRect(0, 10, 32, 32, matrix.Color333(1, 0, 0)); //Red
    delay(100);
    matrix.fillRect(0, 10, 32, 32, matrix.Color333(1, 1, 0)); //Yellow
    delay(100);
    matrix.fillRect(0, 10, 32, 32, matrix.Color333(0, 0, 1)); //Blue
    delay(100);
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0)); //clear
    delay(100);
  }
  else if ( cm > 5 && cm < 15)
    {
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.setCursor(1, 0); // start at top left, with one pixel of spacing
    matrix.print("10 cm");
    delay(1000);
    matrix.fillCircle(16, 18, 10, matrix.Color333(1, 0, 1)); //Purple
    delay(100);
    matrix.fillCircle(16, 18, 10, matrix.Color333(0, 1, 0)); //Green
    delay(100);
    matrix.fillCircle(16, 18, 10, matrix.Color333(7, 1, 0)); //Orange
    delay(100);
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0)); //clear
    delay(100);
    }
  else{
    //Displays in Serial Monitor
    Serial.print(month()); // this display the month/day/year format
    Serial.print("/");
    Serial.print(day());
    Serial.print("/");
    Serial.println(year());
    Serial.print(hour()); //display time hour:minute:second format
    Serial.print(":");
    Serial.print(minute());
    Serial.print(":");
    Serial.println(second());
    delay(1000); //1 sec delay
    
    //Display time on 32x32 matrix
    matrix.setCursor(1, 0);    // start at top left, with one pixel of spacing
    matrix.setTextSize(1);     // size 1 == 8 pixels high
    matrix.setTextWrap(true); // Wrap at end of line
     
    matrix.setTextColor(matrix.Color333(1,1,1)); // White text
    matrix.print(month()); // this display the month/day/year format
    matrix.print('|');
    matrix.print(day());
    matrix.print('|');
    matrix.println(year());
    matrix.print(hour()); //display time hour:minute:second format
    matrix.print(':');
    matrix.print(minute());
    matrix.print(':');
    matrix.println(second());
    delay(1000); //1 sec delay
    matrix.fillScreen(matrix.Color333(0, 0, 0)); //fill screen black*/
  }
 }


