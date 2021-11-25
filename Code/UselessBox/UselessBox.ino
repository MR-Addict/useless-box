#include <Servo.h>

//initlize the servo and the switch
Servo myservo1;
Servo myservo2;

const uint8_t Button = 2;

//modify the servo beginning value to fit your servo position in box
const uint8_t Servo1BeginPos = 15;
const uint8_t Servo2BeginPos = 2;

void setup() {
  pinMode(Button, INPUT_PULLUP);

  myservo1.attach(6); //servo1 attch to the back arm
  myservo2.attach(3); //servo2 attch to the front arm
  myservo1.write(Servo1BeginPos);
  myservo2.write(Servo2BeginPos);
}

void loop() {
  int Time_Delay;
  if (digitalRead(Button)) {
    //back arm go up and open the cover
    Time_Delay = random(1, 3);
    for (int i = myservo1.read(); i <= 90; i += Time_Delay) {
      myservo1.write(i);
      delay(15);
    }
    //1/3 percent that the box arm would pretent to push the switch
    if (random(1, 10) % 3 == 0) {
      Time_Delay = 2;
      for (int i = myservo2.read(); i <= 45; i += Time_Delay) {
        myservo2.write(i);
        delay(15);
      }
      delay(500);
      Time_Delay = 1;
      for (int i = myservo2.read(); i >= Servo2BeginPos; i -= Time_Delay) {
        myservo2.write(i);
        delay(15);
      }
      Time_Delay = 2;
      for (int i = myservo1.read(); i >= Servo1BeginPos; i -= Time_Delay) {
        myservo1.write(i);
        delay(15);
      }
      delay(700);
      Time_Delay = 2;
      for (int i = myservo1.read(); i <= 90; i += Time_Delay) {
        myservo1.write(i);
        delay(15);
      }
    }
    //front arm go up and push the switch
    Time_Delay = random(1, 3);
    for (int i = myservo2.read(); i <= 65; i += Time_Delay) {
      myservo2.write(i);
      delay(15);
    }

    //front arm go down first
    Time_Delay = random(1, 3);
    for (int i = myservo2.read(); i >= 2; i -= Time_Delay) {
      myservo2.write(i);
      delay(15);
    }
    //then back arm go down
    Time_Delay = random(1, 3);
    for (int i = myservo1.read(); i >= 15; i -= Time_Delay) {
      myservo1.write(i);
      delay(15);
    }
    //1/4 percent that the box pretend to show up to peep your movement
    if (random(1, 10) % 4 == 0) {
      delay(1000);
      Time_Delay = 1;
      for (int i = myservo1.read(); i <= 90; i += Time_Delay) {
        myservo1.write(i);
        delay(5);
      }
      delay(1000);
      Time_Delay = 1;
      for (int i = myservo1.read(); i >= 15; i -= Time_Delay) {
        myservo1.write(i);
        delay(15);
      }
    }
  }
}
