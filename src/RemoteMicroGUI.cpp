//
//   Extension of MicroGUI embedded library to enable remote monitoring and
//   control of an embedded display running MicroGUI
//
//   Utilized libraries: ESPAsyncWebServer
// 
//   written by Linus Johansson, 2022 @ Plejd
//

#include <Arduino.h>

#include "MicroGUI.h"
#include "RemoteMicroGUI.h"

#include <WiFi.h>
#include <ESPAsyncWebServer.h>

bool remoteInit = false;

bool getRemoteInit() {
    return remoteInit;
}

char event[100];
char parent[100];


/* REMOTE MICROGUI */

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void handleWebSocketMessage(AsyncWebSocketClient * client, void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;

    String message = (char*)data;

    /* If document is requested, update the document and send it in chunks */
    if (strcmp((char*)data, "documentRequest") == 0) {
      Serial.print(F("[MicroGUI Remote]: Document requested by client "));
      Serial.println(client->id());
      // Fetch all the latest values/states
      mgui_update_doc();

      // Send the document to the client that requested it
      uint16_t chunk_size = 2000;
      char temp[chunk_size + 1];
      for(int i = 0; i < strlen(document); i += chunk_size) {
        strncpy(temp, document + i, chunk_size);
        temp[chunk_size] = '\0';
        ws.text(client->id(), temp);
        delay(50);
      }
      ws.text(client->id(), "DOCUMENT SENT");

      Serial.println("[MicroGUI Remote]: Document sent!");
    }

    else {
      DynamicJsonDocument doc(200);    // Length of JSON plus some slack

      DeserializationError error = deserializeJson(doc, message);
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
      }

      JsonObject root = doc.as<JsonObject>();

      mgui_set_value((const char*)root["Parent"], (int)root["Value"], true);

      memcpy(event, (const char*)root["Event"], strlen((const char*)root["Event"]) + 1);
      memcpy(parent, (const char*)root["Parent"], strlen((const char*)root["Parent"]) + 1);

      delete latest;
      latest = new MGUI_event(event, parent, (int)root["Value"]);

      newEvent = true;

      doc.clear();
    }
  }
}

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len)
{  
  if(type == WS_EVT_CONNECT)
  {  
    Serial.println("[MicroGUI Remote]: WebSocket client connection received");
  } 
  else if (type == WS_EVT_DATA) 
  {
    handleWebSocketMessage(client, arg, data, len);
  } 
  else if(type == WS_EVT_DISCONNECT)
  {
    Serial.println("[MicroGUI Remote]: Client disconnected");
  }
}

/* Initialize remote MicroGUI */
void mgui_remote_init(const char * ssid, const char * password) {
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  ws.onEvent(onWsEvent);
  server.addHandler(&ws);
  	
  server.begin();
  
  Serial.print(F("[MicroGUI Remote]: Connected to WiFi! The IP of this display is "));
  Serial.println(WiFi.localIP());
  remoteInit = true;
}

/* Initialize remote MicroGUI and set any textfield to display the IP address of the screen */
void mgui_remote_init(const char * ssid, const char * password, const char * textfield) {
  mgui_remote_init(ssid, password);
  mgui_set_text(textfield, WiFi.localIP().toString().c_str());
}

/* Broadcast a WebSocket message */
void mgui_send(const char * msg) {
  ws.textAll(msg);
}