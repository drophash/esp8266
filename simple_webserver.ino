#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server;

/*
	Base Station + Access Point Setup (Mesh Network or WISP), For more Info.
	Contact me on Facebook: https://www.facebook.com/100011369547476
	Contact me via Mobile: 09225205353 (Sun Cellular)
*/

uint8_t pin_led = 16;
char* ssid = "Xnow's Access Point"
char* pass = "$1$8t2aFHA/$DRuYhor4Vivci3TiO.5y1/"

void setup(){
	pinMode(pin_led,OUTPUT);
	WiFi.begin(ssid,pass);
	Serial.begin(115200);
	while(WiFi.status()!=WL_CONNECTED){
		Serial.print(".");
		delay(500);
	}
	Serial.println("");
	Serial.print("IP Address: ");
	Serial.print(WiFi.localIP());
	
	server.on("/",[](){server.send(200,"text/plain","Hello World");});
	server.on("/toggle",toggleLED);
	server.begin();
}

void loop(){
	server.handleClient();
}

void toggleLED(){
	digitalWrite(pin_led,digitalRead(pin_led));
	server.send(204,"");
}
