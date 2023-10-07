#define PIN_D1 5  // gpio5 = D1  PWM_A
#define PIN_D2 4  // gpio4 = D2  PWM_B
#define PIN_D3 0  // gpio0 = D3  DA (A- A+) connected to motor (LEDs)
#define PIN_D4 2  // gpio2 = D4  DB (B- B+) connected to motor
#define TRIG_PIN 14 // gpio14
#define ECHO_PIN 12 // gpio12


void setup() {
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D2, OUTPUT);
  pinMode(PIN_D3, OUTPUT);
  pinMode(PIN_D4, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(1 );
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the distance
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2; // in cm

  if (distance > 10) {
    // Move the robot forward
    digitalWrite(PIN_D1, HIGH);  // PWM_A HIGH
    digitalWrite(PIN_D2, HIGH);  // PWM_B HIGH
    digitalWrite(PIN_D3, HIGH);  // DA HIGH
    digitalWrite(PIN_D4, HIGH);  // DB HIGH
    digitalWrite(15, LOW);
    digitalWrite(13, LOW);
  } else {
    // Stop the robot
    digitalWrite(PIN_D1, LOW);  // PWM_A LOW
    digitalWrite(PIN_D2, LOW);  // PWM_B LOW
    digitalWrite(PIN_D3, LOW);  // DA LOW
    digitalWrite(PIN_D4, LOW);  // DB LOW
    digitalWrite(15, HIGH);
    digitalWrite(13, HIGH);
  }
}
