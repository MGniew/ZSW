#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "TP-LINK_DAFFBA";  // type your ssid
const char* password = "67DAFFBA";    // type your password
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
void measurement() // funkcja pomiaru
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
    Serial.println("No empty BOX");
  }
  else{
    Serial.println("Empty BOX");
  }
  SendGET("0.0.0.0.500");
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
void SendGET(String URL)
{
  HTTPClient http;

  http.begin(URL);  //Specify request destination
  http.GET();       //Send the request (returning code 
  http.end();
}

