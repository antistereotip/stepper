#include <Stepper.h>

const int stepsPerRevolution = 2048;

// IN1, IN3, IN2, IN4
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

const int stepsPer90 = 512;

void setup() {
  motor.setSpeed(10);  // brzina motora
}

void loop() {

  // 0° -> 90°
  motor.step(stepsPer90);
  delay(2000);

  // 90° -> 180°
  motor.step(stepsPer90);
  delay(2000);

  // 180° -> 270°
  motor.step(stepsPer90);
  delay(2000);

  // 270° -> 360°
  motor.step(stepsPer90);
  delay(2000);

  // Kada stigne do 360°, čeka 3 sekunde
  delay(3000);
}
