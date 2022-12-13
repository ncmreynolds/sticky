uint8_t numberOfAxis = 6;
uint8_t axisGpioPin[6] = { 36, 39, 34, 35, 32, 33 };
uint8_t numberOfButtons = 12;
uint8_t buttonGpioPin[12] = {25, 26, 27, 14, 12, 13, 15, 2, 0, 4, 16, 17};


void setup() {
  Serial.begin(115200);
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);  
  for(uint8_t pin = 0; pin < numberOfAxis; pin++)
  {
    Serial.print(F("Axis "));
    Serial.print(pin);
    Serial.print(F(" pin: "));
    Serial.println(axisGpioPin[pin]);
    pinMode(axisGpioPin[pin],INPUT);
  }
  for(uint8_t pin = 0; pin < numberOfButtons; pin++)
  {
    Serial.print(F("Button "));
    Serial.print(pin);
    Serial.print(F(" pin: "));
    Serial.println(axisGpioPin[pin]);
    pinMode(buttonGpioPin[pin],INPUT_PULLUP);
  }
}

void loop() {
  for(uint8_t pin = 0; pin < numberOfAxis; pin++)
  {
    Serial.print(F("Axis "));
    Serial.print(pin);
    Serial.print(F(" value: "));
    Serial.print(analogRead(axisGpioPin[pin]));
    Serial.print(' ');
  }
  Serial.println();
  for(uint8_t pin = 0; pin < numberOfButtons; pin++)
  {
    Serial.print(F("Button "));
    Serial.print(pin);
    Serial.print(F(" value: "));
    Serial.print(not digitalRead(buttonGpioPin[pin]));
    Serial.print(' ');
  }
  Serial.println();
  delay(100);
}
