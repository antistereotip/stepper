// =====================================================
// Arduino UNO + 28BYJ-48 + ULN2003
// 360° napred -> 360° nazad -> pauza 3 sekunde
// =====================================================

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// 28BYJ-48 u half-step režimu
// Početna vrednost za jedan puni krug
#define STEPS_PER_REV 4096

// Brzina motora
#define STEP_DELAY 2

// Half-step sekvenca
const byte sequence[8][4] = {
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


// =====================================================
// Jedan korak
// direction = 1  -> napred
// direction = -1 -> nazad
// =====================================================

void stepMotor(int direction)
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

  delay(STEP_DELAY);
}


// =====================================================
// Iskljuci motor
// =====================================================

void motorOff()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// =====================================================
// Setup
// =====================================================

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  motorOff();

  delay(1000);
}


// =====================================================
// Loop
// =====================================================

void loop()
{
  // ---------------------------------------------
  // 360° NAPRED
  // ---------------------------------------------

  for (int i = 0; i < STEPS_PER_REV; i++)
  {
    stepMotor(1);
  }

  motorOff();

  delay(500);


  // ---------------------------------------------
  // 360° NAZAD
  // ---------------------------------------------

  for (int i = 0; i < STEPS_PER_REV; i++)
  {
    stepMotor(-1);
  }

  motorOff();


  // ---------------------------------------------
  // PAUZA 3 SEKUNDE
  // ---------------------------------------------

  delay(3000);
}
