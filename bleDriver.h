/*
 * bleDriver.h
 * These procedures handle bluetooth low energy driver
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

#ifndef BLE_DRIVER_H
#define BLE_DRIVER_H
/*- Includes ------------------------------------------*/
#include <string>

/*- Declaration ---------------------------------------*/
#define SERVICE_UUID "19B10000-E8F2-537E-4F6C-D104768A1214"

#define CHARACTERISTIC_UUID_Receive "19B10000-E8F2-537E-4F6C-D104768A1214"
#define CHARACTERISTIC_UUID_Transmit "19B10001-E8F2-537E-4F6C-D104768A1214"

/*- Implamentations -----------------------------------*/
void bleInitDriver(std::string bleName);
void transmitBleMessageDriver(std::string message);

#endif