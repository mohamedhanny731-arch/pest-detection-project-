#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

const int AD8232_PIN = A0; 
const int MQ135_PIN = A1;
const int MQ3_PIN = A2;
const int MQ2_PIN = A3;

Adafruit_BME280 bme; 

unsigned long previousMillisVOC = 0;
const long vocInterval = 1000;

void setup() {
  Serial.begin(115200);
  pinMode(AD8232_PIN, INPUT);
  
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  unsigned long currentMillis = millis();
  
  int emgValue = analogRead(AD8232_PIN);
  
  Serial.print("E:");
  Serial.println(emgValue);
  
  if (currentMillis - previousMillisVOC >= vocInterval) {
    previousMillisVOC = currentMillis;
    
    int mq135 = analogRead(MQ135_PIN);
    int mq3 = analogRead(MQ3_PIN);
    int mq2 = analogRead(MQ2_PIN);
    float temp = bme.readTemperature();
    float hum = bme.readHumidity();
    
    Serial.print("V:");
    Serial.print(mq135); Serial.print(",");
    Serial.print(mq3); Serial.print(",");
    Serial.print(mq2); Serial.print(",");
    Serial.print(temp); Serial.print(",");
    Serial.println(hum);
  }
  
  delayMicroseconds(1000); 
}
