#define TEMP_PIN A0  // TMP36 analog output connected to A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(TEMP_PIN);           // Read analog value (0–1023)
  float voltage = sensorValue * (5.0 / 1023.0);      // Convert to voltage (0–5V)
  float temperatureC = (voltage - 0.5) * 100.0;      // TMP36 formula for °C

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000);  // Wait for 1 second
}
