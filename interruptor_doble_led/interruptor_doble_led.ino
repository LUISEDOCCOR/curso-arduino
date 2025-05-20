const int LEDS[] = {12, 11};
const int BUTTON = 10;

void setup() {
  for(int i = 0; i < 2; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int button_state = digitalRead(BUTTON);
  if(button_state == LOW){
    digitalWrite(LEDS[0], LOW);
    digitalWrite(LEDS[1], HIGH);
  }else{
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], LOW);
  }
}
