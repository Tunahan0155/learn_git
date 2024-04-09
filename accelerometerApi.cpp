/*
 * accelerometerApi.cpp
 * These procedures handle accelerometer api
 * 
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
*/

/*- Includes ------------------------------------------*/
#include "accelerometerApi.h"
#include "accelerometerHal.h"

/*- Definition ----------------------------------------*/
RotationValue_t rotationValue;
AccelerometerValue_t accelerometerValue;

/*- Implamentations -----------------------------------*/
void accelerometerInitApi(void){
    accelerometerInitHal();
}

int16_t getXrotationApi(void){
    getRotationHal(X, &rotationValue.X);
    return rotationValue.X;
}
int16_t getYrotationApi(void){
    getRotationHal(Y, &rotationValue.Y);
    return rotationValue.Y;
}
int16_t getZrotationApi(void){
    getRotationHal(Z, &rotationValue.Z);
    return rotationValue.Z;
}

float getXaccelerationApi(void){
    getAccelerationHal(X, &accelerometerValue.X);
    return accelerometerValue.X;
}
float getYaccelerationApi(void){
    getAccelerationHal(Y, &accelerometerValue.Y);
    return accelerometerValue.Y;
}
float getZaccelerationApi(void){
    getAccelerationHal(Z, &accelerometerValue.Z);
    return accelerometerValue.Z;
}