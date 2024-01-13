#include <Arduino.h>

#include <WiFi.h>
#include <WebServer.h>
#include "motores.h"
#include "ultrassonico.h"
#include "mpu.h"
#include "VL53.h"
//#include "upload.h"
#include "led.h"
#include "encoder.h"
#include "SPIFFS.h"


VL53_sensors sensores;


char XML [2048]; //Arquivo XML para passagem de informações para o site
char buf[32]; //buffer de armazenamento

//Define se a conexão será via intranet ou não?? -> TODO comentar melhor essa parte
#define USE_INTRANET

//Conexão no Wifi (Caso USE_INTRANET não esteja comentado)
#define LOCAL_SSID "Oi_A822"
#define LOCAL_PASS "MchCM3TM"

//Definicão do IP (Caso USE_INTRANET esteja comentado) ?? -> ou é a definição geral do IP??
//TODO entender melhor o que isso faz
IPAddress Actual_IP;
// definitions of your desired intranet created by the ESP32
IPAddress PageIP(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress ip;


WebServer server(80);

//Protótipo FUNÇÕES
void SendXML();
void SendWebsite();
void printWifiStatus();
void PROCESS_BUTTON_FRONT();
void PROCESS_BUTTON_BACK();
void PROCESS_BUTTON_STOP();
void PROCESS_BUTTON_LEFT();
void PROCESS_BUTTON_RIGHT();


String SITE = "";

void setup() {
  leds("fade", 50);
  Serial.begin(115200);

  //Inicia SPIFFS e lê o HTML pra enviar o server
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  
  File file = SPIFFS.open("/index.html");
  if(!file){
    Serial.println("Failed to open file for reading");
    return;
  }
  SITE = file.readString();



  _imu_connect = imu_setup(); //Init MPU

  //Definitions Motors Pins
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(2, OUTPUT);
  

  sensores.sensorsInit(); //Init VL's

  pixels.begin(); //Init LEDs
  
  //Definitions Encoders A and B
  pinMode(PinDT_A, INPUT);
  pinMode(PinCLK_A, INPUT);
  PreviousCLK_A=digitalRead(PinCLK_A);
  PreviousDATA_A=digitalRead(PinDT_A);

  pinMode(PinDT_B, INPUT);
  pinMode(PinCLK_B, INPUT);
  PreviousCLK_B=digitalRead(PinCLK_B);
  PreviousDATA_B=digitalRead(PinDT_B);

  //Desativa o watch dog do ESP para prevenir ele de reiniciar
  disableCore0WDT();

    // if you have this #define USE_INTRANET,  you will connect to your home intranet, again makes debugging easier
  #ifdef USE_INTRANET
    WiFi.begin(LOCAL_SSID, LOCAL_PASS);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.print("IP address: "); Serial.println(WiFi.localIP());
    Actual_IP = WiFi.localIP();
  #endif

    // if you don't have #define USE_INTRANET, here's where you will creat and access point
    // an intranet with no internet connection. But Clients can connect to your intranet and see
    // the web page you are about to serve up
  #ifndef USE_INTRANET
    WiFi.softAP(AP_SSID, AP_PASS);
    delay(100);
    WiFi.softAPConfig(PageIP, gateway, subnet);
    delay(100);
    Actual_IP = WiFi.softAPIP();
    Serial.print("IP address: "); Serial.println(Actual_IP);
  #endif

  printWifiStatus();
  // these calls will handle data coming back from your web page
  // this one is a page request, upon ESP getting / string the web page will be sent
  server.on("/", SendWebsite);

  // upon esp getting /XML string, ESP will build and send the XML, this is how we refresh
  // just parts of the web page
  server.on("/xml", SendXML);

  //Funções para os botões de frente, trás, stop, esquerda e direita
  server.on("/BUTTON_FRONT", PROCESS_BUTTON_FRONT);
  server.on("/BUTTON_BACK", PROCESS_BUTTON_BACK);
  server.on("/BUTTON_STOP", PROCESS_BUTTON_STOP);
  server.on("/BUTTON_LEFT", PROCESS_BUTTON_LEFT);
  server.on("/BUTTON_RIGHT", PROCESS_BUTTON_RIGHT);

  /*TODO -> primeira etapa: também criar funções para:
  -mandar dados VL0, VL1 e VL2
  -mandar dados MPU (se possível com visualização)
  -Controlar LEDs
  -Mandar distancias encoder

  */
 server.begin();

}

void loop() {
  /*Serial.print("U" + String(getValueUltrassonic(0)) + " ");

  Serial.print("M" + String(getMPUAngle()) + " ");

  Serial.print("EA" + String(encoderA()) + " ");

  Serial.print("EB" + String(encoderB()) + " ");
  Serial.println();
*/
  //frente(50);
  //stop();
   
  /*
  sensores.distanceRead();
  Serial.print(sensores.dist[0]);
  Serial.print(" ");
  Serial.print(sensores.dist[1]);
  Serial.print(" ");
  Serial.print(sensores.dist[2]);
  Serial.println(" ");
  */ 

  

  

  leds("static", 50);


  //ENCODER COM ULT + MPU + MOTOR OK, SEM DELAY, MAS JUNTO COM OS VL's NÃO FUNCIONA DIREITO
  //Parece que os VLs atrasam a leitura dos outros sensores e o encoder não consegue atualizar


  server.handleClient();


}



void PROCESS_BUTTON_STOP(){
  digitalWrite(2, 0);
  //Serial.println("STOP");
  server.send(200, "text/plain", "");
  stop();
}

void PROCESS_BUTTON_BACK(){
  digitalWrite(2, 1);
  //Serial.println("BACK");
  server.send(200, "text/plain", "");
  tras(50);
}

void PROCESS_BUTTON_FRONT(){
  digitalWrite(2, 1);
  //Serial.println("FRONT");
  server.send(200, "text/plain", "");
  frente(50);

}

void PROCESS_BUTTON_RIGHT(){
  digitalWrite(2, 1);
  //Serial.println("RIGHT");
  server.send(200, "text/plain", "");
  direita(50);

}

void PROCESS_BUTTON_LEFT(){
  digitalWrite(2, 1);
  //Serial.println("LEFT");
  server.send(200, "text/plain", "");
  esquerda(50);

}


void SendWebsite() {
  // you may have to play with this value, big pages need more porcessing time, and hence
  // a longer timeout that 200 ms
  server.send(200, "text/html", SITE);
}

// code to send the main web page
// I avoid string data types at all cost hence all the char mainipulation code
void SendXML() {
   strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");
  // show led0 status
  if (digitalRead(2)) {
    strcat(XML, "<LED>1</LED>\n");
  }
  else {
    strcat(XML, "<LED>0</LED>\n");
  }
  sprintf(buf, "<U>%d</U>\n", getValueUltrassonic(0));
  strcat(XML, buf);
  strcat(XML, "</Data>\n");
  Serial.println(XML);

  server.send(200, "text/xml", XML);

}

// I think I got this code from the wifi example
void printWifiStatus() {

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("Open http://");
  Serial.println(ip);
}
