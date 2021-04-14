


/*******************************************************************
    A sketch for controlling a Small Blimp with using a web page
    hosted on a ESP12
    Code by:
    /* Eduardo Chamorro Martin - eduardochamorromartin@gmail.com - http://eduardochamorro.github.io/beansreels/index.html
    Based on the code developped by Brian Lough

 *******************************************************************/

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ssl_client.h>
#include <WebServer.h>
#include <ESPmDNS.h>


// These are the pins used to control the motor shield

#define MOTOR_DIRECTION_LEFT_DIR 14 // using X axis
#define MOTOR_DIRECTION_LEFT_STEP 12 //

#define MOTOR_DIRECTION_RIGHT_DIR 26 // using Y axis
#define MOTOR_DIRECTION_RIGHT_STEP 27 // 

#define MOTOR_TOOL_DIR 32 // using Z axis
#define MOTOR_TOOL_STEP 33 // 

#define MOTOR_ENABLE 25

// Pins for Sensor
#define SENSOR_BUTTON_ALIM 17 //X-Limit
#define SENSOR_BUTTON 16 //Y-LImit
//4 = Zlimit +
//13 = Zlimit -

//PWM management
#define PWM_ENA_LED 22
#define PWM_SIGNAL_LED 2

int speed_val = 2;
String action;
float currenttime = 0;
float currenttime_blink = 0;
int boolKill = 0;
// drivePower sets how fast the car goes
// Can be set between 0 and 1023 (although car problaly wont move if values are too low)
//int LiftPower = 1023;

// steeringPower sets how fast the car turns
// Can be set between 0 and 1023 (again, car probably won't steer if the value is too low)
//int TurningPower = 1023;


// ----------------
// Set your WiFi SSID and Password here
// ----------------
const char* ssid = "Iaac-Wifi";
const char* password = "enteriaac2013";

WebServer server(80); //Replaces ESP8266WebServer server(80);

const char *webpage =
#include "index.h"
  ;

void handleRoot() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(200, "text/html", webpage);
}



void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {

  pinMode(MOTOR_DIRECTION_LEFT_DIR,OUTPUT);
  pinMode(MOTOR_DIRECTION_LEFT_STEP,OUTPUT);
  pinMode(MOTOR_DIRECTION_RIGHT_DIR,OUTPUT);
  pinMode(MOTOR_DIRECTION_RIGHT_STEP,OUTPUT);
  pinMode(MOTOR_TOOL_DIR,OUTPUT);
  pinMode(MOTOR_TOOL_STEP,OUTPUT);
  pinMode(MOTOR_ENABLE,OUTPUT);
  action = "STOP";

//  pinMode(SENSOR_LED,OUTPUT);
  pinMode(SENSOR_BUTTON,INPUT);
  pinMode(SENSOR_BUTTON_ALIM,OUTPUT);
  pinMode(PWM_ENA_LED, OUTPUT);
  pinMode(PWM_SIGNAL_LED,OUTPUT);
  ledcSetup(0,5000,8);
  ledcAttachPin(PWM_SIGNAL_LED,0);

  digitalWrite(MOTOR_ENABLE, LOW); //Allows motors to move
  //digitalWrite(SENSOR_LED,HIGH);
  digitalWrite(SENSOR_BUTTON_ALIM,HIGH);
  digitalWrite(PWM_ENA_LED,HIGH);
  ledcWrite(0,254);
//  boolKill = 0;

  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (MDNS.begin("WifiCar")) {
    Serial.println("MDNS Responder Started");
  }

  server.on("/", handleRoot);
  server.begin();


  Serial.println("HTTP server started");
  
  digitalWrite(MOTOR_ENABLE, LOW); //Allows motors to move
  //digitalWrite(SENSOR_LED,HIGH);
  digitalWrite(SENSOR_BUTTON_ALIM,HIGH);
  digitalWrite(PWM_ENA_LED,HIGH);
  ledcWrite(0,254);
  boolKill = 0;
  
// == MOVING CALLS
  server.on("/front", []() {
    Serial.println("front");
    action = "front";
    server.send(200, "text/plain", "front");
  });

  server.on("/back", []() {
    Serial.println("back");
    action = "back";
    server.send(200, "text/plain", "back");
  });

  server.on("/left", []() {
    Serial.println("left");
    action = "left";
    server.send(200, "text/plain", "left");
  });

  server.on("/right", []() {
    Serial.println("right");
    action = "right";
    server.send(200, "text/plain", "right");
  });

 server.on("/pivotleft", []() {
    Serial.println("pivotleft");
    action = "pivot_left";
    server.send(200, "text/plain", "pivotleft");
  });
 server.on("/pivotright", []() {
    Serial.println("pivotright");
  action = "pivot_right";
    server.send(200, "text/plain", "pivotright");
  });

 server.on("/action", []() {
    Serial.println("action");
    server.send(200, "text/plain", "action");
  });
  
// == STOPPING CALLS
 server.on("/actionStop", []() {
    Serial.println("actionStop");
    action = "STOP";
    server.send(200, "text/plain", "actionStop");
  });
 server.on("/steerStop", []() {
    Serial.println("steerStop");
    action = "STOP";
    server.send(200, "text/plain", "steerStop");
  });
 server.on("/driveStop", []() {
    Serial.println("driveStop");
    action = "STOP";
    server.send(200, "text/plain", "driveStop");
  });


  server.onNotFound(handleNotFound);
  server.begin();
  
  Serial.println("HTTP Server Started");
}

void loop(void) {    
  server.handleClient();
  
// ==SENSOR
  if((digitalRead(SENSOR_BUTTON) == HIGH) && (boolKill == 0)){
    boolKill = 1;
    currenttime = millis();
    while(millis()-currenttime < 10000){ 
      ledcWrite(0,0);
      currenttime_blink = millis();
      while(millis()-currenttime_blink < 500){    
      }
     ledcWrite(0,254);
      currenttime_blink = millis();
      while(millis()-currenttime_blink < 500){    
      }

    }
    boolKill =0;
  }

// == FRONT
    if(action == "front"){   
      Serial.println("front_while");
      digitalWrite(MOTOR_DIRECTION_RIGHT_DIR, LOW);
      digitalWrite(MOTOR_DIRECTION_LEFT_DIR, HIGH);
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, HIGH);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, HIGH);
      currenttime = millis();
      while(millis()-currenttime < 0.1){
        
      }
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, LOW);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, LOW);
      currenttime = millis();
      while(millis()-currenttime < 0.1){
        
      }
    }
 // == BACK 
    if(action == "back"){   
      Serial.println("back_while");
      digitalWrite(MOTOR_DIRECTION_RIGHT_DIR, HIGH);
      digitalWrite(MOTOR_DIRECTION_LEFT_DIR, LOW);
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, HIGH);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, HIGH);
      currenttime = millis();
      while(millis()-currenttime < 0.1){
        
      }
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, LOW);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, LOW);
      currenttime = millis();
      while(millis()-currenttime < 0.1){
        
      }
    }
 // == LEFT 
    if(action == "left"){ 
      digitalWrite(MOTOR_DIRECTION_RIGHT_DIR, LOW);
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, HIGH);
      currenttime = millis();
      while(millis()-currenttime < 0.1){
        
      }
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, LOW);
      currenttime = millis();
      while(millis()-currenttime < 0.1){
        
      }
    }
 // == RIGHT 
    if(action == "right"){ 
      digitalWrite(MOTOR_DIRECTION_LEFT_DIR, HIGH);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, HIGH);
      currenttime = millis();
      while(millis()-currenttime < 0.1){
        
      }
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, LOW);
      currenttime = millis();
      while(millis()-currenttime < 0.1){
        
      }
    }
// == PIVOT_LEFT
    if(action == "pivot_left"){ 
      digitalWrite(MOTOR_DIRECTION_RIGHT_DIR, HIGH);
      digitalWrite(MOTOR_DIRECTION_LEFT_DIR, HIGH);
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, HIGH);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, HIGH);
      while(millis()-currenttime < 0.1){
        
      }
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, LOW);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, LOW);
      while(millis()-currenttime < 0.1){
        
      }
    }
 // == PIVOT_RIGHT
    if(action == "pivot_right"){ 
      digitalWrite(MOTOR_DIRECTION_RIGHT_DIR, LOW);
      digitalWrite(MOTOR_DIRECTION_LEFT_DIR, LOW);
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, HIGH);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, HIGH);
      while(millis()-currenttime < 0.1){
        
      }
      digitalWrite(MOTOR_DIRECTION_RIGHT_STEP, LOW);
      digitalWrite(MOTOR_DIRECTION_LEFT_STEP, LOW);
      while(millis()-currenttime < 0.1){
        
      }
    }
}
