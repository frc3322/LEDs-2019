    #include "FastLED.h"
    #define COLOR_ORDER GRB

CRGB blinkBackup[85];
CRGB leds[85];
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, 5, COLOR_ORDER>(leds, 85); 
}

int Sense(int InputNum) {
  //Array of lights features alternating direction of lights. This is a fix
  if (InputNum <= 16) {return InputNum;}
  if ((InputNum >=17) and (InputNum <=33)) {return -InputNum + 50;}
  if ((InputNum >=34) and (InputNum <=50)) {return InputNum;}
  if ((InputNum >=51) and (InputNum <=67)) {return -InputNum + 118;}
  if ((InputNum >=68) and (InputNum <=84)) {return InputNum;}
}


void Scroll(long col1, long col2, long col3, long col4, long col5, int stay) {
//Creates a scrolling effect for each induvidual line by moving each light value left
//First five inputs are the five rightmost lights, bottom to top
//Last input is the number of lights, right-to-left, that the scrolling ignores
  for ( int i = 16-stay; i > 0; i--) {
    
    leds[i]=leds[i-1];
    }

  for ( int i = 33-stay; i > 17; i--) {
      
    leds[Sense(i)]=leds[Sense(i-1)];
    }

  for ( int i = 50-stay; i > 34; i--) {
      
    leds[i]=leds[i-1];
    }

  for ( int i = 67-stay; i > 51; i--) {
      
    leds[Sense(i)]=leds[Sense(i-1)];
    }

  for ( int i = 84-stay; i > 68; i--) {
      
    leds[i]=leds[i-1];
    }

  leds[0] = col1;
  leds[Sense(17)] = col2;
  leds[34] = col3;
  leds[Sense(51)] = col4;
  leds[68] = col5; FastLED.show(); delay(250);
}




void SetupBlink() {
//stores the current set of lights that are on in another variable; only needs to be done once if blink() is used multiple times without changing the lights
  for ( int i = 0; i < 85; i++) {
    blinkBackup[i] = leds[i];
  }
}


void Blink() {
//flashes black for half a second. Use SetupBlink() first
  for ( int i = 0; i < 85; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show(); delay(500);
    for ( int i = 0; i < 85; i++) {
    leds[i] = blinkBackup[i];
  }
  FastLED.show(); delay(500);


}

void loop() {
  // put your main code here, to run repeatedly:

  Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue, 0);
  Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue, 0);
  Scroll(CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, 0);
  for ( int i = 0; i < 14; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);
    }
  Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue, 4);
  Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue, 4);
  Scroll(CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, 4);
  for ( int i = 0; i < 10; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 4);
    }
  
  Scroll(CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Black, CRGB::Blue, 8);
  Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue, 8);
  Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Blue, CRGB::Blue, 8);
  for ( int i = 0; i < 6; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 8);
    }

  Scroll(CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Black, CRGB::Blue, 12);
  Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue, 12);
  Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Blue, CRGB::Blue, 12);

  for ( int i = 0; i < 2; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 12);
    }
  delay(1000);
  SetupBlink();
  Blink();
  Blink();
  Blink();  
  delay(1000);

  for ( int i = 0; i < 17; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);
    }
}
