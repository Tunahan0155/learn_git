/*
 * accelerometerApp.cpp
 * These procedures handle accelerometer app
 * 
 * Created on: 07/04/2024 by Tunahan Arslan
 * Updated on: 07/04/2024 by Tunahan Arslan
*/

/*- Includes ------------------------------------------*/
#include "accelerometerApi.h"
#include "registerControl.h"

/*- Implamentations -----------------------------------*/
void accelerometerInitApp(void){
    accelerometerInitApi();
}

void accelerometerApp(void){
    writeRegister(REG_ROTATION_X, getXrotationApi());
    writeRegister(REG_ROTATION_Y, getYrotationApi());
    writeRegister(REG_ROTATION_Z, getZrotationApi());
    writeRegister(REG_ACCELEROMETER_X, getXaccelerationApi());
    writeRegister(REG_ACCELEROMETER_Y, getYaccelerationApi());
    writeRegister(REG_ACCELEROMETER_Z, getZaccelerationApi());
}