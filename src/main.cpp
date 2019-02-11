#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 8
#define DHTTYPE DHT11
#define ledPin 13
DHT dht(DHTPIN,DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(ledPin,OUTPUT);
}


void loop()
{
    digitalWrite(ledPin,HIGH);
    delay(1000);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println("%");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println("°C");
    Serial.println();
    digitalWrite(ledPin,LOW);
    delay(1000);
}
