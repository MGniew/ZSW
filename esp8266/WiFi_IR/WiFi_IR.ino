#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Mateg";  // type your ssid
const char* password = "hesianr1";    // type your password
WiFiClient client;

int IRledPin = 4;                     // Dioda IR nadawcz
int TSOPPin = 5;                      // Dioda TSOP odbiorcza
boolean CurrentStatus = false;        // Curren box status 0-empty 1-no empty

void setup() {
  pinMode(TSOPPin, INPUT);
  pinMode(IRledPin, OUTPUT);
  digitalWrite(IRledPin, LOW);
  Serial.begin(115200);
  while (!Serial);
  WiFiConnect();
}

void loop() {
  Serial.println("Awaken");
  measurement();
  Serial.println("Going to sleep");
  ESP.deepSleep(30e6);
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
  Serial.println(resault);
  digitalWrite(IRledPin, LOW);
  reaction(resault);
}

// Reaction if something in box
void reaction(int resault){
  if(resault == 0){
    SendGET("1");
    Serial.println("No empty BOX");
  }
  else{
    SendGET("0");
    Serial.println("Empty BOX");
  }
}

////////
//WiFi//
////////

// Connect to WiFi network
void WiFiConnect() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

// Send GET to URL
void SendGET(String Data)
{
 if(WiFi.status()== WL_CONNECTED){
  String URL = "http://192.168.1.3:5000/state/"+Data;
  Serial.println(URL);
  HTTPClient http;

  http.begin(URL);  //Specify request destination
  http.addHeader("Content-Type", "text/plain");  //Specify content-type header
  int httpCode = http.POST(Data);       //Send the request (returning code
//  int httpCode = http.GET();
  String payload = http.getString();                  //Get the response payload 
   Serial.print("HTTP code ");    //Print HTTP return code
   Serial.println(httpCode);   //Print HTTP return code
   Serial.print("HTTP response ");   //Print request response payload
   Serial.println(payload);    //Print request response payload
  http.end();
  
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
}

