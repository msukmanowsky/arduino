/**
 * Arduino Starter Project #1 - Spaceship Interface
 * Super simple circiut, check to see if a switch is pressed, if so then flash
 * consecutive LEDs, if not, display only a single LED. Three LEDs are intended
 * to be green, yellow red.
 *
 * Video at https://www.youtube.com/watch?v=ZcSfFx3W02o
 *
 * Author: Mike Sukmanowsky <mike.sukmanowsky@gmail.com>
 */

/* Constants */
const int SWITCH_INPUT = 2;
const int GREEN_LED = 3;
const int YELLOW_LED = 4;
const int RED_LED = 5;
const int DELAY = 100; // milliseconds


/* Setup / Loop*/
void setup() {
  pinMode(SWITCH_INPUT, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  boolean switchPressed = digitalRead(SWITCH_INPUT) == HIGH;

  // GREEN always starts on
  digitalWrite(GREEN_LED, HIGH);

  if (switchPressed) {
    // Blink the other LEDs on a delay
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
