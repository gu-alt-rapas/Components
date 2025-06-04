void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, LOW);  // Encender LED
  delay(5000);
  digitalWrite(2, HIGH); // Apagar LED
  delay(5000);
}
