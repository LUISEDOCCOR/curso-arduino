//https://www.tinkercad.com/things/jotwwp1qovL-funcion-boton?sharecode=JQBiD4eBT6iJNpbLI41OdjvRF8VsfArQgItsB-E1TWM

const int BUTTON_PIN = 12;
const int LED_PIN = 11;

void setup() {
  // put your setup code here, to run once:
  //pinMode(BUTTON_PIN, INPUT_PULLUP) NO SE CONECTA LA RESISTENCIA ESTA HIGTH AL PRESIONAR PASA A SER LOW
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, state);
  delay(60);
}
