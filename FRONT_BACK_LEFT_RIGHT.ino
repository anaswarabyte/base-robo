#define PIN_D1 5  // gpio5 = D1  PWM_A
#define PIN_D2 4  // gpio4 = D2  PWM_B
#define PIN_D3 0  // gpio0 = D3  DA (A- A+) connected to motor (LEDs)
#define PIN_D4 2  // gpio2 = D4  DB (B- B+) connected to motor

void setup() {
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D2, OUTPUT);
  pinMode(PIN_D3, OUTPUT);
  pinMode(PIN_D4, OUTPUT);
  
}

void loop() {
  // Drive forward
  digitalWrite(PIN_D1, HIGH);  // PWM_A HIGH
  digitalWrite(PIN_D2, HIGH);  // PWM_B HIGH
  digitalWrite(PIN_D3, HIGH);  // DA HIGH
  digitalWrite(PIN_D4, HIGH);  // DB HIGH
  delay(5000);  // Wait for 5 seconds

  // Stop
  digitalWrite(PIN_D1, LOW);  // PWM_A LOW
  digitalWrite(PIN_D2, LOW);  // PWM_B LOW
  digitalWrite(PIN_D3, LOW);  // DA LOW
  digitalWrite(PIN_D4, LOW);  // DB LOW
  delay(2000);  // Wait for 2 seconds

  // Drive backward
  digitalWrite(PIN_D1, HIGH);   // PWM_A LOW
  digitalWrite(PIN_D2, HIGH);   // PWM_B LOW
  digitalWrite(PIN_D3, LOW);   // DA LOW
  digitalWrite(PIN_D4, LOW);   // DB LOW
  delay(5000);  // Wait for 5 seconds

  // Stop
  digitalWrite(PIN_D1, LOW);  // PWM_A LOW
  digitalWrite(PIN_D2, LOW);  // PWM_B LOW
  digitalWrite(PIN_D3, LOW);  // DA LOW
  digitalWrite(PIN_D4, LOW);  // DB LOW
  delay(2000);  // Wait for 2 seconds

  // Drive left
  digitalWrite(PIN_D1, HIGH);  // PWM_A HIGH
  digitalWrite(PIN_D2, HIGH);   // PWM_B LOW
  digitalWrite(PIN_D3, LOW);   // DA LOW
  digitalWrite(PIN_D4, HIGH);  // DB HIGH
  delay(5000);  // Wait for 5 seconds

  // Stop
  digitalWrite(PIN_D1, LOW);  // PWM_A LOW
  digitalWrite(PIN_D2, LOW);  // PWM_B LOW
  digitalWrite(PIN_D3, LOW);  // DA LOW
  digitalWrite(PIN_D4, LOW);  // DB LOW
  delay(2000);  // Wait for 2 seconds

  // Drive right
  digitalWrite(PIN_D1, HIGH);   // PWM_A LOW
  digitalWrite(PIN_D2, HIGH);  // PWM_B HIGH
  digitalWrite(PIN_D3, HIGH);  // DA HIGH
  digitalWrite(PIN_D4, LOW);   // DB LOW
  delay(5000);  // Wait for 5 seconds

  // Stop
  digitalWrite(PIN_D1, LOW);  // PWM_A LOW
  digitalWrite(PIN_D2, LOW);  // PWM_B LOW

  delay(2000);  // Wait for 2 seconds
  
  digitalWrite(4, HIGH); // Turn on the LED
  delay(50); // Wait for 1 second
  digitalWrite(4, LOW); // Turn off the LED
  delay(50); // Wait for 1 second
}
