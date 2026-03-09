
int dataPin = 13;
int clockPin = 11;
int latchPin = 12;
int pedGreen = 4;
int pedRed = 10;
int Buzzer = 9;
int pedButton = 8;

int carGreen = 7;
int carYellow = 6;
int carRed = 5;

unsigned long changeTime;

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  pinMode(pedRed, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(pedButton, INPUT);

  pinMode(carGreen, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carRed, OUTPUT);

  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
}

void loop()
{
  int state = digitalRead(pedButton);

  if (state == HIGH && (millis() - changeTime) > 8000) {
    ChangeLights();
  }
}

void enviarLeds(uint16_t valor)
{
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, highByte(valor));
  shiftOut(dataPin, clockPin, MSBFIRST, lowByte(valor));

  digitalWrite(latchPin, HIGH);
}

void ChangeLights()
{
  
  digitalWrite(carGreen, LOW);
  digitalWrite(carYellow, HIGH);
  delay(3000);

  
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(2000);

  
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);

  
  tone(Buzzer, 3000);
  delay(300);
  noTone(Buzzer);
  delay(300);
  tone(Buzzer, 3000);
  delay(300);
  noTone(Buzzer);

  
  for (int i = 10; i >= 0; i--) {

    uint16_t leds = (1 << i) - 1;

    enviarLeds(leds);

    
    if (i <= 3 && i > 0) {
      tone(Buzzer, 3000);
      delay(150);
      noTone(Buzzer);
      delay(850);
    } else {
      delay(1000);
    }
  }
  digitalWrite(pedGreen, LOW);

  
  for(int i = 0; i < 4; i++) {
    digitalWrite(pedRed, HIGH);
    tone(Buzzer, 3000);
    delay(400);
    digitalWrite(pedRed, LOW);
    noTone(Buzzer);
    delay(400);
  }

  digitalWrite(pedRed, HIGH);

  delay(1000);

  digitalWrite(carRed, LOW);
  digitalWrite(carGreen, HIGH);

  changeTime = millis();
}
