// Semáforo inteligente para pedestres

int dataPin = 13;
int clockPin = 11;
int latchPin = 12;

int pedRed = 10;
int buzzer = 9;
int pedButton = 8;

int carGreen = 7;
int carYellow = 6;
int carRed = 5;

unsigned long changeTime;

void setup() {

  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  pinMode(pedRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pedButton, INPUT);

  pinMode(carGreen, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carRed, OUTPUT);

  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
}

void loop() {

  int state = digitalRead(pedButton);

  if (state == HIGH && (millis() - changeTime) > 8000) {
    changeLights();
  }
}

void sendLeds(uint16_t value) {

  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, highByte(value));
  shiftOut(dataPin, clockPin, MSBFIRST, lowByte(value));

  digitalWrite(latchPin, HIGH);
}

void changeLights() {

  // carro verde -> amarelo
  digitalWrite(carGreen, LOW);
  digitalWrite(carYellow, HIGH);
  delay(3000);

  // carro amarelo -> vermelho
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(2000);

  // pedestre pode atravessar
  digitalWrite(pedRed, LOW);

  // aviso sonoro inicial
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);

  // barra de LEDs (contagem regressiva)
  for (int i = 10; i >= 0; i--) {

    uint16_t leds = (1 << i) - 1;
    sendLeds(leds);

    delay(1000);
  }

  // aviso de fechamento
  for (int i = 0; i < 4; i++) {

    digitalWrite(pedRed, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(400);

    digitalWrite(pedRed, LOW);
    digitalWrite(buzzer, LOW);
    delay(400);
  }

  digitalWrite(pedRed, HIGH);

  delay(1000);

  digitalWrite(carRed, LOW);
  digitalWrite(carGreen, HIGH);

  changeTime = millis();
}
