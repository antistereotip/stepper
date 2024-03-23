// Promenljive za podešavanje stepper motora
#define STEPS_PER_REVOLUTION 200  // Broj koraka po punom krugu
#define STEPPER_PIN_1 8
#define STEPPER_PIN_2 9
#define STEPPER_PIN_3 10
#define STEPPER_PIN_4 11

// Vreme potrebno za okretanje za 30 stepeni (u milisekundama)
#define ROTATION_TIME 3000  // 3 sekunde

void setup() {
  // Postavljanje pinova stepper motora kao izlaznih
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() {
  // Okretanje u levo za 30 stepeni
  rotateLeft(120);
  delay(ROTATION_TIME);

  // Okretanje u desno za 30 stepeni
  rotateRight(120);
  delay(ROTATION_TIME);
}

// Funkcija za okretanje u levo za određeni broj stepeni
void rotateLeft(int degrees) {
  int stepsToTake = (STEPS_PER_REVOLUTION / 360.0) * degrees;
  for (int i = 0; i < stepsToTake; i++) {
    stepLeft();
    delayMicroseconds(2000);  // Pauza između koraka
  }
}

// Funkcija za okretanje u desno za određeni broj stepeni
void rotateRight(int degrees) {
  int stepsToTake = (STEPS_PER_REVOLUTION / 360.0) * degrees;
  for (int i = 0; i < stepsToTake; i++) {
    stepRight();
    delayMicroseconds(2000);  // Pauza između koraka
  }
}

// Funkcija za korak u levo
void stepLeft() {
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delayMicroseconds(2000);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delayMicroseconds(2000);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  delayMicroseconds(2000);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  delayMicroseconds(2000);
}

// Funkcija za korak u desno
void stepRight() {
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  delayMicroseconds(2000);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  delayMicroseconds(2000);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delayMicroseconds(2000);
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delayMicroseconds(2000);
}
