/*
 * bleApi.cpp
 * These procedures handle bluetooth low energy api
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

/*- Includes ------------------------------------------*/
#include "bleApi.h"
#include "bleHal.h"

/*- Definition ----------------------------------------*/
BleStatus_t bleStatus;
BleMessage_t bleMessage;

/*- Implamentations -----------------------------------*/
void bleInitApi(std::string bleName){
    setBleDisconnectionApi();
    bleInitHal(bleName);
}

void setBleConnectionApi(void){
    bleStatus.isConnected = true;
}

void setBleDisconnectionApi(void){
    bleMessage.status = messageIdle;
    bleMessage.message = "";
    bleStatus.isConnected = false;
}

void setBleMessageApi(std::string message){
    bleMessage.status = messageReceived;
    bleMessage.message = message;
}

bool isBleConnected(void){
    return bleStatus.isConnected;
}

std::string receiveBleMessageApi(void){
    bleMessage.status = messageIdle;
    return bleMessage.message;
}

MessageStatus_t getBleMessageStatusApi(void){
    return bleMessage.status;
}

void transmitBleMessageApi(std::string message){
    transmitBleMessageHal(message);
}