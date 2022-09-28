// DHT11 - Digital Humidity Temperature Sensor
// Vcc - 5V, GND - GND, Data - P22

// Humidity - Relative Humidity - 40
// Temperature - Celsius - 25

#include "DHT.h"

DHT dht11(22,DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht11.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float humidity=dht11.readHumidity();
  float temperature=dht11.readTemperature();

  if(isnan(humidity) || isnan(temperature)) 
    return;

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(", Temperature: ");
  Serial.println(temperature);
  delay(4000); // 4000ms - 4seconds
}
