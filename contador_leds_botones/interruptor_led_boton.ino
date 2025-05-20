const int LEDS[] = {13,12,11,10,9,8}; 
const int MAXLEDS = sizeof(LEDS) / sizeof(LEDS[0]);
const int BTN_INCREASE = 7;
const int BTN_DECREASE = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(3600);
  for(int i = 0; i < MAXLEDS; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(BTN_INCREASE, INPUT_PULLUP);
  pinMode(BTN_DECREASE, INPUT_PULLUP);
}

int LEDS_OFF_COUTN = -1;;
int LAST_INCREASE_VALUE = HIGH;
int LAST_DECREASE_VALUE = HIGH;

void loop() {
  int BTN_INCREASE_VALUE = digitalRead(BTN_INCREASE);
  int BTN_DECREASE_VALUE = digitalRead(BTN_DECREASE);
  
  Serial.println(LEDS_OFF_COUTN);

  if(BTN_INCREASE_VALUE == LOW && LAST_INCREASE_VALUE == HIGH){
    if(LEDS_OFF_COUTN <= MAXLEDS){
      LEDS_OFF_COUTN++;
      digitalWrite(LEDS[LEDS_OFF_COUTN], HIGH);
    }
  }

  if(BTN_DECREASE_VALUE == LOW && LAST_DECREASE_VALUE == HIGH){
    if(LEDS_OFF_COUTN >= 0){
      LEDS_OFF_COUTN--;
      digitalWrite(LEDS[LEDS_OFF_COUTN], LOW);
    }
  }

  LAST_INCREASE_VALUE = BTN_INCREASE_VALUE;
  LAST_DECREASE_VALUE = BTN_DECREASE_VALUE;
}
