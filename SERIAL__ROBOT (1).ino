#define PIN_D1 5  // gpio5 = D1  PWM_A
#define PIN_D2 4  // gpio4 = D2  PWM_B
#define PIN_D3 0  // gpio0 = D3  DA (A- A+) подключается двигатель (светодиоды)
#define PIN_D4 2  // gpio2 = D4  DB (B- B+) подключается двигатель

void setup() 
{
  pinMode(PIN_D1, OUTPUT); // инициализируем Pin как выход
  pinMode(PIN_D2, OUTPUT); // инициализируем Pin как выход
  pinMode(PIN_D3, OUTPUT); // инициализируем Pin как выход
  pinMode(PIN_D4, OUTPUT); // инициализируем Pin как выход

  Serial.begin(9600);      // инициализация связи с последовательным портом
}

void loop()
{
  if (Serial.available() > 0)   // если есть данные в Serial Monitor
  {
    char command = Serial.read(); // читаем символ

    if (command == 'f')   // если введено "f"
    {
      digitalWrite(PIN_D1, HIGH);   // PWM_A HIGH
      digitalWrite(PIN_D3, HIGH);   // DA HIGH
      digitalWrite(PIN_D2, HIGH);   // PWM_B HIGH
      digitalWrite(PIN_D4, HIGH);   // DB HIGH
      delay(5000);                  // wait for 5 seconds
    }
    else if (command == 's')   // если введено "s"
    {
      digitalWrite(PIN_D1, LOW);    // PWM_A LOW
      digitalWrite(PIN_D3, LOW);    // DA LOW
      digitalWrite(PIN_D2, LOW);    // PWM_B LOW
      digitalWrite(PIN_D4, LOW);    // DB LOW
      delay(2000);                  // wait for 2 seconds
    }
    else if (command == 'r')   // если введено "r"
    {
      digitalWrite(PIN_D1, HIGH);    // PWM_A LOW
      digitalWrite(PIN_D3, LOW);   // DA HIGH
      digitalWrite(PIN_D2, HIGH);    // PWM_B LOW
      digitalWrite(PIN_D4, LOW);   // DB HIGH
      delay(5000);                  // wait for 5 seconds
    }
  }
}
