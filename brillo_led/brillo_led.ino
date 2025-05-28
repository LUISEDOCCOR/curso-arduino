//https://www.tinkercad.com/things/4kDggzryKsd-brillo-led?sharecode=GYsn91LEwUAF4VMXE_rWXKKtkd2e4shFLMCGAbUSvx0

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int valorPot = analogRead(A0); //LEER 10bts 0 - 1023
  analogWrite(11, valorPot/4); //SALDIA 8bts 0 - 255
}
