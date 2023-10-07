#define PIN_D1 5  // gpio5 = D1  PWM_A
#define PIN_D2 4  // gpio4 = D2  PWM_B
#define PIN_D3 0  // gpio0 = D3  DA (A- A+) connected to motor (LEDs)
#define PIN_D4 2  // gpio2 = D4  DB (B- B+) connected to motor

#define TRIGGER_PIN 14  // gpio14   D5
#define ECHO_PIN 12  // gpio12 D6

#define DIST_THRESHOLD 10 // Distance threshold in centimeters

void setup() {
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D2, OUTPUT);
  pinMode(PIN_D3, OUTPUT);
  pinMode(PIN_D4, OUTPUT);
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Send a 10us pulse to trigger the ultrasonic sensor
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Measure the distance
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration / 58; // Calculate distance in cm
  
  // Check if the distance is less than the threshold
  if (distance < DIST_THRESHOLD) {
    // Obstacle detected, stop the robot
    digitalWrite(PIN_D1, LOW);  // PWM_A LOW
    digitalWrite(PIN_D2, LOW);  // PWM_B LOW
    delay(2000);  // Wait for 2 seconds
    
    // Turn right to avoid the obstacle
    digitalWrite(PIN_D1, HIGH);  // PWM_A HIGH
    digitalWrite(PIN_D2, LOW);   // PWM_B LOW
    digitalWrite(PIN_D3, LOW);   // DA LOW
    digitalWrite(PIN_D4, HIGH);  // DB HIGH
    delay(3000);  // Wait for 1 second
  } else {
    // No obstacle, move forward
    digitalWrite(PIN_D1, HIGH);  // PWM_A HIGH
    digitalWrite(PIN_D2, HIGH);  // PWM_B HIGH
    digitalWrite(PIN_D3, HIGH);  // DA HIGH
    digitalWrite(PIN_D4, HIGH);  // DB HIGH
  }
}
