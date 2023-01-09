int pinSvetodiod = 13;
void setup() {
  pinMode(pinSvetodiod, OUTPUT);

}

void loop() {
  digitalWrite(pinSvetodiod, HIGH);
  delay(1000);
  digitalWrite(pinSvetodiod, LOW);
  delay(1000);
}
