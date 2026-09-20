#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 2 //  digital pin 2 conected to DHT11

DHT dht(DHTPIN , DHTTYPE);
unsigned long lastRead = 0;
float temperature;
float humidity;

void setup (){
   Serial.begin (9600);
   dht.begin ();
}

void loop(){
   if (millis () - lastRead >= 2000){
   lastRead = millis ();
   float t = dht.readTemperature ();
   float h = dht.readHumidity ();
   if (! isnan(t) && !isnan(h)){
      temperature = t;
      humidity = h;
   }
   Serial.print(F("Temperature: "));
   Serial.print(temperature);
   Serial.print(F(" Humidity: "));
   Serial.print(humidity);
   Serial.println(F("%"));
   }
}
