/*
 * accelerometerHal.cpp
 * These procedures handle accelerometer hal
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

/*- Includes ------------------------------------------*/
#include "accelerometerHal.h"
#include "mma845x_driver.h"

/*- Implamentations -----------------------------------*/
void accelerometerInitHal(void){
    mma845xInitDriver();
}

void getRotationHal(AxisType_t type, int16_t *rotation){
    getRotationDriver(type, rotation);
}

void getAccelerationHal(AxisType_t type, float *acceleration){
    getAccelerationDriver(type, acceleration);
}