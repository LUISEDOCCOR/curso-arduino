//https://www.tinkercad.com/things/dhfJuUQJJkw-piano?sharecode=OGXa2JlUrFn7D4LakswA2yvufy9J1a1LdXx6MzWzIkU
const int BTNS_PIN[] = {13,12,11,10,9,8,7,6};
const int BELL_PIN = 3;
const int SCALE[] = {
  262, // Do
  294, // Re
  330, // Mi
  349, // Fa
  392, // Sol
  440, // La
  494, // Si
  523  // Do
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < 8; i++){
    pinMode(BTNS_PIN[i], INPUT_PULLUP);
  }
}

bool curretnStatusBtn = false;

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 8; i++){
    if(digitalRead(BTNS_PIN[i]) == LOW){
      curretnStatusBtn = true;
      tone(BELL_PIN, SCALE[i], 1000);
      break;
    }else{
      curretnStatusBtn = false;
    }
  }

  if(!curretnStatusBtn){
    noTone(BELL_PIN);
  }

}
