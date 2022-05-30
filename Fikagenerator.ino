#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        7 

int NUMPIXELS = 24; 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
 
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  randomSeed(analogRead(0));
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}
int a = 0;
int timeCount = 0;
int timeMax = random(60, 150);

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  int colorVar[5] = {pixels.Color(60, 120, 180), pixels.Color(200, 20, 20), pixels.Color(20, 200, 20), pixels.Color(20, 20, 200), pixels.Color(180, 120, 60)};


  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:

    if (i == NUMPIXELS - 1) {
      a++;
      if (a == 5) {
        a = 0;
      }
    }

    pixels.setPixelColor(i, colorVar[a]);


    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop

    timeCount++;

    if(timeCount == timeMax){
      exit(0)
    ;}
    
  }
}
