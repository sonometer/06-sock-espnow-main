/*
 *  pwm.cpp
 */

#include <Arduino.h>

#include "pwm.h"

// constants setting PWM properties

static const int freq = 5000;
static const int ledChannel = 0;
static const int resolution = 12;

static const int bright_center = 512;

void
pwm_init(void)
{
    ledcSetup(ledChannel, freq, resolution);
    ledcAttachPin(LED, ledChannel);
    ledcWrite(ledChannel, bright_center);
}

void
pwm_write(int duty)
{
    ledcWrite(ledChannel, duty);
}


