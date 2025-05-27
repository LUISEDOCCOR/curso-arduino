//https://www.tinkercad.com/things/kzEJagsho76-prender-apagar-led?sharecode=uhkBWpI1vXsLh1EimrAfZQmpDb77Zs4n60dCOBxO-sc

const int PIN_LED = 13;
const int PIN_BTN = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BTN, INPUT_PULLUP);
}

int lastButtonState = HIGH;
bool ledIsOff = false;

void loop() {
  // put your main code here, to run repeatedly:
  int btnCurrentState = digitalRead(PIN_BTN);

  if(btnCurrentState == LOW && lastButtonState == HIGH){
    ledIsOff = !ledIsOff;
    digitalWrite(PIN_LED, ledIsOff);
  }

  lastButtonState = btnCurrentState;
}
