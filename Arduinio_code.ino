
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int Relay_PIN = 7;
const int LED_PIN = 6;
const int Voltage_PIN = A0;

void setup() {
  pinMode(Relay_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  lcd.begin(20, 4);
  lcd.setCursor(0,0);
  lcd.print("  THE BRIGHT LIGHT ");
  lcd.setCursor(0,1);
  lcd.print(" VOLTAGE PROTECTION ");
}

void loop() {
  int sensorValue = analogRead(Voltage_PIN);
  float Voltage = (sensorValue * 5.0 / 1023.0) * 100; //converting analog voltage to digital

  lcd.setCursor(0,2);
  lcd.print("   VOLTAGE = ");
  lcd.print(Voltage);
  lcd.print("V");

  if (Voltage >= 180 && Voltage <= 250) {
    digitalWrite(Relay_PIN, HIGH);
    digitalWrite(LED_PIN, LOW);
    lcd.setCursor(0,3);
    lcd.print("   NORMAL VOLTAGE   ");
  } else if (Voltage > 250) {
    digitalWrite(Relay_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);
    lcd.setCursor(0,3);
    lcd.print("    OVER VOLTAGE   ");
  } else {
    digitalWrite(Relay_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);
    lcd.setCursor(0,3);
    lcd.print("    UNDER VOLTAGE   ");
  }
  delay(200);
}
