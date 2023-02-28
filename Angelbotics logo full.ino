#include <FastLED.h>
#include <math.h>

// the id of the location on the arduino that the light is connected to
#define LED_PIN     13
// total number of leds
#define NUM_LEDS    558

#define RAND_MAX = 11

// this sets the color type, in this case RGB, which takes values for how much RED, GREEN and BLUE to light up, in the range 1 - 255.
CRGB leds[NUM_LEDS];

// this are the ids of all the bulbs in the letters. there are 57 bulbs in a, 66 in letter n (57 + 66 = 123), and so on.
int letters[12] = {0, 57, 123, 176, 223, 262, 329, 401, 443, 473, 520, 557};
int numbers[11] = {5, 11, 12, 2, 4, 6, 8, 3, 7, 9, 10};
int red = 250;
int green = 100;
int blue = 8;

void setup() {
  // telling the code what light strip its running the code on
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS);
}

// turns off the lights
void turnoff() {
  for(int i = 0; i <= 558; i++) {
      leds[i] = CRGB(0,0,0);
  }
}

// these are functions for patterns
// slide pattern slides two letters across. the parameter N determines how many times the pattern runs
void slidepattern(int N) {
  // loop running it the specified number of times
  for(int A = 0; A <= (N - 1); A++) {
    // loop running for each letter
    for(int I = 0; I <= 9; I++) {
      // loop running to turn off the whole thing
      // turns all the lights off
      turnoff();
      // loop running lighting up each bulb in thhe letter
      for(int i = letters[I]+1; i <= letters[I+2]; i++) {
        // the yellow color you see
        leds[i] = CRGB(red,green,blue);
      }
      // displays the changes
      FastLED.show();
      
      // self explanitory
      delay(100);
    }

    // turns everything off again
    turnoff();
    FastLED.show();
  }
}

// progression pattern lights up the letters in a line till they are all lit up then resets
// works mostly like the others
void progressionpattern(int N) {
  for(int B = 0; B <= (N - 1); B++) {
    for(int I = 0; I <= 11; I++) {
      for(int i = 0; i <= letters[I]; i++) {
        leds[i] = CRGB(red,green,blue);
      }
      FastLED.show();
    
      delay(60);
    }
    delay(500);

    turnoff();
    FastLED.show();

  }
}

// blink pattern blinks the lights
void blinkpattern(int N) {
  for(int C = 0; C <= (N - 1); C++) {
    
    delay(500);

    for(int i = 0; i <= 558; i++) {
      leds[i] = CRGB(red,green,blue);
    }
    FastLED.show();
    
    delay(500);

    turnoff();
    FastLED.show();
    

  }
}

// not so random lights turn on. broken for some random reason
void randompattern(int N) {
  turnoff();
  FastLED.show();
  for(int D = 0; D <= (N - 1); D++) {
    for(int I = 0; I <= 11; I++) {
      for(int i = letters[numbers[I] - 2]; i < letters[numbers[I] - 1]; i++) {
        leds[i] = CRGB(red,green,blue);
      }
      FastLED.show();
      delay(300);
    }
    delay(300);
    turnoff();
    FastLED.show();
  }
}

// this is where you do things to the lights. this just runs indefinatly looping through what you write in it. this just calls the funcs
void loop() {

 slidepattern(2);
 progressionpattern(2);
 blinkpattern(2);
 
}
