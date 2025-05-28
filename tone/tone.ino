//https://www.tinkercad.com/things/2Skki55gUaM-tone?sharecode=Di3GY2dOaC3E5xx5E95ov5yKI1z-ipFDLVqRQYdRbH0

const int bellPin = 9;

void setup(){
}

void loop(){
  tone(bellPin, 988, 250);
  delay(1000);
  tone(bellPin, 988, 250);
  delay(400);
  tone(bellPin, 880, 250);
  delay(400);
  tone(bellPin, 988, 250);
  delay(1000);

  tone(bellPin, 988, 250);
  delay(400);
  tone(bellPin, 880, 250);
  delay(400);
  tone(bellPin, 988, 250);
  delay(1000);

  tone(bellPin, 988, 250);
  delay(400);
  tone(bellPin, 880, 250);
  delay(400);
  tone(bellPin, 784, 1000);
  delay(1000);
  tone(bellPin, 880, 1000);
  delay(1000);
}