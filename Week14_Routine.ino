#include<Wire.h>
#include<WiFi.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

String dates[] =
{
  "Sun, 20 Jul",
  "Mon, 21 Jul",
  "Tue, 22 Jul",
  "Wed, 23 Jul",
  "Wed, 23 Jul",
  "Thu, 24 Jul",
  "Thu, 24 Jul",
  "Thu, 24 Jul",
};

String tasks[] =
{
  "Algo Quiz",
  "NM Lab Final",
  "Regular Class",
  "Algo Lab Final",
  "Math Assign Due",
  "NM Assign Due",
  "GED Assign Due",
  "Math CT"
};


int n = 8;

void setup()
{
  lcd.init();
  lcd.backlight();

  lcd.print("WiFi Scanning...");
  delay(1000);

  int x = WiFi.scanNetworks();

  lcd.clear();
  if(x==0)
  {
    lcd.setCursor(0,0);
    lcd.print("No WiFi found");
    delay(1000);
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("14th Week Tasks ");
  delay(2000);
}

void loop()
{
  for(int i=0; i<n;i++)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(dates[i]);

    lcd.setCursor(0,1);
    lcd.print(tasks[i]);
    delay(3000);
  }
}
