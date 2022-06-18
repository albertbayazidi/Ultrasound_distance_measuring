# Ultrasound distance measuring

This code is used with a ultrasound sensor, arduino pro micro, and a small OLED screen.
Remember to download the necessary libraries. This can be done in the arduino software or manually. Links can be found [Here](https://github.com/adafruit/Adafruit_SSD1306) for the adafruit_SSD1306.h and [Here](https://github.com/adafruit/Adafruit-GFX-Library) for the adafruit_GFX.h


### Functionality
The sensor is activated with a 10 µs pulse. The result of this is a soundwave that travels the distance we want to measure twice. 
We measure the time it takes for the sound to travel this distance. As a result of this we have to divide by 2.     

### Usage
This can be used to take rough measurements of small rooms   
