//https://www.tinkercad.com/things/cdnRSMcuwjX-uso-de-servo?sharecode=wOgiQovK7YIFz1lCaSEt9Kx-4JVJ126Fc_cHm8fK7Fw

#include <Servo.h>

Servo myServo;
const int LED_PIN = 13;
const int BTN_I_PIN = 8; //Aumentar
const int BTN_D_PIN = 7; //Disminuir

void setup() {
  // put your setup code here, to run once:
  //Inicializar puerto serie
  Serial.begin(9600);
  //Conexiones
  myServo.attach(6);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_I_PIN, INPUT_PULLUP);
  pinMode(BTN_D_PIN, INPUT_PULLUP);
  //Poner el servo a 90 grados
  myServo.write(90);
}

int currentPosition = 90;

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BTN_I_PIN) == LOW){
    delay(50);
    if(currentPosition < 180){
      digitalWrite(LED_PIN, LOW);
      currentPosition++;
      myServo.write(currentPosition);
    }else{
      digitalWrite(LED_PIN, HIGH);
    }
  }

   if(digitalRead(BTN_D_PIN) == LOW){
    delay(50);
    if(currentPosition > 0){
      digitalWrite(LED_PIN, LOW);
      currentPosition--;
      myServo.write(currentPosition);
    }else{
      digitalWrite(LED_PIN, HIGH);
    }
  }

  Serial.print("SERVO => ");
  Serial.println(currentPosition);
}
