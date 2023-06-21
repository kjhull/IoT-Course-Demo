#include "DHT.h"
#include <WiFi.h>
#include "ThingSpeak.h"

#define DHTPIN 13        // Digital pin connected to the DHT sensor
#define LEDPin 34        //LED Connection
#define DHTTYPE DHT22    // DHT 22

const char* ssid = "ESP32pleasework";   // your network SSID (name) 
const char* pass = "Mango130";   // your network password

DHT dht(DHTPIN, DHTTYPE);

WiFiClient  client;

unsigned long myChannelNumber = 1742416;
const char * myWriteAPIKey = "FEZK7OO590RYWDV6";

void setup() {
  Serial.begin(9600);
  Serial.println(F("ESP32 to ThingSpeak"));
  dht.begin();

  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
  // Wait a few seconds between measurements.
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
  
  delay(15000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));

  ThingSpeak.setField(3, t);
  ThingSpeak.setField(4, h);

  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  

}
