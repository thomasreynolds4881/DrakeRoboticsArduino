// Author: Thomas Reynolds
// sources:
// https://medium.com/arduino-playground/checking-for-a-button-press-in-arduino-7681cbb7bde7
// https://arduino.stackexchange.com/questions/186/button-state-changing-randomly

#define LED 4
#define BUTTON 8

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600); // Don't think I ever brought this up but Arduino IDE has a way to "print" stuff using Serial
}

void loop() {
  if(buttonPressed(BUTTON)) {
    Serial.println("Button pressed");
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
  }
  delay(1);
}

int buttonPressed(uint8_t button) {
  static uint16_t lastStates = 0; // uint16_t is a 16 bit integer
  uint8_t state = digitalRead(button);
  if (state != ((lastStates >> button) & 1)) {
    lastStates ^= 1 << button;
    return state == HIGH;
  }
  return false;
}
