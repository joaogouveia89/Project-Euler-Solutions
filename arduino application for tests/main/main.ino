#include <LiquidCrystal.h>
#define START_LED 7
#define FINISHED_LED 8
#define LCD_RS 12
#define LCD_EN 12
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2 

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void exec(){
  //here goes the function
}

void writeLcd(long time){
  lcd.print(time);
}

void setup() {
   pinMode(START_LED, OUTPUT);
   pinMode(FINISHED_LED, OUTPUT);
   lcd.begin(16, 2);
}

void loop() {
  digitalWrite(START_LED, HIGH);
  digitalWrite(FINISHED_LED, LOW);
  unsigned long startTime = millis();
  exec();
  unsigned long endTime = millis();
  digitalWrite(START_LED, LOW);
  digitalWrite(FINISHED_LED, HIGH);
  writeLcd((endTime-startTime));
}
