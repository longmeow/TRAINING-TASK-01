#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

WiFiServer server(80);
WiFiClient client;
String path;

void start(String ssid, String pass) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.begin();

}

bool isReq = false;

void CheckReq(String CIP) {
  client = server.available();
  if (!client) {
    return;
  }
  Serial.println();
  Serial.print("FIND NEW REQUEST - ");
  while (client.connected() && !client.available()) {
    delay(1);
  }

  if (client.remoteIP().toString()!= CIP){
   Serial.print("Not available!");
   return;
  }
  
  String req = client.readStringUntil('r');
  int addr_start = req.indexOf(' ');
  int addr_end = req.indexOf(' ', addr_start + 1);
  if (addr_start == -1 || addr_end == -1) {
    Serial.print("Invalid request: ");
    Serial.println(req);
    return;
  }
  req = req.substring(addr_start + 1, addr_end);
  Serial.print("Requested Path: ");
  Serial.println(req);

  path = req;
  isReq = true;
  client.flush();
}

void waitNewReq (String CIP) {
  do {
    CheckReq(CIP);
  }
  while (!isReq);
  isReq = false;
}

void returnStr(String data1, String data2) {
  String s1;
  s1 = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  s1 += data1;
  s1 += " ";
  s1 += data2;
  client.print(s1);
}

void returnData(float data1, int data2) {
  returnStr(String(data1), String(data2));
}

String getPath() {
  return path;
}
