#include <Servo.h>

Servo myservo1;
Servo myservo2;
const int Button = 2;

void setup() {
  pinMode(Button, INPUT_PULLUP);
  myservo1.attach(3);
  myservo2.attach(6);
  myservo1.write(15);
  myservo2.write(2);
}

void loop() {
  int Time_Delay;
  if (digitalRead(Button)) {
    //going up
    Time_Delay = random(1, 3);
    for (int i = myservo1.read(); i <= 90; i += Time_Delay) {
      myservo1.write(i);
      delay(15);
    }
    if (random(1, 10) % 3 == 0) {
      Time_Delay = 1;
      for (int i = myservo2.read(); i <= 30; i += Time_Delay) {
        myservo2.write(i);
        delay(15);
      }
      Time_Delay = 1;
      for (int i = myservo2.read(); i >= 2; i -= Time_Delay) {
        myservo2.write(i);
        delay(15);
      }
      delay(500);
    }
    Time_Delay = random(1, 3);
    for (int i = myservo2.read(); i <= 65; i += Time_Delay) {
      myservo2.write(i);
      delay(15);
    }

    //going down
    Time_Delay = random(1, 3);
    for (int i = myservo2.read(); i >= 2; i -= Time_Delay) {
      myservo2.write(i);
      delay(15);
    }
    Time_Delay = random(1, 3);
    for (int i = myservo1.read(); i >= 15; i -= Time_Delay) {
      myservo1.write(i);
      delay(15);
    }
    if (random(1, 10) % 4 == 0) {
      delay(1500);
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
