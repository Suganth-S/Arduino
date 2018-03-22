#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);   //defining lcd pins

int value=0;            //initializing variables
float volts=0.0;      
float temp=0.0;      
float tempF=0.0;

void setup()
{
 
 Serial.begin(9600);
  lcd.begin(16,2);      // set up the LCD's number of columns and rows
 
 }
void loop(){
 
  value=analogRead(A0);          //read from A0
  volts=(value/1024.0)*5.0;      //conversion to volts
  temp= volts*100.0;             //conversion to temp Celsius
  tempF=temp*9/5+32;             //conversion to temp Fahrenheit

//display temp no lcd

  Serial.print("temperature= "); 
  Serial.println(temp);
  //lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  lcd.print(tempF);
  lcd.print(" F");
  delay(500);

}

 
