//https://www.tinkercad.com/things/2oHi7Tb9Lez-sensor-luz?sharecode=tl5u90QNywtT2DsU8ooUDin6j20sXZMCtklG4EAlKgU

const int LED_PIN = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valor = analogRead(A0);
  int porcentaje = map(valor, 54, 974, 0, 100);
  if(porcentaje > 70){
    digitalWrite(LED_PIN, LOW);
  }else{
    digitalWrite(LED_PIN, HIGH);
  }
  Serial.println(porcentaje);
}
