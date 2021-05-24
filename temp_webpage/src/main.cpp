#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>   // Include the WebServer library

ESP8266WebServer server(80);

const char* ssid="Racko_Pelao";
const char* password="ChochoMoreno.89";

void handleRoot();
void handleNotFound();
char* temppage();

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  server.on("/showtemp", HTTP_GET, handleRoot);

    // Start the server
  server.begin();
  Serial.println("Server started");

}

void loop() {
  yield();
  server.handleClient();
}

void handleRoot(){
  server.send(200, "text/html", temppage());   // Send HTTP status 200 (Ok) and send some text to the browser/client
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

char* temppage() {
  return "<h1>T1</h1>";
}