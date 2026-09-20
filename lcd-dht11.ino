#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 7
#define DHTTYPE DHT11
#define BTN_TOGGLE 8
#define BTN_RESET 9
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN , DHTTYPE);
// reading variables
float temperature , humidity;

// Variables
float tempSum = 0;
float tempMin , tempMax;
unsigned long samples = 0;
byte screen = 0;
// Reading Timer
unsigned long lastRead = 0;
// Last button STATE
bool lastToggle = HIGH;
bool lastReset = HIGH;
void resetStatistics(float t)
{
   tempSum = t; humSum = g
   samples = 1;
   tempMin = tempMax = t;
   humMin = humMax = h;
}
void setup ()
{
   lcd.begin (16, 2);
   dht.begin ();

   pinMode(BTN_TOGGLE , INPUT_PULLUP);
   pinMode(BTN_RESET , INPUT_PULLUP);
   temperature = dht.readTemperature ();
   humidity = dht.readHumidity ();
   if (! isnan(temperature)) resetStatistics(temperature); // inicializar estatisticas com o primeiro valor lido
   lcd.clear ();
}
void loop()
{
// reading time of DTH11 = 2sec
   if (millis()-lastRead >=2000){
   lastRead = millis ();
   float t = dht.readTemperature ();
   float h = dht.readHumidity ();
   if (! isnan(t) && !isnan(h))
{
   temperature = t;
   humidity = h;
   tempSum += t;
   samples ++;
   if (t < tempMin){
      tempMin = t;
   }
   if (t > tempMax){
      tempMax = t;
   }
}
}
   float avgTemp = tempSum / samples;
   float avgHum = tempHum / samples;
// Botão de mudança de ecrã
   bool toggle = digitalRead(BTN_TOGGLE);
   if (lastToggle == HIGH && toggle == LOW){
      screen ++;
      if (screen > 3){
         screen = 0;
      }
   lcd.clear ();
   delay (50);
   }
   lastToggle = toggle;
// Botão de reset
   bool reset = digitalRead(BTN_RESET);
   if (lastReset == HIGH && reset == LOW){
      resetStatistics(temperature);
      lcd.clear ();
      delay (1000);
   }
   lastReset = reset;
   switch (screen){
      case 0: // Ecra Inicial (mostra T e H atuais)
      lcd.setCursor (0, 0);
      lcd.print("Temp:");
      lcd.print(temperature , 1);
      lcd.print ((char)223);
      lcd.print("C ");
      lcd.setCursor (0, 1);
      lcd.print("Hum :");
      lcd.print(humidity , 1);

   lcd.print("% ");
   break;

   case 1: // Ecra de T e H média
   lcd.setCursor (0, 0);
   lcd.print("Avg T:");
   lcd.print(avgTemp, 1);
   lcd.print((char)223);
   lcd.print("C ");
   lcd.setCursor(0, 1);
   lcd.print("Avg H:");
   lcd.print(avgHum, 1);
   break;

   case 2: // Ecra de T mínima
   lcd.setCursor (0, 0);
   lcd.print("Temp. Minima");
   lcd.print(tempMin);
   break;

   case 3: // Ecra de T máxima
   lcd.setCursor (0, 0);
   lcd.print("Temp. Maxima");
   lcd.print(tempMax);
   break;
   }
}
