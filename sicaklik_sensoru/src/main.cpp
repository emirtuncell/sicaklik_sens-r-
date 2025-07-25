#include <Arduino.h>

#include <DHT.h>

#define DHTPIN 4      // DHT11 veri pini (GPIO4'e bağlı)
#define DHTTYPE DHT11 // Sensör tipi DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);
  dht.begin();
}

float temperature;
float humidity;

void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("SENSÖR VERİ ALMIYOR.");
  }
  else
  {
    Serial.printf("SICAKLIK: %f DERECE \n", temperature);
    Serial.printf("NEM: Yüzde %f", humidity);
  }

  delay(2000);
}

// 2 saniye bekle
