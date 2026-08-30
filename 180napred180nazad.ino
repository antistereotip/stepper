#include <Stepper.h>

const int stepsPerRevolution = 2048;

// IN1, IN3, IN2, IN4
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  motor.setSpeed(10); // brzina u RPM
}

void loop() {
  // Okreni 180 stepeni
  motor.step(1024);

  delay(1000);

  // Vrati se 180 stepeni
  motor.step(-1024);

  delay(1000);
}
