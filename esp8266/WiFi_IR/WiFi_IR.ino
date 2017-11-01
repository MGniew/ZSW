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
  //WiFiDisconnect();
}

void loop() {
  Serial.println("Awaken");
  measurement();
  Serial.println("Going to sleep");
  //delay(1000);
  ESP.deepSleep(30e6);
}

//////
//IR//
//////

// Couting of recived signals
int remote()  
{  
  int value = 0;  
  int time = pulseIn(TSOPPin,LOW);  
  //if(time>2000) // Checking if the Start Bit has been received. Start Bit Duration is 2.4ms  
  {  
   for(int counter1=0;counter1<12;counter1++) // A loop to receive the next 12 bits  
   {  
    if(pulseIn(TSOPPin,LOW)>1000) // checking the duration of each pulse, if it is a '1' then we use it in our binary to decimal conversion, '0's can be ignored.  
    {  
     value = value + (1<< counter1);// binary to decimail conversion. 1<< i is nothing but 2 raised to the power of i  
    }  
   }  
  }  
  return value;  
}

// Measurement IR
void measurement() // funkcja pomiaru
{
  digitalWrite(IRledPin, HIGH);
  int resault = remote();
  Serial.println(resault);
  if ((resault==0 && !CurrentStatus) || (resault>0 && CurrentStatus)){
    CurrentStatus = !CurrentStatus;
    reaction();
  }
  digitalWrite(IRledPin, LOW);
}

// Reaction if something in box
void reaction(){
  //WiFiConnect();
  if(CurrentStatus){
    Serial.println("No empty BOX");
  }
  else{
    Serial.println("Empty BOX");
  }
  //SendGET("0.0.0.0.500");
  //WiFiDisconnect();
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

// Disconnect to WiFi network
void WiFiDisconnect() {
  Serial.println("Disconnecting");
  WiFi.disconnect();
  Serial.println("Disconnected");
}

// Send GET to URL
void SendGET(String URL)
{
  HTTPClient http;

  http.begin(URL);  //Specify request destination
  http.GET();       //Send the request (returning code 
  http.end();
}

