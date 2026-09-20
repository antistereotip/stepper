// ============================================================
// 28BYJ-48 + ULN2003 + Arduino UNO
//
// 45° napred:
// 10 sekundi
//  7 sekundi
//  4 sekunde
//  2 sekunde
//
// Zatim 45° nazad:
//  2 sekunde
//  4 sekunde
//  7 sekundi
// 10 sekundi
//
// Ciklus se ponavlja
// ============================================================

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// 28BYJ-48 HALF-STEP
#define STEPS_PER_REV 4096

// 360 / 8 = 45 stepeni
#define STEPS_45_DEG (STEPS_PER_REV / 8)

// Half-step sekvenca
const byte sequence[8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

int stepIndex = 0;


// ============================================================
// Jedan korak
// ============================================================

void stepMotor(int direction, int stepDelay)
{
  stepIndex += direction;

  if (stepIndex > 7)
    stepIndex = 0;

  if (stepIndex < 0)
    stepIndex = 7;

  digitalWrite(IN1, sequence[stepIndex][0]);
  digitalWrite(IN2, sequence[stepIndex][1]);
  digitalWrite(IN3, sequence[stepIndex][2]);
  digitalWrite(IN4, sequence[stepIndex][3]);

  delay(stepDelay);
}


// ============================================================
// Iskljucivanje motora
// ============================================================

void motorOff()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// ============================================================
// 45 stepeni u odredjenom vremenu
// ============================================================

void move45(int direction, unsigned long duration)
{
  // Izracunavamo koliko vremena imamo za svaki korak
  int stepDelay = duration / STEPS_45_DEG;

  // Sigurnost da delay ne bude 0
  if (stepDelay < 1)
    stepDelay = 1;

  for (int i = 0; i < STEPS_45_DEG; i++)
  {
    stepMotor(direction, stepDelay);
  }
}


// ============================================================
// SETUP
// ============================================================

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  motorOff();

  delay(1000);
}


// ============================================================
// GLAVNI CIKLUS
// ============================================================

void loop()
{
  // ----------------------------------------------------------
  // NAPRED
  // ----------------------------------------------------------

  move45(1, 10000);   // 45° za 10 sekundi

  move45(1, 7000);    // 45° za 7 sekundi

  move45(1, 4000);    // 45° za 4 sekunde

  move45(1, 2000);    // 45° za 2 sekunde


  // ----------------------------------------------------------
  // NAZAD
  // ----------------------------------------------------------

  move45(-1, 2000);   // 45° za 2 sekunde

  move45(-1, 4000);   // 45° za 4 sekunde

  move45(-1, 7000);   // 45° za 7 sekundi

  move45(-1, 10000);  // 45° za 10 sekundi


  // ----------------------------------------------------------
  // Sada se loop automatski ponavlja
  // ----------------------------------------------------------
}
