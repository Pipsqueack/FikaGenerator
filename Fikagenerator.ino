#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        7 
int NUMPIXELS = 24; 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Här definaras hur snabbt ljuslamporna ska lysas upp
#define DELAYVAL 50 

//Setup funktion med huvudsyfte att sätta igång neopixeln samt att slumpa fram ett randomSeed som används i void loop.
void setup() {
 
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  randomSeed(analogRead(0));
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

//Definerar hur länge ljusen kommer att rotera, i detta fall kommer 60-150 pixlar lysa upp.
int a = 0;
int timeCount = 0;
int timeMax = random(60, 150);


//Lyser upp pixlarna och roterar färger utefter vilket värde timeMax fick av random(). 
void loop() {
  pixels.clear(); 
  int colorVar[5] = {pixels.Color(60, 120, 180), pixels.Color(200, 20, 20), pixels.Color(20, 200, 20), pixels.Color(20, 20, 200), pixels.Color(180, 120, 60)};


  for (int i = 0; i < NUMPIXELS; i++) { 

    if (i == NUMPIXELS - 1) {
      a++;
      if (a == 5) {
        a = 0;
      }
    }

    pixels.setPixelColor(i, colorVar[a]);
    pixels.show();

    delay(DELAYVAL); 

    timeCount++;

    if(timeCount == timeMax){
      exit(0)
    ;}
    
  }
}
