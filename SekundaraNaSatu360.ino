#include <Stepper.h>

const int stepsPerRevolution = 2048;

// ULN2003:
// IN1 -> D8
// IN2 -> D9
// IN3 -> D10
// IN4 -> D11
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

// 5 stepeni ≈ 28.4 koraka
const int stepsPer5 = 28;

void setup() {
  motor.setSpeed(10);
}

void loop() {

  // =========================
  // 360° U JEDNOM SMERU
  // =========================

  for (int i = 0; i < 72; i++) {

    motor.step(stepsPer5);

    delay(1000);  // 1 sekunda
  }


  // =========================
  // 360° U SUPROTNOM SMERU
  // =========================

  for (int i = 0; i < 72; i++) {

    motor.step(-stepsPer5);

    delay(1000);  // 1 sekunda
  }
}
