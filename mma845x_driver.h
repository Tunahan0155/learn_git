/*
 * accelerometerHal.h
 * These procedures handle mma845x accelerometer driver
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

#ifndef MMA845X_DRIVER_H
#define MMA845X_DRIVER_H

/*- Includes ------------------------------------------*/
#include <stdint.h>
#include "accelerometerHal.h"

/*- Implamentations -----------------------------------*/
void mma845xInitDriver(void);
void getRotationDriver(AxisType_t type, int16_t *rotation);
void getAccelerationDriver(AxisType_t type, float *acceleration);

#endif