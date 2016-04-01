

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop () {
  static unsigned long starttime;
  static int ledstate = LOW;

  if (ledstate == HIGH && millis() - starttime > 500) {
    ledstate = LOW;
    digitalWrite(13, LOW);
    starttime = millis();
    //Serial.println("---------------");
    Serial.println("off");
    Serial.print("starttime ");
    Serial.println(starttime);
  }
  else if (ledstate == LOW && millis() - starttime > 1000) {
    ledstate = HIGH;
    digitalWrite(13, HIGH);
    starttime = millis();
    Serial.println("---------------");
    Serial.println("on");
    Serial.print("starttime ");
    Serial.println(starttime);
  }
}
