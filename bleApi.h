/*
 * bleApi.h
 * These procedures handle bluetooth low energy api
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

#ifndef BLE_API_H
#define BLE_API_H

/*- Includes ------------------------------------------*/
#include <string>

/*- Declaration ---------------------------------------*/
typedef struct {
    bool isConnected;         
} BleStatus_t;

typedef enum {
    messageIdle,
    messageReceived,
} MessageStatus_t;

typedef struct {
    MessageStatus_t status; 
    std::string message;        
} BleMessage_t;

/*- Implamentations -----------------------------------*/
void bleInitApi(std::string bleName);
void setBleConnectionApi(void);
void setBleDisconnectionApi(void);
void setBleMessageApi(std::string message);
bool isBleConnected(void);
std::string receiveBleMessageApi(void);
MessageStatus_t getBleMessageStatusApi(void);
void transmitBleMessageApi(std::string message);

#endif