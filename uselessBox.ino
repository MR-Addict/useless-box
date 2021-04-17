#include <Servo.h>

Servo myservo_1;
const int SwitchPin = 4;

void setup() {
  pinMode(SwitchPin, INPUT_PULLUP);
  myservo_1.attach(6);
  myservo_1.write(2);
}

void loop() {
  boolean SwitchStatus = digitalRead(SwitchPin);
  if (SwitchStatus) {
    switch(random(4)){
      case 0:Style_1();break;
      case 1:Style_2();break;
      case 2:Style_3();break;
      case 3:Style_4();break;
    }
  }
}

void ARM_UP(int MIN, int MAX) {
  for (int pos = MIN; pos <= MAX; pos ++) {
    myservo_1.write(pos);
    delay(10);
  }
}

void ARM_DOWN(int MAX, int MIN) {
  for (int pos = MAX; pos >= MIN; pos --) {
    myservo_1.write(pos);
    delay(10);
  }
}

void Style_1() {
  ARM_UP(2, 65);
  ARM_DOWN(65, 2);
}

void Style_2() {
  ARM_UP(2, 40);
  ARM_DOWN(40, 2);
  delay(1000);
  ARM_UP(2, 65);
  ARM_DOWN(65, 2);
}

void Style_3() {
  ARM_UP(2, 65);
  ARM_DOWN(65, 2);
  delay(1000);
  ARM_UP(2, 40);
  delay(1000);
  ARM_DOWN(40, 2);
}

void Style_4() {
  for (int i = 0; i < 3; i++) {
    ARM_UP(2, 40);
    ARM_DOWN(40, 2);
  }
  delay(1000);
  ARM_UP(2, 65);
  ARM_DOWN(65, 2);
}
