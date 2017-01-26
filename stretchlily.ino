#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

const int sensorPin   = A5 ; 

const int BUTTON_PIN     =  2 ;  // The number of the pushbutton pin
const int NEOPIXEL_PIN   =  6 ;  // The number of the LED pin
const int NUMPIXELS      = 30 ;  // The number of LEDs in the LED strip.




int sensorValue;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // This initializes the NeoPixel library.
   strip.show(); // Initialize all pixels to 'off'
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Initialize the pushbutton pin as an input 
                                     // and high by default.
  Serial.begin(9600); // initialize serial communications at 9600 bps:
  pinMode(6,OUTPUT);
}

void loop() {  
  
   sensorValue = analogRead(sensorPin);
   sensorValue=sensorValue-400;
   sensorValue=sensorValue/6;
   if (sensorValue<0)  sensorValue=0;
   if (sensorValue>30)  sensorValue=30;
   
   
   
   
   Serial.println(sensorValue);
  
  
  
  
  
 
  for( int pixel = 0 ; pixel < sensorValue ; pixel++ ) {    
   strip.setPixelColor(pixel,255,255,255); 
  }
  for( int pixel = sensorValue ; pixel < NUMPIXELS ; pixel++ ) {    
   strip.setPixelColor(pixel,0,0,0); 
  }
  strip.show(); // This sends the updated pixel color to the hardware.
}







