//https://www.tinkercad.com/things/d0V0rwW2Oh6-velocidad-dc?sharecode=uFkezvoRYI9VweB_Extp8ZAAgvGr1o6tFtUBYmDCC5U
const int BTN_I_PIN = 12;
const int BTN_D_PIN = 11;
const int MOTOR_GATE_PIN = 9;
const int LED_GREEN_PIN = 6;
const int LED_RED_PIN = 7;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(BTN_I_PIN, INPUT_PULLUP);
  pinMode(BTN_D_PIN, INPUT_PULLUP);
  pinMode(MOTOR_GATE_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  Serial.begin(9600);
}

int currentSpeed = 0;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_RED_PIN, LOW);

  
  if(digitalRead(BTN_I_PIN) == LOW){
    if(currentSpeed < 255){
      currentSpeed ++;
      digitalWrite(LED_GREEN_PIN, HIGH);
    }else{
      digitalWrite(LED_RED_PIN, HIGH);
    }
  }

  if(digitalRead(BTN_D_PIN) == LOW){
    if(currentSpeed != 0){
      currentSpeed --;
      digitalWrite(LED_GREEN_PIN, HIGH);
    }else{
      digitalWrite(LED_RED_PIN, HIGH);
    }
  }

  analogWrite(MOTOR_GATE_PIN, currentSpeed);
  Serial.println(currentSpeed);
}
