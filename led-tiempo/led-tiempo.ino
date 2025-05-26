const int PIN_LED_RED = 13;
const int PIN_LED_GREEN = 12;
const int PIN_BTN = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_BTN, INPUT_PULLUP);
}

int lastStateBtn = HIGH;
bool runningCount = false;
unsigned long timeStart;
unsigned long timeEnd;


void loop() {
  // put your main code here, to run repeatedly:
  int currentStateBtn = digitalRead(PIN_BTN);

  if(lastStateBtn == HIGH && currentStateBtn == LOW ){
    delay(50),;
    if(runningCount){
      timeEnd = millis();
      float finalTime = (timeEnd - timeStart) / 1000.0;
      Serial.print("TIEMPO: ");
      Serial.print(finalTime, 2);
      Serial.println("s\n");
      digitalWrite(PIN_LED_GREEN, LOW);
    }else{
      timeStart = millis();
      digitalWrite(PIN_LED_GREEN, HIGH);
    }
    runningCount = !runningCount;
  }

  if(currentStateBtn == LOW && !runningCount){
    digitalWrite(PIN_LED_RED, HIGH);
  }else{
    digitalWrite(PIN_LED_RED, LOW);
  }

  lastStateBtn = currentStateBtn;
}
