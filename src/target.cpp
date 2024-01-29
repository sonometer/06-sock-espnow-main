/*
 *  target.cpp
 *      Simulate target hit
 */

#include <Arduino.h>

#include "util_macros.h"
#include "target.h" 
#include "websock.h"

static unsigned long start_target;
static const unsigned long period_target = 1000;
static int hit;
static int counter;


static void
task_target(void)
{
    static char buffer[10];

    if( --counter == 0 )
    {
        counter = 10;
        hit = !hit;
    }
    sprintf(buffer,"tgt,%d",hit);
    send_websock(buffer);
//    Serial.printf("%s: %s\n",__FUNCTION__,buffer);
}

void
target_init(void)
{
    counter = 10;
    hit = 0;
}

void
target_process(void)
{
    do_time_task(start_target,period_target,task_target);    
}


