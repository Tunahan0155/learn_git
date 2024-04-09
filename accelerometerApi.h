/*
 * accelerometerApi.h
 * These procedures handle accelerometer api
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

#ifndef ACCELEROMETER_API_H
#define ACCELEROMETER_API_H

/*- Includes ------------------------------------------*/
#include <stdint.h>

/*- Declaration ---------------------------------------*/
typedef enum {
    X,    
    Y,         
    Z,     
} AxisType_t;

typedef struct {
    int16_t X;      
    int16_t Y;         
    int16_t Z;      
} RotationValue_t;

typedef struct {
    float X;      
    float Y;         
    float Z;      
} AccelerometerValue_t;

/*- Implamentations -----------------------------------*/
void accelerometerInitApi(void);
int16_t getXrotationApi(void);
int16_t getYrotationApi(void);
int16_t getZrotationApi(void);

float getXaccelerationApi(void);
float getYaccelerationApi(void);
float getZaccelerationApi(void);

#endif