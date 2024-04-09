/*
 * bleApp.cpp
 * These procedures handle bluetooth low energy app
 * 
 * Created on: 07/04/2024 by Tunahan Arslan
 * Updated on: 07/04/2024 by Tunahan Arslan
*/

/*- Includes ------------------------------------------*/
#include <time.h>
#include "timer.h"

/*- Implamentations -----------------------------------*/
void startTimer(Timer_t* timer, uint16_t time, TimerType_t type){
    timer->time = time;
    timer->counter = clock();
    timer->type = type;
}

void restartTimer(Timer_t* timer){
    timer->time = clock();
}

bool checkTimer(Timer_t* timer){
    if(clock() - timer->counter > timer->time){
        if(timer->type == INTERVAL){
            restartTimer(timer);
        }
        return true;
    } else {
        return false;
    }
}