const int PIN_LED = 10;
const int PIN_BTN_1 = 11;
const int PIN_BTN_2 = 12;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BTN_1, INPUT_PULLUP);
  pinMode(PIN_BTN_2, INPUT_PULLUP);
}

void loop() {
  int x = digitalRead(PIN_BTN_1);
  int y = digitalRead(PIN_BTN_2);
  if(x == LOW){
    digitalWrite(PIN_LED, HIGH);
    delay(1000);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
  }
  if(y == LOW){
    digitalWrite(PIN_LED, HIGH);
    delay(700);
    digitalWrite(PIN_LED, LOW);
    delay(700);
  }
}
