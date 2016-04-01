#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;


boolean intervalSession = true;

//is const unsigned long correct?
unsigned long wholeTime = 5000;      //5 = 300,000 minuts interval
const int workingTime = 2000;     //2 seconds pattern happening
unsigned long intervalTime = wholeTime - workingTime;

int lastCheck = 0;
int vibePin[8];   //number of pins connected

unsigned long currentTime;          //from millis()
unsigned long lastPatternCheck;     //for 500 ms intervals

int patternState = 1; //there are 4 states (each 500 ms)

DateTime now; //global to all functions


void setup() {

#ifndef ESP8266
  while (!Serial); // for RTC Leonardo/Micro/Zero
#endif

  Serial.begin(9600);
  delay(1000);    //wait for serial monitor to start

  //RTC stuff-------------------------
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  //end RTC stuff----------------------


  //initialize 9 pins as outputs (pins 2 to 9)
  for (int i = 0; i < 8; i++) {
    pinMode(i + 2, OUTPUT); //adjust numbers and makem OUTPUTS
    vibePin[i] = i + 2;     //match to pins
  }
  currentTime = 0; //from millis()
}


void loop() {

  //Serial.println( "-----------" );
  currentTime = millis();

  if (currentTime - lastCheck >= intervalTime) {
    Serial.print(intervalSession);
    if (intervalSession == true) {
      intervalSession = false;
      
      patternState = 1;
      
      lastPatternCheck = currentTime;
      loadPattern(patternState);      //call function that takes the right pattern
    }
    //problem miht be below if statment
    if (currentTime - lastCheck >= wholeTime) {
      intervalSession = true;
      lastCheck = currentTime;
    }
  }

  if (intervalSession) {
    //interval time!! turn vibe and LED off - Do nothing maybe ADD sleep?
    for (int i = 0; i < 8; i++) {
      digitalWrite(vibePin[i], LOW);
    }
    //Serial.println("----I----");
  }
  else {
    //pattern time 2 seconds

    if (currentTime - lastPatternCheck > 500) { //4 frames of pattern 500 ms each
      patternState ++;  //position of digit to read
      Serial.println("hi");
      //loadPattern(patternState);
      lastPatternCheck = currentTime;  //timestamp of last update
    }

    //Serial.println("----I----");
  }

}

void loadPattern( int clockDigit ) { //takes the digit from the c
  now = rtc.now();

  if (clockDigit == 1 ) {
    //show frame 1
    int smooth = floor((now.hour()) / 10); //find the first digit of hour
    //Serial.println(smooth);
    showPattern(smooth);
  }
  else if (clockDigit == 2 ) {
    //show frame 2
    int leftOver = (now.hour()) % 10;  //find the second digit of hour
    showPattern(leftOver);
  }
  else if (clockDigit == 3 ) {
    //show frame 3
    int smooth = floor(now.minute() / 10); //find the first digit of hour
    showPattern(smooth);
  }
  else if (clockDigit == 4 ) {
    //show frame 4
    int leftOver = (now.minute()) % 10;  //find the second digit of hour
    showPattern(leftOver);
  }
}

void showPattern( int content ) { //content is the location in the dictionary!!!

  Serial.println( "-----------" );
  Serial.println( content );

  if (content == 0) {
    Serial.println( "sequence for 0" );
  }
  else if (content == 1) {
    Serial.println( "sequence for 01" );
  }
  else if (content == 2) {
    Serial.println( "sequence for 02" );
  }
  else if (content == 3) {
    Serial.println( "sequence for 03" );
  }
  else if (content == 4) {
    Serial.println( "sequence for 04" );
  }
  else if (content == 5) {
    Serial.println( "sequence for 05" );
  }
  else if (content == 6) {
    Serial.println( "sequence for 06" );
  }
  else if (content == 7) {
    Serial.println( "sequence for 07" );
  }
  else if (content == 8) {
    Serial.println( "sequence for 08" );
  }
  else if (content == 9) {
    Serial.println( "sequence for 09" );
  }
}


