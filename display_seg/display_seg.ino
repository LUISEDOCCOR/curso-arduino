//https://www.tinkercad.com/things/41l6EZayNU4-display?sharecode=G-0AKbKWIwmnf4h1Qmxm9Rhe_K_dsFhAbEBnYxj4caE

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int trig_pin = 10;
const int echo_pin = 9;
long getDistance ();

LiquidCrystal_I2C lcd(32, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  //Display
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0); 
}

void loop() {
  // put your main code here, to run repeatedly:
  long distance = getDistance();
  lcd.setCursor(0, 0);
  lcd.print("DISTANCE (CM):");
  lcd.setCursor(0, 1);
  lcd.print(distance);
}

long getDistance () {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);

  return (duration * 0.0343) / 2;
}