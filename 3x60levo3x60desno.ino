#include <Stepper.h>

const int stepsPerRevolution = 2048;

// IN1, IN3, IN2, IN4
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

// 60 stepeni = 2048 / 6 ≈ 341 korak
const int stepsPer60 = 341;

void setup() {
  motor.setSpeed(10);
}

void loop() {

  // =========================
  // 3 puta po 60° ULEVO
  // =========================

  motor.step(stepsPer60);
  delay(2000);

  motor.step(stepsPer60);
  delay(2000);

  motor.step(stepsPer60);
  delay(2000);


  // =========================
  // 3 puta po 60° UDESNO
  // =========================

  motor.step(-stepsPer60);
  delay(2000);

  motor.step(-stepsPer60);
  delay(2000);

  motor.step(-stepsPer60);
  delay(2000);


  // Pauza pre ponavljanja
  delay(3000);
}
