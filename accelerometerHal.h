/*
 * accelerometerHal.h
 * These procedures handle accelerometer hal
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

#ifndef ACCELEROMETER_HAL_H
#define ACCELEROMETER_HAL_H

/*- Includes ------------------------------------------*/
#include <stdint.h>
#include "accelerometerApi.h"

/*- Implamentations -----------------------------------*/
void accelerometerInitHal(void);
void getRotationHal(AxisType_t type, int16_t *rotation);
void getAccelerationHal(AxisType_t type, float *acceleration);

#endif