const int trigPin = D1; // Trigger pin of the ultrasonic sensor
const int echoPin = D2; // Echo pin of the ultrasonic sensor

void setup() {
  Serial.begin(115200); // Start serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration on the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  long distance = duration / 58.2;

  // Print the distance to the Serial Monitor
  if (distance >= 2 && distance <= 400) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.println("Out of range");
  }

  delay(500); // Wait for a moment before taking the next measurement
}
