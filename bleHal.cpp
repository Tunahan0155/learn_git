/*
 * bleHal.cpp
 * These procedures handle bluetooth low energy hal
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

/*- Includes ------------------------------------------*/
#include "bleHal.h"
#include "bleApi.h"
#include "bleDriver.h"

/*- Implamentations -----------------------------------*/
void bleInitHal(std::string bleName){
    bleInitDriver(bleName);
}

void setBleConnectionHal(void){
    setBleConnectionApi();
}

void setBleDisconnectionHal(void){
    setBleDisconnectionApi();
}

void receiveBleMessageHal(std::string message){
    setBleMessageApi(message);
}

void transmitBleMessageHal(std::string message){
    transmitBleMessageDriver(message);
}