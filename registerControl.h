/*
 * registerControl.h
 * These procedures handle to control registersTable
 * 
 * Created on: 04/04/2024 by Tunahan Arslan
 * Updated on: 04/04/2024 by Tunahan Arslan
*/

#ifndef REGISTER_CONTROL_H
#define REGISTER_CONTROL_H

/*- Declaration ---------------------------------------*/
typedef enum {
    UINT8,
    INT8,
    UINT16,
    INT16,
    UINT32,
    INT32,
    UINT64,
    INT64,
    FLOAT,
} RegisterSizes_t;

typedef enum {
    NONE = 0,
    REG_ROTATION_X = 20,
    REG_ROTATION_Y = 21,
    REG_ROTATION_Z = 22,
    REG_ACCELEROMETER_X = 23,
    REG_ACCELEROMETER_Y = 24,
    REG_ACCELEROMETER_Z = 25,
    REG_ACCELEROMETER_INTERVAL = 26,
} RegId_t;

typedef struct {
    const RegId_t name;      
    float value;          
    const RegisterSizes_t size;       
} Registers_t;

/*- Implamentations -----------------------------------*/
void writeRegister(RegId_t regName, float value);
float readRegister(RegId_t regName);

#endif