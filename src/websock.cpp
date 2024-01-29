/*
 *  websock.cpp
 */

#include <Arduino.h>

#include <WebServer.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

#include "websock.h"

#include "webpage.h"

//  Object creation

WebServer server;
WebSocketsServer webSocket = WebSocketsServer(81);

//  Private variables

static unsigned short brightness;
static int volatile news;

//  Private functions

/*
 *  webSocketEvent:
 *      Events Callback
 */

static void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
    Serial.printf("WebSocket event. Type: %d\n", type);
    Serial.printf("El Payload es: %s\n", payload ? (const char *)payload : "NULL");

    if (type == WStype_TEXT)
    {
        Serial.printf("Entro al primer if\n"); // Asegúrate de añadir las llaves aquí

        String message = String((char *)&payload[0]);
        Serial.printf("Received message: %s\n", message.c_str());
        if (message == "ping")
        {
            Serial.println("Received ping");
            webSocket.sendTXT(num, "pong");
            Serial.println("Sent pong");
        }
        else if (payload[0] == '#')
        {
            brightness = (uint16_t)strtol((const char *)&payload[1], NULL, 10);
            news = 1;
        }
        else
        {
            DynamicJsonDocument doc(1024);
            deserializeJson(doc, (char *)payload);
            JsonObject obj = doc.as<JsonObject>();

            JsonObject position = obj["position"];
            int x = position["x"];
            int y = position["y"];
            int radius = obj["radius"];
            int angle = obj["angle"];

            // Imprime los valores en la consola
            Serial.printf("x: %d\n", x);
            Serial.printf("y: %d\n", y);
            Serial.printf("radius: %d\n", radius);
            Serial.printf("angle: %d\n", angle);
        }
    }
    else if (type == WStype_DISCONNECTED)
    {
        Serial.printf("Client #%u disconnected\n", num);
        // Agrega lógica de manejo de desconexión si es necesario
        webSocket.sendTXT(num, "DISCONNECTED");
    }
}

//  Public functions

void websock_init(void)
{
    server.on("/", []()
              { server.send_P(200, "text/html", webpage); });
    server.begin();
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
}

void
send_websock(const char *p)
{
    Serial.printf("%s: \"%s\"\n", __FUNCTION__, p);
}

int websock_test(void)
{
    webSocket.loop();
    server.handleClient();
    if (news != 0)
    {
        news = 0;
        return brightness;
    }
    return -1;
}
