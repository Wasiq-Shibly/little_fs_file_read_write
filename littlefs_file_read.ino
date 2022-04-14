#include "LittleFS.h"
String wifi_name,wifi_pass,wifi_data; 
void setup() {
Serial.begin(115200);
LittleFS.begin();

  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;        
 }
 
File file;

file = LittleFS.open("/wifi.txt", "w");
file.println("first password");

file.println("second password");
file.println("third password");
file.close();


file = LittleFS.open("/wifi.txt", "r");
  while(file.available()){
  wifi_name=((file.readStringUntil('\n')));
   wifi_pass=((file.readStringUntil('\n')));
   wifi_data=((file.readStringUntil('\n')));
  }

  file.close();
 Serial.println("data1");
  Serial.println(wifi_name);
   Serial.println("data2");
  Serial.println(wifi_pass);
   Serial.println("data3");
    Serial.println(wifi_data);
  LittleFS.end();


}
 
void loop() {

}
