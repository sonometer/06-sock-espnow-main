#ifndef __UTIL_MACROS_H__
#define __UTIL_MACROS_H__

/*
 *  util_macros.h
 */

#define do_time_task(start,period,task)             \
    do                                              \
    {                                               \
        unsigned long currentMillis = millis();     \
                                                    \
        if( currentMillis - start >= period )       \
        {                                           \
            (*task)();                              \
            start = currentMillis;                  \
        }                                           \
    } while(0)

#endif

