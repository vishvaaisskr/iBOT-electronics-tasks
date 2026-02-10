#include <DHT.h>

DHT dht(4, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("  Humidity: ");
  Serial.println(h);

  delay(1000);
}
