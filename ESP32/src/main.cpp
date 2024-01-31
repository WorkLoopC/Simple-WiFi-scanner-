#include <Arduino.h>
#include <WiFiClientSecure.h>

#define red 18
#define green 5
#define yellow 19

void setup(){
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(yellow,OUTPUT);

Serial.begin(115200);
WiFi.mode(WIFI_STA); //basically used to connect as a client to existing wifi
WiFi.disconnect(); //disconnects from previously connected wifi network
delay(1000);
}

void loop(){
Serial.println("Scanning networks");
digitalWrite(red,HIGH);
digitalWrite(green,LOW);
int scan=WiFi.scanNetworks(); //Returns a number the total number of networks found
if(scan!=0){
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
Serial.print(scan);
Serial.println("Network(s) found");
for(int i=0; i<scan;++i){
  Serial.print("network");
  Serial.println(i + 1);
  Serial.print(": ");
  Serial.print(WiFi.SSID(i)); //Name of network
  Serial.print(" (");
  Serial.print (WiFi.RSSI(i)); //How strong the signal is ,the closer to 0 the better
  Serial.print(")");
  Serial.println((WiFi.encryptionType(i)== WIFI_AUTH_OPEN)? " open ":" protected"); //If connection is protected than print "protected",if open than print "open"
  delay(100);
  }
}
else{
  Serial.println("No signal"); //Incase there is no avaiable signal
  digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
}
Serial.println("----------------------------");
delay(5000);
}