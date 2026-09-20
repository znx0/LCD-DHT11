#define BTN 3
unsigned long count = 0;
bool lastState = HIGH;

void setup (){
   Serial.begin (9600);
   pinMode(BTN , INPUT_PULLUP);
}

void loop(){
   bool state = digitalRead(BTN);
   if (lastState == HIGH && state == LOW){
      count ++;
      Serial.println(count);
      delay (100);
   }

   lastState = state;
}
