// Hardware-target firmware. NOT compiled or tested on a physical board.
// ESP32 GPIO21 SDA, GPIO22 SCL. BME280 breakout powered from 3.3 V.
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <math.h>

Adafruit_BME280 bme;
bool sensorReady = false;
unsigned long nextSample = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  sensorReady = bme.begin(0x76, &Wire) || bme.begin(0x77, &Wire);
  if (!sensorReady) Serial.println("{\"type\":\"error\",\"message\":\"BME280 not detected\"}");
}

void loop() {
  if (millis() < nextSample) return;
  nextSample = millis() + 2000;
  if (!sensorReady) return;
  const float t = bme.readTemperature();
  const float h = bme.readHumidity();
  const float p = bme.readPressure() / 100.0f;
  if (!isfinite(t) || !isfinite(h) || !isfinite(p)) {
    Serial.println("{\"type\":\"error\",\"message\":\"Invalid sensor reading\"}");
    return;
  }
  Serial.printf("{\"type\":\"reading\",\"temperature_c\":%.2f,\"humidity_percent\":%.2f,\"pressure_hpa\":%.2f}\n", t, h, p);
}
