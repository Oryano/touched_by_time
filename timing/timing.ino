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
int vibePin[8];      // the number of the vibe pin



// make state Variables to all motors (will change):


int led1State = LOW;             // ledState used to set the LED
int led2State = LOW;
int led3State = LOW;
int led4State = LOW;
int led5State = LOW;
int led6State = LOW;
int led7State = LOW;
int led8State = LOW;
int led9State = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
// will store last time LED was updated

// constants won't change :
const long interval = 1000;     // interval at which to blink (milliseconds)
unsigned long elapsed;   //number of timer laps in an interval
unsigned long previous; 
int state = 0;

void setup() {

  Serial.begin(9600);

  //initialize 9 pins as outputs ( pin 2 to 9)
  for (int i = 2; i < 9; i++) {
    pinMode(vibePin[i], OUTPUT);
  }
  previous =  millis(); //probably 0 at this point of the sketch
}

void loop() {
  
  if (state > 5) {

    state = 0;
    //sleep
  };

  // check to see if it's time to vibe; that is, if the
  // difference between the current time and last time you vibed
  // is bigger than the interval at which you want to vibe

  unsigned long current = millis();

  elapsed = elapsed + current - previous;

  Serial.println("----------");

  Serial.print("current ");
  Serial.println(current);

  Serial.print("previous ");
  Serial.println(previous);

  Serial.print("elapsed ");
  Serial.println(elapsed);


  previous = current;

  if (elapsed >= interval) {

    //state++

    // save the last time you blinked the LED
    elapsed = 0;

  } else {

    //play(state)
    // get sequence for state

  }


  // if the LED is off turn it on and vice-versa:

  //
  //    if (led1State == LOW) {
  //      led1State = HIGH;
  //    } else {
  //      led1State = LOW;
  //    }
  //
  //    if (led2State == LOW) {
  //      led2State = HIGH;
  //    } else {
  //      led2State = LOW;
  //    }
  //
  //    if (led3State == LOW) {
  //      led3State = HIGH;
  //    } else {
  //      led3State = LOW;
  //    }
  //
  //    if (led4State == LOW) {
  //      led4State = HIGH;
  //    } else {
  //      led4State = LOW;
  //    }



  // set the LED with the ledState of the variable:
  //digitalWrite(vibePin, ledState);

}

