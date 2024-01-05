/*
 *  mac_data.cpp
 */
#include <Arduino.h>

#include <cutils.h>
#include "mac_data.h"

static const unsigned char macs[][6] =
{
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },    // order 0 == broadcast
    {0x0C, 0xB8, 0x15, 0xC5, 0x0B, 0x20 },    // order 1
    {0xA4, 0xCF, 0x12, 0x45, 0xD2, 0x34 },    // order 2
    {0x0C, 0xB8, 0x15, 0xC3, 0xC7, 0xA8 },    // order 3
    {0x30, 0xAE, 0xA4, 0x05, 0x49, 0x18 },    // order 4
    {0x30, 0xAE, 0xA4, 0xFE, 0xF2, 0x70 },    // order 5
    {0x30, 0xAE, 0xA4, 0x05, 0x49, 0x18 }     // order 6
};

static const char * const mac_addresses[] =
{
    "FF:FF:FF:FF:FF:FF",    // order 0 == broadcast
    "0C:B8:15:C5:0B:20",    // order 1
    "A4:CF:12:45:D2:34",    // order 2
    "0C:B8:15:C3:C7:A8",    // order 3
    "30:AE:A4:05:49:18",    // order 4
    "30:AE:A4:FE:F2:70",    // order 5
    "30:AE:A4:05:49:18"     // order 6      
};

#define NUM_ESPNOW  SizeOf(macs)

void
mac_init(void)
{
}

unsigned const char *
get_address(int order)
{
    if( order < 0 || order > NUM_ESPNOW )
        return NULL;
    else
        return macs[order];
}

