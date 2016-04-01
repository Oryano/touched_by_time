void setup() {

  const int ledPins[3] = {2, 13, 4};
  pinMode (ledPins[0], OUTPUT);
  pinMode (ledPins[1], OUTPUT);
  pinMode (ledPins[2], OUTPUT);

  const byte sequence[6] = {1, 2, 0, 1, 0, 2};
  const int duration = 400;

  int i;
  int j;
  for (i = 0; i < 6; i = i + 1) {
    j = sequence[i];
    delay (duration);
    digitalWrite(ledPins[j], HIGH);
    delay(duration);
    digitalWrite(ledPins[j], LOW);
    delay(duration);

  }
}

void loop() {

}
