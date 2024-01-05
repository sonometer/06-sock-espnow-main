/*
 *  led.cpp
 */

#include <Arduino.h>

#include "led.h"

typedef struct
{
    int num_blink;
    unsigned long blink_time;
} blnk_t;

static blnk_t btypes[NUM_BLINK] =
{
    { 2, 500 },     //  N0
    { 3, 250 },     //  E1
    { 4, 100 },     //  E2
    { 5, 50  }      //  E3
};


void
led_init(void)
{
    pinMode(LED,OUTPUT);
}

void
led_blink(int which)
{
    int i;
    blnk_t *p;

    Serial.printf("which = %d, num_blink = %d, blink_time = %ld\n", which, btypes[which].num_blink, btypes[which].blink_time);
    if( which < 0 || which >= NUM_BLINK )
        return;

    for( p = btypes + which, i = 0; i < 2 * p->num_blink; ++i )
    {
        led_toggle();
        delay(p->blink_time);
    }
}

void
led_toggle( void )
{
    digitalWrite( LED, !digitalRead(LED) );
}




