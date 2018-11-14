#include <LiquidCrystal.h>
#include<math.h>
#define START_LED 7
#define FINISHED_LED 8
#define LCD_RS 12
#define LCD_EN 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2 
#define GOAL 10001

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

int isPrime(unsigned int n){
    unsigned int idx;
    for(idx = 2; idx <= sqrt(n); idx++){
        if(n % idx == 0){
            return 0;
        }
    }
    return 1;
}

void exec(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Starting...");
  int nPrimeNumber = 1;
    unsigned int current = 2;

    while(nPrimeNumber != GOAL){
        current++;
        if(isPrime(current) == 1){
            nPrimeNumber++;
        }
    }
}

void writeLcd(long time){
  lcd.clear();
  lcd.setCursor(0, 0);
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
  while(true){
    
  }  
}
