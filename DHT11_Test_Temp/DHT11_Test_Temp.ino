#include "DHT.h"
#define DHTPIN D4 //PIN D4
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(115200);
Serial.println("DHT Connected!!!");
dht.begin();
}

void loop() {
delay(2000);  // หน่วงเวลา 2 วินาทีให้เซนเซอร์ทำงาน
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   float f = dht.readTemperature(true);
   
// เช็คถ้าอ่านค่าไม่สำเร็จให้เริ่มอ่านใหม่
if (isnan(h) || isnan(t) || isnan(f)) {
Serial.println("Failed to read from DHT sensor!");  
return;
}

Serial.print("Humidity: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.print(" *C ");
Serial.print(f);
Serial.print(" *F\t\n");
}
