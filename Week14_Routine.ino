#include <Wire.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 

String Dates[] = 
{
  "Sun, 20 Jul 2025",
  "Mon, 21 Jul 2025",
  "Tue, 22 Jul 2025",
  "Wed, 23 Jul 2025",
  "Wed, 23 Jul 2025",
  "Thu, 24 Jul 2025",
  "Thu, 24 Jul 2025",
  "Thu, 24 Jul 2025",
};

String Task[] = 
{
  "Algo Quiz",
  "NM Lab Final",
  "Regular Classes",
  "Algo Lab Final",
  "NM Assign Due",
  "Math Assign Due",
  "GED Assign Due",
  "Math CT"
};


int TotalTasks = 8;

void setup() 
{
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("WiFi Scanning...");
  delay(1000);

  int n = WiFi.scanNetworks();

  lcd.clear();
  if (n == 0) 
  {
    lcd.setCursor(0, 0);
    lcd.print("No WiFi Found");
    delay(1000);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Week 14");
  lcd.setCursor(0, 1);
  delay(1000);
}

void loop() 
{
  for (int i = 0; i < TotalTasks; i++) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(Dates[i]);

    lcd.setCursor(0, 1);
    lcd.print(Task[i]);
    delay(2000);
  }
}
