#include <Stepper.h>

const int stepsPerRevolution = 2048;

// IN1, IN3, IN2, IN4 za ULN2003
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

const int angle = 30;
const int stepsPerMove = stepsPerRevolution / 12;

void setup() {
  motor.setSpeed(10); // RPM
}

void loop() {

  // 12 puta po 30° = 360°
  for (int i = 0; i < 12; i++) {

    // Pomeri motor za 30°
    motor.step(stepsPerMove);

    // Zaustavi se na 1 sekundu
    delay(1000);
  }

  // Nakon 360° napravi pauzu
  delay(1000);
}
