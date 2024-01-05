/*
 *  led.h
 */

enum
{
    N0, E1, E2, E3,
    NUM_BLINK
};


void led_init(void);
void led_blink(int which);
void led_toggle(void);

