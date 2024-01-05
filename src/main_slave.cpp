/*
 *  Project 06-sock-espnow
 *      src/main_slave.cpp
 */

#include <Arduino.h>
#include <cutils.h>

#include <WiFi.h>
#include <esp_now.h>

#include "data.h"
#include "pwm.h"

static int bright;

// Create a struct_message called myData
static msg_t myData;
static int volatile data_available;


// callback function that will be executed when data is received

static void
OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
    memcpy(&myData, incomingData, sizeof(myData));
    bright = myData.bright;
    data_available = 1;
}

void
setup(void)
{
    Serial.begin(BAUD_RATE);

    pwm_init();

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        forever
        ;
    }

    esp_now_register_recv_cb(OnDataRecv);
}

void
loop(void)
{
    if( data_available )
    {
        data_available = 0;
        pwm_write(myData.bright);
    }
}


