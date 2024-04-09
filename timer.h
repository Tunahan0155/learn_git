/*
 * timer.h
 * These procedures handle timer
 * 
 * Created on: 08/04/2024 by Tunahan Arslan
 * Updated on: 08/04/2024 by Tunahan Arslan
*/

#ifndef TIMER_H
#define TIMER_H

/*- Includes ------------------------------------------*/
#include <stdint.h>
#include <stdio.h>

/*- Declaration ---------------------------------------*/
typedef enum
{
    TIMEOUT,
    INTERVAL,
} TimerType_t;

typedef struct
{
    uint16_t time;
    unsigned long counter;
    TimerType_t type; 
} Timer_t;

/*- Implamentations -----------------------------------*/
void startTimer(Timer_t* timer, uint16_t time, TimerType_t type);
void restartTimer(Timer_t* timer);
bool checkTimer(Timer_t* timer);

#endif