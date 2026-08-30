#include <Stepper.h>

const int stepsPerRevolution = 2048;

// ULN2003:
// IN1 -> D8
// IN2 -> D9
// IN3 -> D10
// IN4 -> D11
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

// 10 stepeni ≈ 57 koraka
const int stepsPer10 = 57;

void setup() {
  motor.setSpeed(10);
}

void loop() {

  // 36 puta po 10° = 360°
  for (int i = 0; i < 36; i++) {

    // Okreni 10° U DESNO
    motor.step(stepsPer10);

    // Pauza 2 sekunde
    delay(2000);
  }

  // Posle 360° ponovo kreće ciklus
}
