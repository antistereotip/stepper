#include <Stepper.h>

const int stepsPerRevolution = 2048;

// Povezivanje:
// IN1 -> D8
// IN2 -> D9
// IN3 -> D10
// IN4 -> D11
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  motor.setSpeed(10);  // brzina u RPM
}

void loop() {

  // Okreni 90 stepeni
  motor.step(512);
  delay(3000);

  // Okreni još 180 stepeni
  motor.step(1024);
  delay(3000);

  // Okreni još 360 stepeni
  motor.step(2048);
  delay(3000);
}


// START
//   ↓
// +90°  → čekaj 3 sekunde
//   ↓
// +180° → čekaj 3 sekunde
//  ↓
// +360° → čekaj 3 sekunde
//   ↓
// ponovo +90°
