    #include "FastLED.h"
    #define COLOR_ORDER GRB
const int buttonPin1 = 2;
const int buttonPin2 = 8;
long Color = 0;



CRGB blinkBackup[85];
CRGB leds[85];
void setup() {  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  FastLED.addLeds<WS2811, 5, COLOR_ORDER>(leds, 85); 
  randomSeed(analogRead(0)); 
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
//Creates a scrolling effect for each induvidual line by moving each light value left one light
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

void Sclorr(long col1, long col2, long col3, long col4, long col5, int stay, int Update=0) {
//Copy-and-paste of scroll() but flipped along the y-axis
//if the name looks weird, it's because the r's and l's in the name were swapped too
//Update will stop fastleds.show from being called, if it is not set to 0
  for ( int i = 0+stay; i < 16; i++) {
    
    leds[i]=leds[i+1];
    }

  for ( int i = 17+stay; i < 33; i++) {
      
    leds[Sense(i)]=leds[Sense(i+1)];
    }

  for ( int i = 34+stay; i < 50; i++) {
      
    leds[i]=leds[i+1];
    }

  for ( int i = 51+stay; i < 67; i++) {
      
    leds[Sense(i)]=leds[Sense(i+1)];
    }

  for ( int i = 68+stay; i < 84; i++) {
      
    leds[i]=leds[i+1];
    }

  leds[16] = col1;
  leds[Sense(33)] = col2;
  leds[50] = col3;
  leds[Sense(67)] = col4;
  leds[84] = col5; 
  
  if (Update == 0) {
  FastLED.show(); delay(250);}

}

void ScrollV(long Col,int Hpos, int Dir) {
//scrolls, but vertically
//Col is the color of the new led, Hpos is the position of the bottommost (or topmost, if going up) light in the column of choice
//Dir is the direction, up or down. 1 or -1
// ex. ScrollV(CRGB::Red,1); Will move all lights in the second-to-the-right column and make the top light of that column red
  for (int i = 0; i<4; i++) {
    leds[Sense(Hpos + (Dir*17*i))] = leds[Sense(Hpos + (17*Dir*(i+1)))];
    }
  leds[Sense(Hpos + Dir*68)] = Col;

}

void SetupBlink() {
//stores the current set of lights that are on in another variable
//recalled during the blink() function
//only needs to be done once if blink() is used multiple times without changing the light configuration
  for ( int i = 0; i < 85; i++) {
    blinkBackup[i] = leds[i];
  }
}


void Blink() {
//flashes black for half a second. Use SetupBlink() first or else it will not work
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
  

 
  while (Color == 0) {//color select. Use for alliance

    if (digitalRead(buttonPin1) == HIGH) {
    Color = CRGB::Blue;
    }
    if (digitalRead(buttonPin2) == HIGH) {
      Color = CRGB::Red;
    }
  }
  
  long PatternOut = random(4);
  long PatternIn = random(5);
  if (PatternIn == 2) {// scroll each letter --up then --down then --up --down
   
     ScrollV(Color,83,-1);  
     ScrollV(Color,82,-1);  
     ScrollV(CRGB::Black,81,-1);  FastLED.show(); delay(250);
     ScrollV(CRGB::Black,83,-1);  
     ScrollV(CRGB::Black,82,-1);  
     ScrollV(Color,81,-1);  FastLED.show(); delay(250);
     ScrollV(Color,83,-1);  
     ScrollV(Color,82,-1);  
     ScrollV(CRGB::Black,81,-1);  FastLED.show(); delay(250);
     ScrollV(CRGB::Black,83,-1);  
     ScrollV(CRGB::Black,82,-1);  
     ScrollV(Color,81,-1);  FastLED.show(); delay(250);
     ScrollV(Color,83,-1);  
     ScrollV(Color,82,-1);  
     ScrollV(CRGB::Black,81,-1);  FastLED.show(); delay(250);//3

     ScrollV(Color,11,1);
     ScrollV(Color,10,1);
     ScrollV(CRGB::Black,9,1);  FastLED.show(); delay(250);
     ScrollV(CRGB::Black,11,1);  
     ScrollV(CRGB::Black,10,1);  
     ScrollV(Color,9,1);  FastLED.show(); delay(250);
     ScrollV(Color,11,1);  
     ScrollV(Color,10,1);  
     ScrollV(CRGB::Black,9,1);  FastLED.show(); delay(250);
     ScrollV(CRGB::Black,11,1);  
     ScrollV(CRGB::Black,10,1);  
     ScrollV(Color,9,1);  FastLED.show(); delay(250);
     ScrollV(Color,11,1);  
     ScrollV(Color,10,1);  
     ScrollV(CRGB::Black,9,1);  FastLED.show(); delay(250);//3

     ScrollV(Color,75,-1);  
     ScrollV(Color,74,-1);  
     ScrollV(CRGB::Black,73,-1);  FastLED.show(); delay(250);
     ScrollV(CRGB::Black,75,-1);  
     ScrollV(CRGB::Black,74,-1);  
     ScrollV(Color,73,-1);  FastLED.show(); delay(250);
     ScrollV(CRGB::Black,75,-1);  
     ScrollV(Color,74,-1);  
     ScrollV(Color,73,-1);  FastLED.show(); delay(250);
     ScrollV(Color,75,-1);  
     ScrollV(CRGB::Black,74,-1);  
     ScrollV(CRGB::Black,73,-1);  FastLED.show(); delay(250);
     ScrollV(Color,75,-1);  
     ScrollV(Color,74,-1);  
     ScrollV(Color,73,-1);  FastLED.show(); delay(250);//2
   
     ScrollV(Color,3,1);  
     ScrollV(Color,2,1);  
     ScrollV(Color,1,1);  FastLED.show(); delay(250);
     ScrollV(Color,3,1);  
     ScrollV(CRGB::Black,2,1);  
     ScrollV(CRGB::Black,1,1);  FastLED.show(); delay(250);
     ScrollV(CRGB::Black,3,1);  
     ScrollV(Color,2,1);  
     ScrollV(Color,1,1);  FastLED.show(); delay(250);
     ScrollV(CRGB::Black,3,1);  
     ScrollV(CRGB::Black,2,1);  
     ScrollV(Color,1,1);  FastLED.show(); delay(250);
     ScrollV(Color,3,1);  
     ScrollV(Color,2,1);  
     ScrollV(CRGB::Black,1,1);  FastLED.show(); delay(250);//2
  }

  if (PatternIn == 1) {//scroll in from both sides

  Sclorr(CRGB::Black,Color,CRGB::Black,Color,CRGB::Black,8,1);//3, the right side
    Scroll(Color, Color, CRGB::Black, CRGB::Black, Color, 8);//2, the left side
  Sclorr(Color,CRGB::Black,Color,CRGB::Black,Color,8,1);//3
    Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 8);//2
  Sclorr(Color,CRGB::Black,Color,CRGB::Black,Color,8,1);//3
    Scroll(Color, CRGB::Black, Color, Color, CRGB::Black, 8);//2
  Sclorr(CRGB::Black,CRGB::Black,CRGB::Black,CRGB::Black,CRGB::Black, 8,1);//2
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 8);


  Sclorr(CRGB::Black,Color,CRGB::Black,Color,CRGB::Black,8,1);  //same pattern of 3's and 2's as above
    Scroll(Color, Color, CRGB::Black, CRGB::Black, Color, 8);
  Sclorr(Color,CRGB::Black,Color,CRGB::Black,Color,8,1);
    Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 8);
  Sclorr(Color,CRGB::Black,Color,CRGB::Black,Color,8,1);
    Scroll(Color, CRGB::Black, Color, Color, CRGB::Black, 8);  
  Sclorr(CRGB::Black,CRGB::Black,CRGB::Black,CRGB::Black,CRGB::Black,8,1);
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 8);

  }



  if (PatternIn == 0) {// block scroll

 
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Scroll(CRGB::Black, Color, CRGB::Black, Color, CRGB::Black, 0); //3
  for ( int i = 0; i < 13; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);
    }
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 5);
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 5);
  Scroll(CRGB::Black, Color, CRGB::Black, Color, CRGB::Black, 5); //3
  for ( int i = 0; i < 9; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 4);
    }

  Scroll(Color, Color, CRGB::Black, CRGB::Black, Color, 8);
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 8);
  Scroll(Color, CRGB::Black, Color, Color, CRGB::Black, 8); //2
  for ( int i = 0; i < 5; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 8);
    }

  Scroll(Color, Color, CRGB::Black, CRGB::Black, Color, 12);
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 12);
  Scroll(Color, CRGB::Black, Color, Color, CRGB::Black, 12); //2
  if ((digitalRead(buttonPin2) == HIGH) and (digitalRead(buttonPin1) == HIGH)) {
    Color = CRGB::Green; 
    }  
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 12);

  }

    if (PatternIn == 3) {// scroll left

  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Scroll(CRGB::Black, Color, CRGB::Black, Color, CRGB::Black, 0); //3
  Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);
   
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Scroll(CRGB::Black, Color, CRGB::Black, Color, CRGB::Black, 0); //3
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black,0);

  Scroll(Color, Color, CRGB::Black, CRGB::Black, Color, 0);
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Scroll(Color, CRGB::Black, Color, Color, CRGB::Black, 0); //2
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);
    
  Scroll(Color, Color, CRGB::Black, CRGB::Black, Color, 0);
  Scroll(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Scroll(Color, CRGB::Black, Color, Color, CRGB::Black, 0); //2
  Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);

  }

    if (PatternIn == 4) {// scroll right

  Sclorr(Color, CRGB::Black, Color, Color, CRGB::Black, 0);
  Sclorr(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Sclorr(Color, Color, CRGB::Black, CRGB::Black, Color, 0); //2
  Sclorr(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);
    

  Sclorr(Color, CRGB::Black, Color, Color, CRGB::Black, 0);  
  Sclorr(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Sclorr(Color, Color, CRGB::Black, CRGB::Black, Color, 0);//2
  Sclorr(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);

  Sclorr(CRGB::Black, Color, CRGB::Black, Color, CRGB::Black, 0);
  Sclorr(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Sclorr(Color, CRGB::Black, Color, CRGB::Black, Color, 0);//3
  Sclorr(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);

  Sclorr(CRGB::Black, Color, CRGB::Black, Color, CRGB::Black, 0);   
  Sclorr(Color, CRGB::Black, Color, CRGB::Black, Color, 0);
  Sclorr(Color, CRGB::Black, Color, CRGB::Black, Color, 0);//3
  Sclorr(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black,0);
  }
   
  delay(1000);
  SetupBlink();
  Blink();
  Blink();
  Blink();  
  delay(1000);

  if (PatternOut == 1) {
      for ( int i = 0; i < 17; i++){
    Scroll(CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, 0);
    } 
    }
  if (PatternOut == 0) {
        for ( int i = 0; i < 17; i++) {
      Sclorr(CRGB::Black,CRGB::Black,CRGB::Black,CRGB::Black,CRGB::Black,0);
      }
    }
  if (PatternOut == 2) {
    for  ( int j = 0; j < 5; j++) {
      for ( int i = 0; i < 17; i++) {
        ScrollV(CRGB::Black,i,1) ;
        FastLED.show();
        delay(100);
      }
    }
  }
  if (PatternOut == 3) {
    leds[1] = CRGB::Black; leds[2] = CRGB::Black; leds[5] = CRGB::Black; leds[11] = CRGB::Black;
    leds[14] = CRGB::Black; leds[15] = CRGB::Black; leds[Sense(20)] = CRGB::Black; leds[Sense(30)] = CRGB::Black;
    leds[35] = CRGB::Black; leds[36] = CRGB::Black; leds[39] = CRGB::Black; leds[45] = CRGB::Black; leds[48] = CRGB::Black;
    leds[49] = CRGB::Black; leds[Sense(52)] = CRGB::Black; leds[Sense(56)] = CRGB::Black; leds[Sense(64)] = CRGB::Black;
    leds[70] = CRGB::Black; leds[71] = CRGB::Black; leds[74] = CRGB::Black; leds[79] = CRGB::Black;
    leds[82] = CRGB::Black;  leds[83] = CRGB::Black;
    leds[4] = Color; leds[13] = Color; leds[Sense(21)] = Color; leds[Sense(29)] = Color; leds[38] = Color;
    leds[43] = Color; leds[46] = Color; leds[47] = Color; leds[Sense(54)] = Color; leds[Sense(57)] = Color;
    leds[Sense(63)] = Color; leds[72] = Color; leds[81] = Color;
    FastLED.show();
    delay(100);
    
    leds[3] = CRGB::Black; leds[4] = CRGB::Black; leds[6] = CRGB::Black; leds[7] = CRGB::Black; leds[10] = CRGB::Black;
    leds[13] = CRGB::Black; leds[40] = CRGB::Black; leds[44] = CRGB::Black; leds[47] = CRGB::Black; leds[Sense(54)] = CRGB::Black; 
    leds[Sense(57)] = CRGB::Black; leds[72] = CRGB::Black; leds[75] = CRGB::Black; leds[78] = CRGB::Black; leds[81] = CRGB::Black;
    leds[Sense(20)] = Color; leds[Sense(23)] = Color; leds[Sense(27)] = Color; leds[Sense(30)] = Color; leds[41] = Color;
    leds[42] = Color; leds[45] = Color; leds[Sense(55)] = Color; leds[Sense(56)] = Color; leds[Sense(58)] = Color;
    leds[Sense(59)] = Color; leds[Sense(61)] = Color; leds[Sense(64)] = Color;
    FastLED.show();
    delay(100);
    leds[Sense(20)] = CRGB::Black; leds[Sense(21)] = CRGB::Black; leds[Sense(23)] = CRGB::Black; leds[Sense(24)] = CRGB::Black;
    leds[Sense(26)] = CRGB::Black; leds[Sense(27)] = CRGB::Black; leds[Sense(29)] = CRGB::Black; leds[Sense(30)] = CRGB::Black;
    leds[38] = CRGB::Black; leds[45] = CRGB::Black; leds[46] = CRGB::Black; leds[Sense(55)] = CRGB::Black;
    leds[Sense(56)] = CRGB::Black; leds[Sense(58)] = CRGB::Black; leds[Sense(59)] = CRGB::Black; leds[Sense(60)] = CRGB::Black;
    leds[Sense(61)] = CRGB::Black; leds[Sense(63)] = CRGB::Black; leds[Sense(64)] = CRGB::Black;
    leds[Sense(40)] = Color; leds[Sense(44)] = Color;
    FastLED.show();
    delay(100);
    leds[Sense(40)] = CRGB::Black; leds[Sense(41)] = CRGB::Black; leds[Sense(43)] = CRGB::Black; leds[Sense(44)] = CRGB::Black;
    FastLED.show();
    delay(100);
    leds[8] = Color; leds[Sense(25)] = Color; leds[Sense(59)] = Color; leds[76] = Color;
    FastLED.show();
    delay(100);
    leds[8] = CRGB::Black; leds[Sense(25)] = CRGB::Black; leds[Sense(42)] = CRGB::Black;
    leds[Sense(59)] = CRGB::Black; leds[76] = CRGB::Black;
    FastLED.show();
    delay(300);
    
    }
}
//Index               Values may not be absolute due to neglect
//function            Code Line
//Sense               19
//Scroll              29
//Sclorr              65
//ScrollV             105
//SetupBlink          117
//Blink               127
//Loop                141
//Up-Down             158
//Both sides inwards  225
//Block scroll        250
//Scroll in left      286
//Scroll in right     310
//Exit Patterns       342
