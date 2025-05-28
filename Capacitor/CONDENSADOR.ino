const int chargePin = 7;
const int readPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(chargePin, OUTPUT);
}

void loop() {
  int lectura;
  unsigned long startTime, elapsed;

  // CARGA
  digitalWrite(chargePin, HIGH);
  startTime = millis();
  do {
    lectura = analogRead(readPin);
    Serial.println(lectura);
    delay(10);
  } while (lectura < 1000); // casi completamente cargado
  elapsed = millis() - startTime;
  Serial.print("CARGA_MS:");
  Serial.println(elapsed);

  delay(500);  // Pausa antes de descarga

  // DESCARGA
  digitalWrite(chargePin, LOW);
  startTime = millis();
  do {
    lectura = analogRead(readPin);
    Serial.println(lectura);
    delay(10);
  } while (lectura > 10); // casi completamente descargado
  elapsed = millis() - startTime;
  Serial.print("DESCARGA_MS:");
  Serial.println(elapsed);

  Serial.println("---");
  delay(2000);
}
