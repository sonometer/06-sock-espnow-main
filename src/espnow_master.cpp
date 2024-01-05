/*
 *  espnow_master.cpp
 */

#include <Arduino.h>
#include <esp_now.h>
#include <cutils.h>

#include "espnow_master.h"
#include "mac_data.h"
#include "data.h"

static const unsigned char *address;

// Create a struct_message called myData
static msg_t myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
static void
OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
    if( status != ESP_NOW_SEND_SUCCESS )
        Serial.println("Delivery Fail");
}

void
espnow_master_init(void)
{
    address = get_address(SLAVE_ESPNOW);

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        forever
        ;
    }

    esp_now_register_send_cb(OnDataSent);

    // Register peer
    memcpy(peerInfo.peer_addr, address, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    // Add peer
    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        Serial.println("Failed to add peer");
        forever
        ;
    }
}


int
espnow_master_send(int bright)
{
    Serial.println(myData.bright = bright);
    esp_err_t result = esp_now_send(address, (uint8_t *)&myData, sizeof(myData));   // Send message via ESP-NOW
    if( result != ESP_OK )
    {
        Serial.println("Error sending data");
        return 0;
    }
    return 1;
}


