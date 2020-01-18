#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "NodeMCU";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

uint8_t OpenFloor1 = 1;
uint8_t CloseFloor1 = 2;
bool FLOOR1status = LOW;

uint8_t OpenFloor2 = 3;
uint8_t CloseFloor2 = 4;
bool FLOOR2status = LOW;

uint8_t OpenDoor = 5;
uint8_t CloseDoor = 6;
bool DOORstatus = LOW;


void setup() {
  Serial.begin(9600);
  
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/OpenFloor1", handle_floor1on);
  server.on("/CloseFloor1", handle_floor1off);
  server.on("/OpenFloor2", handle_floor2on);
  server.on("/CloseFloor2", handle_floor2off);
  server.on("/OpenDoor", handle_opendoor);
  server.on("/CloseDoor", handle_closedoor);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if(FLOOR1status)
  {Serial.write(OpenFloor1);}
  else
  {Serial.write(CloseFloor1);}
  
  if(FLOOR2status)
  {Serial.write(OpenFloor2);}
  else
  {Serial.write(CloseFloor2);}
  
  if(DOORstatus)
  {Serial.write(OpenDoor);}
  else
  {Serial.write(CloseDoor);}
}

void handle_OnConnect() {
  FLOOR1status = LOW;
  FLOOR2status = LOW;
  DOORstatus = LOW;
  server.send(200, "text/html", SendHTML(FLOOR1status,FLOOR2status,DOORstatus)); 
}

void handle_floor1on() {
  FLOOR1status = HIGH;
  server.send(200, "text/html", SendHTML(true,FLOOR2status,DOORstatus)); 
}

void handle_floor1off() {
  FLOOR1status = LOW;
  server.send(200, "text/html", SendHTML(false,FLOOR2status,DOORstatus)); 
}

void handle_floor2on() {
  FLOOR2status = HIGH;
  server.send(200, "text/html", SendHTML(FLOOR1status,true,DOORstatus)); 
}

void handle_floor2off() {
  FLOOR2status = LOW;
  server.send(200, "text/html", SendHTML(FLOOR1status,false,DOORstatus)); 
}

void handle_opendoor() {
  LCDstatus = HIGH;
  server.send(200, "text/html", SendHTML(FLOOR1status,FLOOR2status,true)); 
}
void handle_closedoor() {
  LCDstatus = LOW;
  server.send(200, "text/html", SendHTML(FLOOR1status,FLOOR2status,false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t floor1stat,uint8_t floor2stat,uint8_t doorstat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP8266 Web Server</h1>\n";
  ptr +="<h3>Using Access Point(AP) Mode</h3>\n";
  
   if(floor1stat)
  {ptr +="<p>Floor1 Light System: ON</p><a class=\"button button-off\" href=\"/CloseFloor1\">OFF</a>\n";}
  else
  {ptr +="<p>Floor1 Light Status: OFF</p><a class=\"button button-on\" href=\"/OpenFloor1\">ON</a>\n";}

  if(floor2stat)
  {ptr +="<p>Floor2 Light System: ON</p><a class=\"button button-off\" href=\"/CloseFloor2\">OFF</a>\n";}
  else
  {ptr +="<p>Floor2 Light System: OFF</p><a class=\"button button-on\" href=\"/OpenFloor2\">ON</a>\n";}
  
  if(doorstat)
   {ptr +="<p>Door Status: Opened</p><a class=\"button button-off\" href=\"/CloseDoor\">OFF</a>\n";}
  else
  {ptr +="<p>Door Status: Closed</p><a class=\"button button-on\" href=\"/OpenDoor\">ON</a>\n";}

  
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
