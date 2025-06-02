void setup() {
  Serial.begin(9600);
}

void loop() {
  int valBase = analogRead(A0);
  int valColector = analogRead(A1);

  float vBase = valBase * (5.0 / 1023.0);
  float vCol = valColector * (5.0 / 1023.0);

  float iB = vBase / 1000.0;  // Rb = 1kΩ

  float vCaidaRC = 5.0 - vCol;  // Caída sobre Rc
  float iC = vCaidaRC / 220.0;  // Rc = 220Ω

  float beta = (iB > 0.00001) ? iC / iB : 0;

  Serial.print("VB: ");
  Serial.print(vBase, 3);
  Serial.print(" V\tIB: ");
  Serial.print(iB * 1000, 3);
  Serial.print(" mA\t");

  Serial.print("VC: ");
  Serial.print(vCol, 3);
  Serial.print(" V\tIC: ");
  Serial.print(iC * 1000, 3);
  Serial.print(" mA\t");

  Serial.print("Beta: ");
  Serial.println(beta, 1);

  delay(1000);
}
