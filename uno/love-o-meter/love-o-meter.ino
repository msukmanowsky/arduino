/**
 * Arduino Starter Project #2 - Love-o-Meter
 * Users a TMP36 sensor to detect temperature, then microcontroller logic uses
 * TMP36's analog input to control 3 LEDs.
 *
 * Video at https://www.youtube.com/watch?v=8UcjhftcKxo
 */

/* Constants */
const int SERIAL_SAMPLE_RATE = 9600; // bits per second
const int TEMP_SENSOR_PIN = A0;
const int SAMPLES_FOR_BASELINE = 1000;
const int FIRST_THRESHOLD = 2; // +2 degrees over room temp
const int SECOND_THRESHOLD = 4; // 4 degrees over room temp

/* Globals */
float temp_baseline;  // room temperature, established at setup

/* Functions */

/**
 * Converts an analog input from a TMP36 (http://arduino.cc/documents/datasheets/TEMP-TMP35_36_37.pdf)
 * sensor into degrees celsius.
 * @param sensorVal the raw sensor value from the analog pin.
 * @return the sensor value converted to degrees in celsius.
 */
float sensorToCelsius(int sensorVal) {
  float voltage = (sensorVal / 1024.0) * 5.0;
  return (voltage - 0.5) * 100;
}


/* Setup / Loop*/
void setup() {
  // open serial port and sample analog input
  Serial.begin(SERIAL_SAMPLE_RATE);

  // Take 1000 samples of temp sensor to establish baseline
  Serial.print("Determining room temperature using ");
  Serial.print(SAMPLES_FOR_BASELINE);
  Serial.print(" samples.\n");
  for (int count = 0; count < SAMPLES_FOR_BASELINE; count++) {
    temp_baseline += analogRead(TEMP_SENSOR_PIN);
  }
  temp_baseline = sensorToCelsius((int)(temp_baseline / SAMPLES_FOR_BASELINE));
  Serial.print("Room temperature established: ");
  Serial.print(temp_baseline);
  Serial.print(" degrees celsius.\n");

  for (int pin = 2; pin <= 4; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}


void loop() {
  int sensorVal = analogRead(TEMP_SENSOR_PIN);
  float temperature = sensorToCelsius(sensorVal);

  if (temperature < temp_baseline) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= temp_baseline && temperature < temp_baseline + FIRST_THRESHOLD) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= temp_baseline + FIRST_THRESHOLD && temperature < temp_baseline + SECOND_THRESHOLD) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= temp_baseline + SECOND_THRESHOLD) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1);
}
