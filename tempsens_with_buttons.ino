// Authors: Margaret Flemings, Shanzay Kazmi, and Rachel Pak
// Adapted code from github, class examples, and Neopixel library


// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
const int potPin = A0;
int led1 = 0;
int led2 = 1;
int led3 = 2;


// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // delay for half a second
const int temperaturePin = 0;

void setup()
{  
  Serial.begin(9600);
  //set up the pulsometer and lights
  // can be used to measure pain 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
  pixels.begin(); // This initializes the NeoPixel library.

}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814); 
}

void loop() {
  
  int rawValue = analogRead(potPin);
  Serial.println(rawValue);
  
  int numLEDs = rawValue * 4 / 1010;
  Serial.println(numLEDs);
  
  if (numLEDs > 0){
    digitalWrite(led1, HIGH);
  }
  if (numLEDs > 1){
    digitalWrite(led2, HIGH);
  }
  if (numLEDs > 2){
    digitalWrite(led3, HIGH);
  }

  delay(100);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  // read the temperature from the sensor on the Bean
  int degreesF = Bean.getTemperature();
  Serial.println(degreesF);

  // initial rgb set to 0,0,0
    int r = 0;
    int g = 0; 
    int b = 0; 

   //map or divide/sub 255
   //red
  if (degreesF > 27) {
    r = 255;
    g = 0;
    b = 0;
    Serial.print("r = ");
    Serial.println(r);
    //pink
  } else if (degreesF > 26) {
    r = 255;
    g = 75;
    b = 75;
    Serial.print("r = ");
    Serial.println(r);
    white
  } else if (degreesF > 24) {
    r = 255;
    g = 255;
    b = 255;
    Serial.print("r = ");
    Serial.println(r);
  } else {
    r = 255;
    g = 255;
    b = 255;
    Serial.print("r = ");
    Serial.println(r);
  }

//  set up neopixels to light up in a circle
  for(int i=0;i<NUMPIXELS;i++){
    
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.setBrightness(100);
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
 }
