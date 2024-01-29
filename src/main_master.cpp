/*
 *  project 06-sock-espnow
 *      src/main_master.cpp
 */

#include <Arduino.h>
#include <cutils.h>
#include <ESPmDNS.h>


#include "led.h"
#include "wifi_ruts.h"
#include "websock.h"
#include "espnow_master.h"
#include "target.h"

#include <WiFi.h>

void
dns_init(const char *local_name)
{
    if(!MDNS.begin(local_name))
        Serial.println("Error starting mDNS");
}

void
setup( void )
{
    Serial.begin(BAUD_RATE);
    led_init();
    wifi_connect(WIFI_MODE);
    dns_init(LOCAL);
    target_init();
    websock_init();
    espnow_master_init();
}

void
loop(void)
{
    int bright;

    if( ( bright = websock_test() ) > 0 && espnow_master_send(bright) )
        led_toggle();
    target_process();
    delay(5);
}
