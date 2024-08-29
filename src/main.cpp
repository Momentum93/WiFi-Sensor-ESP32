#include <Arduino.h>
#include "WiFi.h"

#include <list>
#include <algorithm>
#include <map>

int status = WL_DISCONNECTED;

struct S_WiFi {
  String ssid;
  int rssi;
  int encrypted; 
};
std::map<String, S_WiFi> mWiFi;
std::map<int, String> encryption = {{2,"TKIP-WPA"},{3,"CCMP-WPA(2)"},{5,"WEP"},{4,"CCMP-WPA"},{7,"NONE"},{8,"AUTO"}};



void setup() {

  Serial.begin(9600); 
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  while(WiFi.status() != WL_DISCONNECTED){};

  //Serial.print(WiFi.status());


}


void loop() {
  int n = WiFi.scanNetworks();

  for (int i = 0; i < n; ++i) {


      /*
      if (mWiFi.find(WiFi.SSID(i)) == mWiFi.end()){
        Serial.print(WiFi.SSID(i));
        Serial.print(" || ");
        int enc_type = WiFi.encryptionType(i);
        if (encryption.find(enc_type) == encryption.end()){
          Serial.print(enc_type);
        }else{
          Serial.print(encryption[enc_type]);
        }
        
        Serial.print(" || ");
        Serial.println(WiFi.RSSI(i));
        mWiFi[WiFi.SSID(i)] = {WiFi.SSID(i), WiFi.RSSI(i), WiFi.encryptionType(i) == WIFI_AUTH_OPEN};
      }
      */
     String returnStr = "<" + (String)WiFi.SSID(i) + ">" + (String)WiFi.RSSI(i);
     Serial.println(returnStr);

    }
  
}

