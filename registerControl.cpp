/*
 * registerControl.c
 * These procedures handle to control registersTable
 * 
 * Created on: 04/04/2024 by Tunahan Arslan
 * Updated on: 04/04/2024 by Tunahan Arslan
*/

/*- Includes ------------------------------------------*/
#include <ArduinoJson.h>
#include <stdint.h>
#include <stdio.h>
#include "registerControl.h"

/*- Definition ----------------------------------------*/
Registers_t registersTable[] = {
    {REG_ROTATION_X, 0, INT16},
    {REG_ROTATION_Y, 0, INT16},
    {REG_ROTATION_Z, 0, INT16},
    {REG_ACCELEROMETER_X, 0, FLOAT},
    {REG_ACCELEROMETER_Y, 0, FLOAT},
    {REG_ACCELEROMETER_Z, 0, FLOAT},
    {REG_ACCELEROMETER_INTERVAL, 1000, UINT16},
};

/*- Implamentations -----------------------------------*/
void writeRegister(RegId_t regName, float value) {
    uint16_t registersTableSize = sizeof(registersTable) / sizeof(registersTable[0]);
    for (uint16_t registerIndex = 0; registerIndex < registersTableSize; registerIndex++) {
        if (registersTable[registerIndex].name == regName) {
            switch (registersTable[registerIndex].size) {
                case UINT8:
                    registersTable[registerIndex].value = ((uint8_t)value);
                case INT8:
                    registersTable[registerIndex].value = ((int8_t)value);
                case UINT16:
                    registersTable[registerIndex].value = ((uint16_t)value);
                case INT16:
                    registersTable[registerIndex].value = ((int16_t)value);
                case UINT32:
                    registersTable[registerIndex].value = ((uint32_t)value);
                case INT32:
                    registersTable[registerIndex].value = ((int32_t)value);
                case UINT64:
                    registersTable[registerIndex].value = ((int64_t)value);
                case INT64:
                    registersTable[registerIndex].value = ((int64_t)value);
                case FLOAT:
                    registersTable[registerIndex].value = ((float)value);
            }
        }
    }
}

float readRegister(RegId_t regName) {
    uint16_t registersTableSize = sizeof(registersTable) / sizeof(registersTable[0]);
    for (uint16_t registerIndex = 0; registerIndex < registersTableSize; registerIndex++) {
        if (registersTable[registerIndex].name == regName) {
            switch (registersTable[registerIndex].size) {
                case UINT8:
                    return ((uint8_t)registersTable[registerIndex].value);
                case INT8:
                    return ((int8_t)registersTable[registerIndex].value);
                case UINT16:
                    return ((uint16_t)registersTable[registerIndex].value);
                case INT16:
                    return ((int16_t)registersTable[registerIndex].value);
                case UINT32:
                    return ((uint32_t)registersTable[registerIndex].value);
                case INT32:
                    return ((int32_t)registersTable[registerIndex].value);
                case UINT64:
                    return ((uint64_t)registersTable[registerIndex].value);
                case INT64:
                    return ((int64_t)registersTable[registerIndex].value);
                case FLOAT:
                    return ((float)registersTable[registerIndex].value);
            }
        }
    }
    return 0;
}