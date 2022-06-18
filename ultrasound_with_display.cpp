#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define WIDTH 128 // OLED display width, in pixels
#define HEIGHT 64 // OLED display height, in pixels

#define echoPin 5 
#define trigPin 6 

// defines variables
long duration; // variable for the duration of sound wave travel
double distance; // variable for the distance measurement
const double handle_length = 5;


Adafruit_SSD1306 display(WIDTH, HEIGHT, &Wire, -1);

void setup()
{
  Serial.begin(115200);
  //pin settup
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

  //display settup
  display.setTextSize(2); //font size
  display.setTextColor(WHITE);//font color
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { 
    Serial.println("SSD1306 allocation failed");
    for(;;); // Don't proceed, loop forever
  }

  delay(200);
  display.clearDisplay();
}


void loop() {
  // calculating distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  distance = distance/100;


  delay(100);


  // the display code
  display.setCursor(0,0);  
  display.print("Distance: ");
  display.setCursor(0,22);
  display.print(distance);
  display.print("m");
  display.setCursor(0,45);
  display.print(distance+handle_length);
  display.print("m");
  display.display();
  display.clearDisplay();
}
