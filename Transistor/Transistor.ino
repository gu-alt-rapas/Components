const int transistorPin = 7;

void setup() {
  pinMode(transistorPin, OUTPUT);
}

void loop() {
  digitalWrite(transistorPin, HIGH); // Enciende el LED
  delay(1000);
  digitalWrite(transistorPin, LOW);  // Apaga el LED
  delay(1000);
}
