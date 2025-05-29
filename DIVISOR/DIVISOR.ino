void setup() {
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(A0);
  float voltaje = lectura * (5.0 / 1023.0);
  
  Serial.print("ADC: ");
  Serial.print(lectura);
  Serial.print(" | Voltaje: ");
  Serial.print(voltaje);
  Serial.println(" V");

  delay(500);
}
