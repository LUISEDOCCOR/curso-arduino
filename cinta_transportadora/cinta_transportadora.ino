const int BTN_STOP = 12;
const int BTN_START = 11;
const int MOTOR_PIN = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(BTN_START, INPUT_PULLUP);
  pinMode(BTN_STOP, INPUT_PULLUP);
  pinMode(MOTOR_PIN, OUTPUT);
}

bool MOTOR_STATE = false;

void loop() {
  // put your main code here, to run repeatedly:
  int CURRENT_BTN_STOP_STATE = digitalRead(BTN_STOP);
  int CURRENT_BTN_START_STATE = digitalRead(BTN_START);
  
  if(CURRENT_BTN_START_STATE == LOW ){
    MOTOR_STATE = true;
  }

  if(CURRENT_BTN_STOP_STATE == LOW ){
    MOTOR_STATE = false;
  }

  digitalWrite(MOTOR_PIN, MOTOR_STATE);
}
