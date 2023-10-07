#define PIN_D1 5  // gpio5 = D1  PWM_A
#define PIN_D2 4  // gpio4 = D2  PWM_B
#define PIN_D3 0  // gpio0 = D3  DA (A- A+) connected to motor (LEDs)
#define PIN_D4 2  // gpio2 = D4  DB (B- B+) connected to motor
#define TRIG_PIN 14  // gpio12 = D6  Trig pin of Ultrasonic Sensor
#define ECHO_PIN 12  // gpio13 = D7  Echo pin of Ultrasonic Sensor

void setup() {
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D2, OUTPUT);
  pinMode(PIN_D3, OUTPUT);
  pinMode(PIN_D4, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Measure distance with ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  float distance_cm = pulseIn(ECHO_PIN, HIGH) / 58.0;

  // Move robot forward if distance is less than 10 cm, else stop
  if (distance_cm < 10) {
    digitalWrite(PIN_D1, HIGH);  // PWM_A HIGH
    digitalWrite(PIN_D2, HIGH);  // PWM_B HIGH
    digitalWrite(PIN_D3, HIGH);  // DA HIGH
    digitalWrite(PIN_D4, HIGH);  // DB HIGH
  } else {
    digitalWrite(PIN_D1, LOW);  // PWM_A LOW
    digitalWrite(PIN_D2, LOW);  // PWM_B LOW
    digitalWrite(PIN_D3, LOW);  // DA LOW
    digitalWrite(PIN_D4, LOW);  // DB LOW
  }
}
