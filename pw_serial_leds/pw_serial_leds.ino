//https://www.tinkercad.com/things/26hZBX6AVpX-pw-serial-leds?sharecode=jZNmLXAFDz2hhKAfkDQQhAU0wUaqgbkZbhs6gM7Yc98

const int BTNS_PW_PINS[] = {12, 11, 10};
const int PASSWORD[] = {0, 1, 1};
const int BTN_CONFIRM_PIN = 8;
//GREEN | RED
const int LEDS_PINS[] = {7, 6};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < 3; i++){
    pinMode(BTNS_PW_PINS[i], INPUT);
  }
  for(int i = 0; i < 2; i++){
    pinMode(LEDS_PINS[i], OUTPUT);
  }
  pinMode(BTN_CONFIRM_PIN, INPUT_PULLUP);
}

int LAST_STATE_BTN_CONFIRM = HIGH;
void loop() {
  // put your main code here, to run repeatedly:
  int CURRENT_STATE_BTN_CONFIRM = digitalRead(BTN_CONFIRM_PIN);

  if(CURRENT_STATE_BTN_CONFIRM == LOW && LAST_STATE_BTN_CONFIRM == HIGH){
    Serial.println(digitalRead(BTNS_PW_PINS[0]));
    Serial.println(digitalRead(BTNS_PW_PINS[1]));
    Serial.println(digitalRead(BTNS_PW_PINS[2]));
    Serial.println("--------------------");
    if(digitalRead(BTNS_PW_PINS[0]) == PASSWORD[0] && digitalRead(BTNS_PW_PINS[1]) == PASSWORD[1] && digitalRead(BTNS_PW_PINS[2]) == PASSWORD[2]){
      digitalWrite(LEDS_PINS[0], HIGH);
      delay(1500);
      digitalWrite(LEDS_PINS[0], LOW);
    }else{
      digitalWrite(LEDS_PINS[1], HIGH);
      delay(1500);
      digitalWrite(LEDS_PINS[1], LOW);
    }
  }

  LAST_STATE_BTN_CONFIRM = CURRENT_STATE_BTN_CONFIRM;
}
