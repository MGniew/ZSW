#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "***";  // type your ssid
const char* password = "***";    // type your password
WiFiClient client;

int IRledPin = 4;                     // Dioda IR nadawcz
int TSOPPin = 5;                      // Dioda TSOP odbiorcza
boolean CurrentStatus = false;        // Curren box status 0-empty 1-no empty

void setup() {
  pinMode(TSOPPin, INPUT);
  pinMode(IRledPin, OUTPUT);
  digitalWrite(IRledPin, LOW);
  WiFiConnect();
}

void loop() {
  measurement();
  ESP.deepSleep(10e6);
}

//////
//IR//
//////

// Measurement IR
void measurement()
{
  digitalWrite(IRledPin, HIGH);
  delay(100);
  //int resault = remote();
  int resault = pulseIn(TSOPPin,LOW,10000000);  //waiting 10 seconds for IR signal
  digitalWrite(IRledPin, LOW);
  reaction(resault);
}

// Reaction if something in box
void reaction(int resault){
  if(resault == 0){
    SendGET("1");
  }
  else{
    SendGET("0");
  }
}

////////
//WiFi//
////////

// Connect to WiFi network
void WiFiConnect() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

// Send GET to URL
void SendGET(String Data)
{
 if(WiFi.status()== WL_CONNECTED){
  String URL = "http://10.0.0.2:5000/state/"+Data;
  HTTPClient http;

  http.begin(URL);  //Specify request destination
  http.addHeader("Content-Type", "text/plain");  //Specify content-type header
  int httpCode = http.POST(Data);       //Send the request (returning code
//  int httpCode = http.GET();
  String payload = http.getString();                  //Get the response payload 
  http.end();
  
 }
}

