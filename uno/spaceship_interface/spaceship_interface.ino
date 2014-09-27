const int SWITCH_INPUT = 2;
const int GREEN_LED = 3;
const int YELLOW_LED = 4;
const int RED_LED = 5;
const int DELAY = 100; // milliseconds

boolean switchPressed = false;

void setup() {
  pinMode(SWITCH_INPUT, INPUT);
  
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  switchPressed = digitalRead(2) == HIGH;
  
  // GREEN always starts on
  digitalWrite(GREEN_LED, HIGH);
  
  if (switchPressed) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    delay(DELAY);
    
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    delay(DELAY);
    
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(DELAY);

  } else {
    // Only display GREEN
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }
}
