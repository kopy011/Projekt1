
#define LED_1 9
#define BTN 12
#define BTN_2 11

byte state;
byte prevState;
byte state2;
byte prevState2;
signed short light;
signed short mode;

void setup() {
  // put your setup code here, to run once:
  pinMode(BTN,INPUT);
  pinMode(LED_1,OUTPUT);
  pinMode(BTN_2,INPUT);
  digitalWrite(LED_1,HIGH);
  state = HIGH;
  prevState = HIGH;
  state2 = HIGH;
  prevState2 = HIGH;
  light = -1;
  mode = -1;
}

void loop() {
  state = digitalRead(BTN);
  state2 = digitalRead(BTN_2);
  if(prevState == HIGH && state == LOW){
      mode = -mode;
  }
  if(prevState2 == HIGH && state2 == LOW){
      light = -light;
  }

  if(mode == -1){
    vilagit(light);
  } else {
    pulzal(light);
  }
  
  prevState = state;
  prevState2 = state2;
}

void vilagit(signed short light){
  if(light == -1){
    digitalWrite(LED_1,HIGH);
  } else {
    digitalWrite(LED_1,LOW);
    delay(100);
    digitalWrite(LED_1,HIGH);
    delay(100);
  }

}

void pulzal(signed short light){

  
  int intensity;

  if(light == -1){
    digitalWrite(LED_1,HIGH);
  } else {
    for (intensity = 255; intensity >= 5; intensity -= 5)
    {
      analogWrite(LED_1,intensity);
      delay(10);
    }
  
    //Cycle to decrease the intensity level. Note that the LEDs operate with inverse logic.
    for (intensity = 0; intensity <= 250; intensity += 5)
    {
      analogWrite(LED_1,intensity);
      delay(10);
    }  
  }
}
