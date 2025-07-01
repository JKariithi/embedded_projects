const int ledPin = 23;       
const int buttonPin = 15;

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  digitalWrite(ledPin, ledState);
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  // Detect falling edge (button press)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    ledState = !ledState;               // Toggle LED state
    digitalWrite(ledPin, ledState);
  }

  lastButtonState = currentButtonState;
  delay(50);  // Debounce delay
}
