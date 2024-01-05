/*
 *  wifi_ruts.cpp
 *      Routines for WiFi management
 */

#include <Arduino.h>

#include <WiFi.h>

#include "wifi_ruts.h"
#include "wifi_data.h"

//  Private functions

static void
wifi_connect_sta(void)
{
    WiFi.begin(STA_SSID, STA_PASS);

    while( WiFi.status() != WL_CONNECTED )
    {
        Serial.print(".");
        delay(500);
    }

    Serial.println();
    Serial.println("______________");
    Serial.print( "Conectado a ");
    Serial.println( STA_SSID );
    Serial.print( "MAC = ");
    Serial.println( WiFi.macAddress() );
    Serial.print( "local IP = " );
    Serial.println( WiFi.localIP() );
    Serial.println("______________");
}

static void 
wifi_connect_ap(void)
{
    WiFi.softAP(AP_SSID, AP_PASS);
    IPAddress IP = IPAddress(10, 10, 10, 1);
    IPAddress NMask = IPAddress(255, 255, 255, 0);
    WiFi.softAPConfig(IP, IP, NMask);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

}

//  Public functions

void
wifi_connect(int mode)
{
    WiFi.mode(WIFI_AP_STA);
    if(mode == 0)
        wifi_connect_sta();
    else
        wifi_connect_ap();
}

