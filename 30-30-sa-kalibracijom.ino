// ============================================================
// Arduino UNO + 28BYJ-48 + ULN2003
// HOME senzor + pomeranje 30 stepeni napred/nazad
// ============================================================

// ULN2003 -> Arduino
#define STEPPER_PIN_1 8
#define STEPPER_PIN_2 9
#define STEPPER_PIN_3 10
#define STEPPER_PIN_4 11

// HOME mikroprekidac / senzor
#define HOME_PIN 2

// ------------------------------------------------------------
// 28BYJ-48
// Broj koraka za jedan puni krug.
// Za ovu konfiguraciju koristimo 4096 koraka / 360°.
// ------------------------------------------------------------
#define STEPS_PER_REV 4096

// 30 stepeni
#define STEPS_30_DEG  (STEPS_PER_REV / 12)

// Brzina motora
#define STEP_DELAY 2

// Maksimalan broj koraka tokom trazenja HOME
#define MAX_HOME_STEPS 5000

// ------------------------------------------------------------
// HALF-STEP sekvenca za 28BYJ-48
// ------------------------------------------------------------
const byte stepSequence[8][4] = {
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

// ------------------------------------------------------------
// Jedan korak
// direction = 1  -> napred
// direction = -1 -> nazad
// ------------------------------------------------------------
void singleStep(int direction)
{
  stepIndex += direction;

  if (stepIndex > 7)
    stepIndex = 0;

  if (stepIndex < 0)
    stepIndex = 7;

  digitalWrite(STEPPER_PIN_1, stepSequence[stepIndex][0]);
  digitalWrite(STEPPER_PIN_2, stepSequence[stepIndex][1]);
  digitalWrite(STEPPER_PIN_3, stepSequence[stepIndex][2]);
  digitalWrite(STEPPER_PIN_4, stepSequence[stepIndex][3]);

  delay(STEP_DELAY);
}

// ------------------------------------------------------------
// Iskljucivanje zavojnica
// ------------------------------------------------------------
void motorOff()
{
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
}

// ------------------------------------------------------------
// Provera HOME senzora
// Koristimo INPUT_PULLUP.
// Senzor mora spojiti D2 na GND kada je aktivan.
// ------------------------------------------------------------
bool homeDetected()
{
  return digitalRead(HOME_PIN) == LOW;
}

// ------------------------------------------------------------
// TRAZENJE HOME POZICIJE
// ------------------------------------------------------------
void findHome()
{
  Serial.println("Trazenje HOME pozicije...");

  int counter = 0;

  // Ako je senzor vec aktivan,
  // prvo se malo udaljimo od njega.
  if (homeDetected())
  {
    Serial.println("HOME senzor je vec aktivan.");

    for (int i = 0; i < 100; i++)
    {
      singleStep(-1);
    }
  }

  // Sada trazimo HOME
  while (!homeDetected() && counter < MAX_HOME_STEPS)
  {
    singleStep(1);
    counter++;
  }

  // Zaustavi motor
  motorOff();

  if (homeDetected())
  {
    Serial.println("HOME pronadjen!");
    Serial.println("Pozicija = 0 stepeni");
  }
  else
  {
    Serial.println("GRESKA: HOME nije pronadjen!");
  }
}

// ------------------------------------------------------------
// Pomeranje za odredjeni broj koraka
// ------------------------------------------------------------
void moveSteps(int steps, int direction)
{
  for (int i = 0; i < steps; i++)
  {
    singleStep(direction);
  }

  motorOff();
}

// ------------------------------------------------------------
// SETUP
// ------------------------------------------------------------
void setup()
{
  Serial.begin(9600);

  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);

  pinMode(HOME_PIN, INPUT_PULLUP);

  motorOff();

  delay(1000);

  Serial.println();
  Serial.println("==============================");
  Serial.println("28BYJ-48 SISTEM");
  Serial.println("==============================");

  // Prvo obavezno kalibracija
  findHome();

  delay(1000);
}

// ------------------------------------------------------------
// LOOP
// ------------------------------------------------------------
void loop()
{
  // ----------------------------------------------------------
  // 30 stepeni NAPRED
  // ----------------------------------------------------------
  Serial.println("30 stepeni NAPRED");

  moveSteps(STEPS_30_DEG, 1);

  delay(1000);


  // ----------------------------------------------------------
  // 30 stepeni NAZAD
  // ----------------------------------------------------------
  Serial.println("30 stepeni NAZAD");

  moveSteps(STEPS_30_DEG, -1);

  delay(1000);
}
