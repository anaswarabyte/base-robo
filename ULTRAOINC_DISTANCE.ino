#define TRIGGER_PIN 5 // Pin for the ultrasonic sensor trigger
#define ECHO_PIN 4   // Pin for the ultrasonic sensor echo

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(TRIGGER_PIN, INPUT);
  pinMode(ECHO_PIN, OUTPUT);
  
}

void loop() {
  // Send a pulse to the ultrasonic sensor to start a measurement
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Measure the duration of the pulse from the ultrasonic sensor
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance based on the duration of the pulse
  float distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Wait for 1 second before taking another measurement

  
}
