#include <SPI.h>
#include <MFRC522.h>
int count = 0;
#include <LiquidCrystal.h>
const int rs = 8, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//LiquidCrystal lcd(7,6,5,4,3,2); //replex 6 into 8
//LiquidCrystal lcd(A5,A4,A3,A2,A1,A0); //replex 6 into 8
#include <VarSpeedServo.h> 

VarSpeedServo servo1;
const int servopin = 6;
  
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 2 //define green LED pin
#define LED_R 3 //define red LED
#define BUZZER 4 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

 
void setup() 
{
   lcd.begin(16,2);
  lcd.print("RFID attendance");
   servo1.attach(servopin);
   servo1.write(70,10,true);
//servo1.write(0,60,true);
 
  
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
 

  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "C0 88 17 A4") 
  {
    servo1.write(10,70,true);
  delay(3000);
  servo1.write(70,10,true);
     delay(500);
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
      lcd.clear(); 
    count++;                    // Increment Count by 1
      lcd.setCursor(1, 0);
      lcd.print("Subas is Present");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(400);
  }
   if (content.substring(1) == "6A 22 5D 74") 
  {
      servo1.write(10,70,true);
  delay(3000);
  servo1.write(70,10,true);
     delay(1000);
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
      lcd.clear(); 
    count++;                    // Increment Count by 1
      lcd.setCursor(1, 0);
      lcd.print("VC Sir is Present");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(400);
  }
   
if (content.substring(1) == "27 DB 3E 65") 
  {
      servo1.write(10,70,true);
  delay(3000);
  servo1.write(70,10,true);
     delay(1000);
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
      lcd.clear(); 
    count++;                    // Increment Count by 1
      lcd.setCursor(1, 0);
      lcd.print("Imarn is Present");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(400);
  }
 if (content.substring(1) == "E3 28 96 BB") 
  {
      servo1.write(10,70,true);
  delay(3000);
  servo1.write(70,10,true);
     delay(1000);
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
      lcd.clear(); 
    count++;                    // Increment Count by 1
      lcd.setCursor(1, 0);
      lcd.print("Shikha is Present ");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(400);
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
} 


