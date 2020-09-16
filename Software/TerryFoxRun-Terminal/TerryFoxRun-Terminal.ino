//Developed by : Milador (https://github.com/milador/TerryFoxRun-Terminal)
//Firmware : TerryFoxRun-Terminal.ino
//VERSION: 1.0.0 (15 September 2020) 

#include "xbm.h"
#include "melody.h" 
#include "fonts.h" 
#include <TFT_eSPI.h>        // Hardware-specific library

#define TEXT "Milad is running.."
#define TIME_DELAY 200
#define TIME_SHORT_DELAY 100
#define TIME_LONG_DELAY 3000
#define BUZZER_PIN WIO_BUZZER

TFT_eSPI tft = TFT_eSPI();   // Invoke library
//Structure for bitmap
typedef struct {                                  
  uint8_t bitmapNumber;
  PROGMEM const unsigned char* bitmapName;
  uint16_t bitmapColor;
} bitmapStruct;

//bitmap Intro properties 
const bitmapStruct bitmapIntroProperty[] {
    {1,intro1,TFT_RED},
    {2,intro2,TFT_RED},
    {3,intro3,TFT_RED},    
    {4,intro4,TFT_RED},
    {5,intro5,TFT_RED},
    {6,intro6,TFT_RED},
    {7,intro7,TFT_RED},
    {8,intro8,TFT_RED}, 
    {9,intro9,TFT_RED}, 
    {10,intro10,TFT_RED}
};

//bitmap Intro properties 
const bitmapStruct bitmapColorfulProperty[] {
    {1,intro10,TFT_WHITE},
    {2,intro10,TFT_YELLOW},
    {3,intro10,TFT_CYAN},    
    {4,intro10,TFT_GREEN},
    {5,intro10,TFT_PURPLE},
    {6,intro10,TFT_RED},
    {7,intro10,TFT_BLUE}
};

//bitmap Intro properties 
const bitmapStruct bitmapMainProperty[] {
    {1,main1,TFT_NAVY},
    {2,main2,TFT_NAVY},
    {3,main3,TFT_NAVY},    
    {4,main4,TFT_NAVY},
    {5,main5,TFT_NAVY},
    {6,main6,TFT_NAVY},
    {7,main7,TFT_NAVY},
    {8,main8,TFT_NAVY}, 
    {9,main9,TFT_NAVY}, 
    {10,main10,TFT_DARKGREEN},
    {11,main11,TFT_DARKGREEN},
    {12,main12,TFT_DARKGREEN},
    {13,main13,TFT_DARKGREEN},    
    {14,main14,TFT_DARKGREEN},
    {15,main15,TFT_DARKGREEN},
    {16,main16,TFT_DARKGREEN},
    {17,main17,TFT_DARKGREEN},
    {18,main18,TFT_DARKGREEN}, 
    {19,main19,TFT_DARKGREEN}, 
    {20,main20,TFT_DARKGREEN},
    {21,main21,TFT_DARKGREEN},
    {22,main22,TFT_DARKGREEN},
    {23,main23,TFT_DARKGREEN},    
    {24,main24,TFT_DARKGREEN},
    {25,main25,TFT_DARKGREEN},
    {26,main26,TFT_DARKGREEN},
    {27,main27,TFT_PURPLE},
    {28,main28,TFT_PURPLE}, 
    {29,main29,TFT_PURPLE}, 
    {30,main30,TFT_PURPLE},   
    {31,main31,TFT_PURPLE},
    {32,main32,TFT_PURPLE},
    {33,main33,TFT_PURPLE}
};



void setup() {
    tft.begin();               // Initialise the display
    tft.fillScreen(TFT_BLACK); // Black screen fill
    pinMode(WIO_BUZZER, OUTPUT);
    Serial.begin(115200); 

    tft.setSwapBytes(true);
}

void displayName(int timeDelay){
    tft.setRotation(3);
    tft.setTextDatum(MC_DATUM);
    // Set text colour to orange with black background
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.fillScreen(TFT_BLACK);              // Clear screen
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(timeDelay);   
    tft.fillScreen(TFT_BLACK); 
    tft.setRotation(0);
}

void displayIntro(int timeDelay){
  for(int i = 0; i <= (sizeof (bitmapIntroProperty) / sizeof (bitmapIntroProperty[0]))-1; i++){
    //Serial.println(bitmapIntroProperty[i].bitmapNumber);
    tft.drawXBitmap(0, 0, bitmapIntroProperty[i].bitmapName, frameWidth, frameHeight, bitmapIntroProperty[i].bitmapColor,TFT_WHITE);
    delay(timeDelay);
    tft.drawXBitmap(0, 0, bitmapIntroProperty[i].bitmapName, frameWidth, frameHeight, TFT_BLACK);
    delay(timeDelay);      
   }
   tft.fillScreen(TFT_WHITE);
}

void displayColorful(int timeDelay){
  for(int i = 0; i <= (sizeof (bitmapColorfulProperty) / sizeof (bitmapColorfulProperty[0]))-1; i++){
    //Serial.println(bitmapIntroProperty[i].bitmapNumber);
    tft.drawXBitmap(0, 0, bitmapColorfulProperty[i].bitmapName, frameWidth, frameHeight, bitmapColorfulProperty[i].bitmapColor,TFT_WHITE);
    delay(timeDelay);
    tft.drawXBitmap(0, 0, bitmapColorfulProperty[i].bitmapName, frameWidth, frameHeight, TFT_BLACK);
    delay(timeDelay);      
   }
   tft.fillScreen(TFT_WHITE);
}

void displayRandom(){
  int randomNum=random(0,(sizeof (bitmapColorfulProperty) / sizeof (bitmapColorfulProperty[0]))-1);
  tft.drawXBitmap(0, 0, bitmapColorfulProperty[randomNum].bitmapName, frameWidth, frameHeight, bitmapColorfulProperty[randomNum].bitmapColor,TFT_WHITE);
  delay(5);
  tft.drawXBitmap(0, 0, bitmapColorfulProperty[randomNum].bitmapName, frameWidth, frameHeight, TFT_BLACK);
  delay(5);      
  //tft.fillScreen(TFT_WHITE);
}
void displayMain(int timeDelay){
  for(int i = 0; i <= (sizeof (bitmapMainProperty) / sizeof (bitmapMainProperty[0]))-1; i++){
    //Serial.println(bitmapIntroProperty[i].bitmapNumber);
    tft.drawXBitmap(0, 0, bitmapMainProperty[i].bitmapName, frameWidth, frameHeight, bitmapMainProperty[i].bitmapColor,TFT_WHITE);
    delay(timeDelay);
    tft.drawXBitmap(0, 0, bitmapMainProperty[i].bitmapName, frameWidth, frameHeight, TFT_BLACK);
    delay(timeDelay);      
   }
   //tft.fillScreen(TFT_WHITE);
}

// Play melody
void sing(){      
     displayRandom();
     int size = sizeof(melody) / sizeof(int);
     for (int thisNote = 0; thisNote < size; thisNote++) {
       int noteDuration = 1000/tempo[thisNote];
       buzz(WIO_BUZZER, melody[thisNote],noteDuration);
       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration *1.3;
       delay(pauseBetweenNotes);
       // stop the tone playing:
       buzz(WIO_BUZZER, 0,noteDuration);

    }
    

}

void buzz(int targetPin, long frequency, long length) {
  long delayValue = 50000/frequency/1; // calculate the delay value between transitions
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
}

void loop() {
    displayName(TIME_LONG_DELAY);
    displayIntro(TIME_DELAY);
    displayColorful(TIME_SHORT_DELAY);
    displayMain(TIME_DELAY);
}
