/*
 * bleHal.h
 * These procedures handle bluetooth low energy hal
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

#ifndef BLE_HAL_H
#define BLE_HAL_H

/*- Includes ------------------------------------------*/
#include <string>

/*- Implamentations -----------------------------------*/
void bleInitHal(std::string bleName);
void setBleConnectionHal(void);
void setBleDisconnectionHal(void);
void receiveBleMessageHal(std::string message);
void transmitBleMessageHal(std::string message);

#endif