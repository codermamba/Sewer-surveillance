#include "DHT.h"
#define DHTPIN 9
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int water_o, mq2_o, mq135_o, dht11_o;
int mq2 = 2, mq135 = 5, dht11 = 9, water = 11;
String csv;
void setup() {
  pinMode(mq2,INPUT_PULLUP);  // MQ2 SENSOR 
  pinMode(3,OUTPUT);          // MQ2 SENSOR GND
  digitalWrite(3,LOW);
  pinMode(4,OUTPUT);          // MQ2 SENSOR VCC
  digitalWrite(4,HIGH);
  pinMode(mq135,INPUT_PULLUP);// MQ135 SENSOR
  pinMode(6,OUTPUT);          // MQ135 SENSOR GND
  digitalWrite(6,LOW);
  pinMode(7,OUTPUT);          // MQ135 SENSOR VCC
  digitalWrite(7,HIGH);
  pinMode(8,OUTPUT);          // DHT11 SENSOR VCC
  digitalWrite(8,HIGH);
  pinMode(dht11,INPUT_PULLUP);// DHT11 SENSOR
  pinMode(10,OUTPUT);         // DHT11 SENSOR GND
  digitalWrite(10,LOW);
  pinMode(water,INPUT_PULLUP);// WATER SENSOR 
  pinMode(12,OUTPUT);         //WATER SENSOR VCC
  digitalWrite(12,HIGH);
  Serial.begin(9600);
  dht.begin();
  delay(2000); // The whole system starts after 2 seconds.
}

void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  water_o = digitalRead(water);
  mq2_o = digitalRead(mq2);
  mq135_o = digitalRead(mq135);
  Serial.println(String(water_o)+","+String(mq2_o)+","+String(mq135_o)+","+String(h)+","+String(t));
  delay(700);
}
