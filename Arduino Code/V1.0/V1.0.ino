int but1 = 12;
int but2 = 11;
int but3 = 10;
int led1 = 5;
int led2 = 3;
int led3 = 6;
int rly1 = 9;
int rly2 = 7;
int rly3 = 8;

#define minTimeRly1 1000 //The minimum number of ms that the relay for channel 1 stays on and off. (to prevent turning on
// and off like 10 times a second, which is bad for the electronics that are connected. For example, the clock may have a smaller min time than a monitor.)
#define minTimeRly2 30000
#define minTimeRly3 1000
#define fadeSpeed 30 //in percent
#define targetBrightness 255 //The brigness of leds when on. a number from 0-255. 0 is off, 255 is full on.
#define offBrightness 0 //The brigness of leds when off. a number from 0-255. 0 is off, 255 is full on.


enum stateEnum {
  on,
  turningOn,
  off,
  turningOff
};

class LEDcontroller {
  public:
    int selectedLED;
    stateEnum state;
    unsigned long long int lastOnTime;
    unsigned long long int lastOffTime;
    unsigned long long int lastIncreaseTime;
    unsigned long long int lastDecreaseTime;
    int brightness;



    LEDcontroller(int ledNum) {
      switch(ledNum) {
        case 1:
          selectedLED = led1;
          break;
        case 2:
          selectedLED = led2;
          break;
        case 3:
          selectedLED = led3;
          break;
      }

      digitalWrite(selectedLED, LOW);
      brightness = offBrightness;
      state = off;
      lastOffTime = millis();
    }

    void applyBrightness() {
      analogWrite(selectedLED, brightness);
    }

    void increaseBrightness() {
      //imcrease brightness
      brightness += 1;
    }

    void decreaseBrightness() {
      brightness -= 1;
    }
};






LEDcontroller LED1(1);
LEDcontroller LED2(2);
LEDcontroller LED3(3);
int fadeInterval;

void setup() {
  Serial.begin(9600);
  pinMode(but1, INPUT_PULLUP); //channel 1 button
  pinMode(but2, INPUT_PULLUP); //channel 2 button
  pinMode(but3, INPUT_PULLUP); //channel 3 button

  pinMode(led1, OUTPUT); //channel 1 LED
  pinMode(led2, OUTPUT); //channel 2 LED
  pinMode(led3, OUTPUT); //channel 3 LED

  pinMode(rly1, OUTPUT); //cahnnel 1 out
  pinMode(rly2, OUTPUT);; //channel 2 out
  pinMode(rly3, OUTPUT); //channel 3 out

  fadeInterval = map(fadeSpeed, 0, 100, 10, 0);

  delay(1000); //prevents premature execution of loop()
}

void loop() {

//Turn on led1 and rly1 when but1 is pressed.
  LED1.applyBrightness();
  if ((LED1.state == off) && (digitalRead(but1) == LOW) && ((millis() - LED1.lastOffTime) > minTimeRly1)) {
    //if the led was off more more than 1s and you press the button...
    //This is essentially the criteria that decides we now process to fading on the button.

    digitalWrite(rly1, HIGH); //turn on relay now (before led fully turns on)
    //keep track of parameters.
    LED1.state = turningOn;
  }

  if (LED1.state == turningOn){
    //increase brightness at a given interval until we are at our decided brightness level

    if ((LED1.brightness < targetBrightness) && ((millis() - LED1.lastIncreaseTime) > fadeInterval)){
      LED1.increaseBrightness();
      LED1.lastIncreaseTime = millis();
    }

    else if (LED1.brightness == targetBrightness) {
      //Once at full brightness
      LED1.state = on;
      LED1.lastOnTime = millis();
    }
  }

  if ((LED1.state == on) && (digitalRead(but1) == HIGH) && ((millis() - LED1.lastOnTime) > minTimeRly1)) {
    //if the led was on more more than 1s and you press the button...
    //This is essentially the criteria that decides we now process to fading off the button.

    digitalWrite(rly1, LOW); //turn off relay now (before led fully turns off)
    //keep track of parameters.
    LED1.state = turningOff;
  }

  if (LED1.state == turningOff){
    //increase brightness at a given interval until we are at our decided brightness level

    if ((LED1.brightness > offBrightness) && ((millis() - LED1.lastDecreaseTime) > fadeInterval)){
      LED1.decreaseBrightness();
      LED1.lastDecreaseTime = millis();
    }

    else if (LED1.brightness == offBrightness) {
      //Once at full brightness
      LED1.state = off;
      LED1.lastOffTime = millis();
    }
  }

//Turn on led2 and rly2 when but2 is pressed.
  LED2.applyBrightness();
  if ((LED2.state == off) && (digitalRead(but2) == LOW) && ((millis() - LED2.lastOffTime) > minTimeRly2)) {
    //if the led was off more more than 1s and you press the button...
    //This is essentially the criteria that decides we now process to fading on the button.

    digitalWrite(rly2, HIGH); //turn on relay now (before led fully turns on)
    //keep track of parameters.
    LED2.state = turningOn;
  }

  if (LED2.state == turningOn){
    //increase brightness at a given interval until we are at our decided brightness level

    if ((LED2.brightness < targetBrightness) && ((millis() - LED2.lastIncreaseTime) > fadeInterval)){
      LED2.increaseBrightness();
      LED2.lastIncreaseTime = millis();
    }

    else if (LED2.brightness == targetBrightness) {
      //Once at full brightness
      LED2.state = on;
      LED2.lastOnTime = millis();
    }
  }

  if ((LED2.state == on) && (digitalRead(but2) == HIGH) && ((millis() - LED2.lastOnTime) > minTimeRly2)) {
    //if the led was on more more than 1s and you press the button...
    //This is essentially the criteria that decides we now process to fading off the button.

    digitalWrite(rly2, LOW); //turn off relay now (before led fully turns off)
    //keep track of parameters.
    LED2.state = turningOff;
  }

  if (LED2.state == turningOff){
    //increase brightness at a given interval until we are at our decided brightness level

    if ((LED2.brightness > offBrightness) && ((millis() - LED2.lastDecreaseTime) > fadeInterval)){
      LED2.decreaseBrightness();
      LED2.lastDecreaseTime = millis();
    }

    else if (LED2.brightness == offBrightness) {
      //Once at full brightness
      LED2.state = off;
      LED2.lastOffTime = millis();
    }
  }

//Turn on led3 and rly3 when but3 is pressed.
  LED3.applyBrightness();
  if ((LED3.state == off) && (digitalRead(but3) == LOW) && ((millis() - LED3.lastOffTime) > minTimeRly3)) {
    //if the led was off more more than 1s and you press the button...
    //This is essentially the criteria that decides we now process to fading on the button.

    digitalWrite(rly3, HIGH); //turn on relay now (before led fully turns on)
    //keep track of parameters.
    LED3.state = turningOn;
  }

  if (LED3.state == turningOn){
    //increase brightness at a given interval until we are at our decided brightness level

    if ((LED3.brightness < targetBrightness) && ((millis() - LED3.lastIncreaseTime) > fadeInterval)){
      LED3.increaseBrightness();
      LED3.lastIncreaseTime = millis();
    }

    else if (LED3.brightness == targetBrightness) {
      //Once at full brightness
      LED3.state = on;
      LED3.lastOnTime = millis();
    }
  }

  if ((LED3.state == on) && (digitalRead(but3) == HIGH) && ((millis() - LED3.lastOnTime) > minTimeRly3)) {
    //if the led was on more more than 1s and you press the button...
    //This is essentially the criteria that decides we now process to fading off the button.

    digitalWrite(rly3, LOW); //turn off relay now (before led fully turns off)
    //keep track of parameters.
    LED3.state = turningOff;
  }

  if (LED3.state == turningOff){
    //increase brightness at a given interval until we are at our decided brightness level

    if ((LED3.brightness > offBrightness) && ((millis() - LED3.lastDecreaseTime) > fadeInterval)){
      LED3.decreaseBrightness();
      LED3.lastDecreaseTime = millis();
    }

    else if (LED3.brightness == offBrightness) {
      //Once at full brightness
      LED3.state = off;
      LED3.lastOffTime = millis();
    }
  }
  

}
