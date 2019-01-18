    #include "FastLED.h"
    #define COLOR_ORDER GRB


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


void Scroll(long col1, long col2, long col3, long col4, long col5) {
//creates a scrolling effect for each induvidual line by moving each light value left
//inputs are the five rightmost lights, bottom to top
  for ( int i = 16; i > 0; i--) {
    
    leds[i]=leds[i-1];
    }

for ( int i = 33; i > 17; i--) {
      
  leds[Sense(i)]=leds[Sense(i-1)];
  }

for ( int i = 50; i > 34; i--) {
      
  leds[i]=leds[i-1];
  }

for ( int i = 67; i > 51; i--) {
      
  leds[Sense(i)]=leds[Sense(i-1)];
  }

for ( int i = 84; i > 68; i--) {
      
  leds[i]=leds[i-1];
  }

leds[0] = col1;
leds[Sense(17)] = col2;
leds[34] = col3;
leds[Sense(51)] = col4;
leds[68] = col5; FastLED.show(); delay(1000);
}


void loop() {
  // put your main code here, to run repeatedly:

Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue);
Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue);
Scroll(CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue);
Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black);

Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue);
Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue);
Scroll(CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Blue);
Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black);

Scroll(CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Black, CRGB::Blue);
Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue);
Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Blue, CRGB::Blue);
Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black);

Scroll(CRGB::Blue, CRGB::Blue, CRGB::Blue, CRGB::Black, CRGB::Blue);
Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Black, CRGB::Blue);
Scroll(CRGB::Blue, CRGB::Black, CRGB::Blue, CRGB::Blue, CRGB::Blue);

Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black);
Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black);
Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black);
}
