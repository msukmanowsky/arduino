/**
 * Arduino Starter Project #3 - Colour Mixing Lamp
 *
 * Video at https://www.youtube.com/watch?v=u9uc92ae6WY
 *
 * Author: Mike Sukmanowsky <mike.sukmanowsky@gmail.com>
 */

/* Constants */
const int SERIAL_SAMPLE_RATE = 9600;

const int RED_LED_PIN = 10;
const int GREEN_LED_PIN = 9;
const int BLUE_LED_PIN = 11;
const int RED_SENSOR_PIN = A0;
const int GREEN_SENSOR_PIN = A1;
const int BLUE_SENSOR_PIN = A2;


/* Globals */
int redAmount = 0;
int greenAmount = 0;
int blueAmount = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

/* Setup / Loop*/
void setup() {
  // open serial port and sample analog input
  Serial.begin(SERIAL_SAMPLE_RATE);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}


void loop() {
  redSensorValue = analogRead(RED_SENSOR_PIN);
  delay(5);
  greenSensorValue = analogRead(GREEN_SENSOR_PIN);
  delay(5);
  blueSensorValue = analogRead(BLUE_SENSOR_PIN);
  delay(5);

  Serial.print("Raw sensor values\nRed: ");
  Serial.print(redSensorValue);
  Serial.print("\nGreen: ");
  Serial.print(greenSensorValue);
  Serial.print("\nBlue: ");
  Serial.print(blueSensorValue);
  Serial.print("\n\n");

  redAmount = redSensorValue / 4;
  greenAmount = greenSensorValue / 4;
  blueAmount = blueSensorValue / 4;

  Serial.print("Mapped sensor values\nRed: ");
  Serial.print(redAmount);
  Serial.print("\nGreen: ");
  Serial.print(greenAmount);
  Serial.print("\nBlue: ");
  Serial.print(blueAmount);
  Serial.print("\n\n");

  analogWrite(RED_LED_PIN, redAmount);
  analogWrite(GREEN_LED_PIN, greenAmount);
  analogWrite(BLUE_LED_PIN, blueAmount);
}
