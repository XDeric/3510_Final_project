// Eric Mei Light Show

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

//random variables
long random_n, random_n1, random_n2;

//ping sensor variables
long unsigned int duration = 0, inches = 0, cm = 0;

void setup() {
 Serial.begin(115200); //Communication Speed for monitor

 //starts the sensor
 pinMode(TRIG, OUTPUT); // Trigger Pin 
 pinMode(ECHO, INPUT);  // Echo pin 
 
 randomSeed(analogRead(5));// analog pin not in use, it's to help start with a random number 
 // Setting time
 setTime(8,45,0,12,5,16);  //hours, minutes, seconds, days, months, years
 
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
 if (cm <= 5) // display light show 1 if object less than 5 inches away
  {
    Serial.print("5 cm away");
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.setCursor(1, 0); // start at top left, with one pixel of spacing
    matrix.print("5 cm");
    delay(1000); 
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.setCursor(1, 0); // start at top left, with one pixel of spacing
    matrix.print("5 cm");
    delay(100); 
    
    //Walking Stick_Man phase 1
    
    matrix.fillCircle(5, 10, 3, matrix.Color333(1, 1, 1)); //white Head
    //
    matrix.drawLine(5, 13, 5, 20, matrix.Color333(1, 1, 1));//body
    //
    matrix.drawLine(5, 14, 2, 16, matrix.Color333(1, 1, 1));//R_arm
    //
    matrix.drawLine(2, 16, 2, 20, matrix.Color333(1, 1, 1));//R_arm
    //
    matrix.drawLine(5, 13, 6, 16, matrix.Color333(1, 1, 1));//L_arm
    //
    matrix.drawLine(6, 16, 9, 19, matrix.Color333(1, 1, 1));//L_arm
    //
    matrix.drawLine(5, 21, 4, 23, matrix.Color333(1, 1, 1));//R_leg
    //
    matrix.drawLine(4, 23, 3, 29, matrix.Color333(1, 1, 1));//R_leg
    //
    matrix.drawLine(5, 21, 7, 23, matrix.Color333(1, 1, 1));//L_leg
    //
    matrix.drawLine(7, 23, 7, 29, matrix.Color333(1, 1, 1));//L_leg
    delay(100);
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0)); //clear
    
    //Walking Stick_Man phase 2
    
    matrix.fillCircle(5, 10, 3, matrix.Color333(1, 1, 1)); //white Head
    //
    matrix.drawLine(5, 13, 5, 20, matrix.Color333(1, 1, 1));//body
    //
    matrix.drawLine(5, 15, 3, 15, matrix.Color333(1, 1, 1));//R_arm
    //
    matrix.drawLine(3, 15, 6, 20, matrix.Color333(1, 1, 1));//R_arm
    matrix.drawPixel(4, 16, matrix.Color333(0, 0, 0)); //Edit
    matrix.drawPixel(3, 16, matrix.Color333(1, 1, 1)); //Edit
    matrix.drawPixel(3, 15, matrix.Color333(0, 0, 0)); //Edit
    //
    matrix.drawLine(5, 14, 6, 16, matrix.Color333(1, 1, 1));//L_arm
    //
    matrix.drawLine(6, 16, 8, 20, matrix.Color333(1, 1, 1));//L_arm
    //
    matrix.drawLine(5, 21, 7, 23, matrix.Color333(1, 1, 1));//R_leg
    //
    matrix.drawLine(7, 23, 2, 28, matrix.Color333(1, 1, 1));//R_leg
    //
    matrix.drawLine(5, 21, 5, 29, matrix.Color333(1, 1, 1));//L_leg
    //
    delay(100);
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0)); //clear
    
    //Walking Stick_Man phase 3
    
    matrix.fillCircle(5, 10, 3, matrix.Color333(1, 1, 1)); //white Head
    //
    matrix.drawLine(5, 13, 5, 20, matrix.Color333(1, 1, 1));//body
    //
    matrix.drawLine(5, 15, 3, 15, matrix.Color333(1, 1, 1));//R_arm
    matrix.drawPixel(3, 15, matrix.Color333(0, 0, 0)); //Edit
    //
    matrix.drawLine(3, 16, 3, 20, matrix.Color333(1, 1, 1));//R_arm
    //
    matrix.drawLine(5, 13, 6, 16, matrix.Color333(1, 1, 1));//L_arm
    //
    matrix.drawLine(6, 16, 8, 19, matrix.Color333(1, 1, 1));//L_arm
    //
    matrix.drawLine(5, 21, 4, 23, matrix.Color333(1, 1, 1));//R_leg
    //
    matrix.drawLine(4, 23, 3, 28, matrix.Color333(1, 1, 1));//R_leg
    //
    matrix.drawLine(5, 21, 6, 23, matrix.Color333(1, 1, 1));//L_leg
    //
    matrix.drawLine(7, 24, 4, 28, matrix.Color333(1, 1, 1));//L_leg
    delay(100);
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0)); //clear
    
    //Walking Stick_Man phase 4
    
    matrix.fillCircle(5, 10, 3, matrix.Color333(1, 1, 1)); //white Head
    //
    matrix.drawLine(5, 13, 5, 20, matrix.Color333(1, 1, 1));//body
    //
    matrix.drawLine(4, 16, 4, 19, matrix.Color333(1, 1, 1));//R_arm
    //
    matrix.drawLine(5, 15, 7, 20, matrix.Color333(1, 1, 1));//L_arm
    matrix.drawPixel(7, 19, matrix.Color333(0, 0, 0)); //Edit
    //
    matrix.drawLine(5, 21, 4, 23, matrix.Color333(1, 1, 1));//R_leg
    //
    matrix.drawLine(4, 23, 4, 29, matrix.Color333(1, 1, 1));//R_leg
    //
    matrix.drawLine(5, 21, 7, 23, matrix.Color333(1, 1, 1));//L_leg
    //
    matrix.drawLine(7, 23, 7, 27, matrix.Color333(1, 1, 1));//L_leg
    delay(100);
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0)); //clear
    delay(100);
  }
  
  else if ( cm > 5 && cm < 15) // circle light show for 5-15 inches away
    {
    matrix.setTextColor(matrix.Color333(7,0,0));
    matrix.setCursor(1, 0); // start at top left, with one pixel of spacing
    matrix.print("10 cm");
    delay(1000);
    random_n = random(7); // to generate random number 0-7 color
    random_n1 = random(7); // to generate random number 0-7 color
    random_n2 = random(7); // to generate random number 0-7 color
    //circle in middle
    matrix.fillCircle(16, 18, 8, matrix.Color333(random_n, random_n1, random_n2));
    delay(200);
    matrix.fillCircle(16, 18, 8, matrix.Color333(random_n1, random_n, random_n2));
    delay(200);
    matrix.fillCircle(16, 18, 8, matrix.Color333(random_n2, random_n1, random_n));
    delay(200);
    // circle around
    matrix.fillCircle(5, 15, 2, matrix.Color333(random_n, random_n2, random_n1));
    delay(200);
    matrix.fillCircle(5, 15, 2, matrix.Color333(0, 0, 0));
    delay(200);
    matrix.fillCircle(6, 22, 2, matrix.Color333(random_n1, 1, 1));
    delay(200);
    matrix.fillCircle(6, 22, 2, matrix.Color333(0, 0, 0));
    delay(200);
    matrix.fillCircle(16, 29, 2, matrix.Color333(0, 1, random_n2));
    delay(200);
    matrix.fillCircle(16, 29, 2, matrix.Color333(0, 0, 0));
    delay(200);
    matrix.fillCircle(26, 22, 2, matrix.Color333(random_n, 1, 1));
    delay(200);
    matrix.fillCircle(26, 22, 2, matrix.Color333(0, 0, 0));
    delay(200);
    matrix.fillCircle(27, 15, 2, matrix.Color333(0, random_n1, 1));
    delay(200);
    matrix.fillCircle(27, 15, 2, matrix.Color333(0, 0, 0));
    delay(200);
    matrix.fillCircle(16, 7, 2, matrix.Color333(random_n1, 0, random_n2));
    delay(200);
    matrix.fillCircle(16, 7, 2, matrix.Color333(0, 0, 0));
    delay(200);
    matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 0)); //clear
    delay(200);
    }
  
  else{ // returns to telling time
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

