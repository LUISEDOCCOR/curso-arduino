void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int entrada = analogRead(A0);
  int porcentaje = map(entrada, 0, 1023, 0, 180);
  Serial.println(porcentaje);
}
