/*
 * accelerometerHal.cpp
 * These procedures handle mma845x accelerometer driver
 *
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
 */

/*- Includes ------------------------------------------*/
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include "mma845x_driver.h"
#include "accelerometerApi.h"

/*- Definition ----------------------------------------*/
Adafruit_LIS3DH lis = Adafruit_LIS3DH();
sensors_event_t event;

/*- Implamentations -----------------------------------*/
void mma845xInitDriver(void)
{
    while (1)
    {
        if (lis.begin(0x19))
            break;
    }
}

void getRotationDriver(AxisType_t type, int16_t *rotation)
{
    lis.read();
    switch (type)
    {
        case X:
            *rotation = lis.x;
            break;
        case Y:
            *rotation = lis.y;
            break;
        case Z:
            *rotation = lis.z;
            break;
    }
}

void getAccelerationDriver(AxisType_t type, float *acceleration)
{
    lis.getEvent(&event);
    switch (type)
    {
        case X:
            *acceleration = event.acceleration.x;
            break;
        case Y:
            *acceleration = event.acceleration.y;
            break;
        case Z:
            *acceleration = event.acceleration.z;
            break;
    }
}