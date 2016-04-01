/* Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital
  pin, without using the delay() function.  This means that other code
  can run at the same time without being interrupted by the LED code.

  The circuit:
   LED attached from pin 13 to ground.
   Note: on most Arduinos, there is already an LED on the board
  that's attached to pin 13, so no hardware is needed for this example.

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald


  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

// constants won't change. Used here to set a pin number :
const int ledPin1 =  2;      // the number of the LED pin
const int ledPin2 =  4;

// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long intervalBig = 5000;       // interval between sequences (5 min)
const long seqDuration = 1000;    //interval for the sequence to happen

boolean seqTime = false; //for 2 seconds measure

void setup() {
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  //  Serial.print("current ");
  //  Serial.println(currentMillis);
  //  Serial.print("last ");
  //  Serial.println(previousMillis);



  if (currentMillis - previousMillis >= intervalBig) { //if 5 min had gone by
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    Serial.print(seqTime);
    // switch state every 5 min [if on then off if off then on]
    if (seqTime == false) { //after 5 min turn on if off
      seqTime = true;
    } else {
      seqTime = false;
    }

    sequence(seqTime);
  }
}

void sequence(boolean) {
  unsigned long currentMillisBBB = millis();

  if (seqTime == true || currentMillisBBB - previousMillis >= intervalSmall) { //do math to calc 2 sec
    previousMillis = currentMillisBBB;    // save the last time you blinked the LED

//    if (seqTime == false) {
//      seqTime = true;
//    } else {
//      seqTime = false;
//    }

    //digitalWrite(ledPin, HIGH);  //trun on sequence
    //do something for 2 seconds
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);

  } else {
    //digitalWrite(ledPin, LOW);  //trun on sequence
    //reseat the timer
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
}





