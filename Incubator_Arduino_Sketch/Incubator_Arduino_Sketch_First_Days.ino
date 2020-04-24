/*   
 
 Hardware Connections (HTU21D to Arduino):
 -VCC = 3.3V
 -GND = GND
 -SDA = A4 (use inline 330 ohm resistor if your board is 5V)
 -SCL = A5 (use inline 330 ohm resistor if your board is 5V)

 */

 /*
  For first 18 days
  Temperature : 99.5 to 100 degree farenhiet = 37.5 to 37.7 degree celcius
  37.5 is ideal. Do not allow 102 degree farenheit ( 38.8 celcius ) for too long
  Let our temperature be from 37.5 to 38 degrees.

  Humidity: 50 to 55
  Let our humidity be 53 with 2 as variance
 */

#include <Wire.h>
#include "SparkFunHTU21D.h"
#include<LiquidCrystal.h>

#define FAN 7
#define HEAT 8
#define HUMIDITY 9
#define HUM_BUTTON 10

float thigh = 38;
float tlow = 37.5;
float hhigh = 54;
float hlow = 51;

int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Create an instance of the object
HTU21D myHumidity;

void setup()
{
  analogWrite(6, Contrast);
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("HTU21D Example!");

  myHumidity.begin();

  pinMode(FAN, OUTPUT);
  pinMode(HEAT, OUTPUT);
  pinMode(HUMIDITY, OUTPUT);
  pinMode(HUM_BUTTON, OUTPUT);
}

boolean humidifier_on = false;
boolean temperature_on = false;
int humidifier_timer = 0;

// Function to turn on fan and humidifier
void turnOnHumidifier() {
  digitalWrite(FAN, HIGH);
  digitalWrite(HUMIDITY, HIGH);
  delay(3000);
  digitalWrite(HUM_BUTTON, HIGH);
  delay(500);
  digitalWrite(HUM_BUTTON, LOW);
  humidifier_on = true;
  humidifier_timer = 0; // reset humidifier timer
}

// Function to turn off fan and humidifier
void turnOffHumidifier() {
  // turn off fan only if heater/light is also off
  if(temperature_on == false) {
    digitalWrite(FAN, LOW);
  }
  digitalWrite(HUMIDITY, LOW);
  humidifier_on = false;
  humidifier_timer = 0; // reset humidifier timer
}

// Function to turn on light and fan
void turnOnTemperature() {
  digitalWrite(HEAT, HIGH);
  digitalWrite(FAN, HIGH);
  temperature_on = true;
}

// Function to turn off light and fan
void turnOffTemperature() {
  // turn off fan only if humidifier is also off
  if(humidifier_on == false) {
    digitalWrite(FAN, LOW);
  }
  digitalWrite(HEAT, LOW);
  temperature_on = false;
}

void loop()
{
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hum:");
  lcd.print(humd);
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print(temp);

  Serial.print("Time:");
  Serial.print(millis());
  Serial.print(" Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");

  /********* HUMIDITY SECTION ***********/

  // count humidifier timer
  if(humidifier_on == true) {
    humidifier_timer++;
  }

  // after 30 seconds, give the timer a rest; this will still cause the timer to run
  if(humidifier_timer > 30) {
    digitalWrite(HUMIDITY, LOW);
  }

  // turn on the humidifier after a 10 second rest
  if(humidifier_timer > 40) {
    turnOnHumidifier();
  }

  // turn on fan and humidifier
  if(humd <= hlow) {
    if(humidifier_on == false) {
      turnOnHumidifier();
    }
  }
  
  // turn off fan and humidifier
  if(humd >= hhigh) {
    if(humidifier_on == true) {
      turnOffHumidifier();
    }
  }

  /******************************************/

  /********* TEMPERATURE SECTION ***********/

  // increase temperature if it is low
  if(temp <= tlow) {
    turnOnTemperature();
  }

  // turn off light and fan if temperature has reached higher limit
  if(temp >= thigh) {
    turnOffTemperature();
  }
  
  /******************************************/

  Serial.println();
  delay(1000);
}
