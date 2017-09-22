/* Amp Pot B5K (B5K) [S027] : http://rdiot.tistory.com/190 [RDIoT] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
Servo myservo; 
int servoPin = 12;
int potPin = A0;
int val;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  myservo.attach(servoPin); 
  delay(1000);

  lcd.clear();
}

void loop()
{

  val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 179);
 
  lcd.setCursor(0,0);
  lcd.print("S027:B5K");

  myservo.write(val);
  lcd.setCursor(0,1);
  lcd.print("pos0~179=" + (String)val + "  " );

  delay(10); 
}
