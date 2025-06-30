//https://www.tinkercad.com/things/1GkxFkxIzsB-tempbrillo

const int PIN_GATE_MOTOR = 11; 

void setup() {
  pinMode(PIN_GATE_MOTOR, OUTPUT);
}

int temp = 0;

void loop() {
  temp = map(analogRead(A0), 0, 1023, 0, 255);
  analogWrite(PIN_GATE_MOTOR, temp); 
}
