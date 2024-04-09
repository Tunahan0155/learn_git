/*
 * bleApp.cpp
 * These procedures handle bluetooth low energy app
 * 
 * Created on: 07/04/2024 by Tunahan Arslan
 * Updated on: 07/04/2024 by Tunahan Arslan
*/

/*- Includes ------------------------------------------*/
#include <ArduinoJson.h>
#include "bleApp.h"
#include "bleApi.h"
#include "accelerometerApp.h"
#include "registerControl.h"
#include "timer.h"

/*- Definition ----------------------------------------*/
const size_t JSON_CAPACITY = JSON_OBJECT_SIZE(6);
StaticJsonDocument<JSON_CAPACITY> doc;
Timer_t transmitTimer;

/*- Implamentations -----------------------------------*/
void setJson(std::string key, float value) {
    doc[key] = value;
}

void createJson(void) {
    setJson("REG_ROTATION_X", readRegister(REG_ROTATION_X));
    setJson("REG_ROTATION_Y", readRegister(REG_ROTATION_Y));
    setJson("REG_ROTATION_Z", readRegister(REG_ROTATION_Z));
    setJson("REG_ACCELEROMETER_X", readRegister(REG_ACCELEROMETER_X));
    setJson("REG_ACCELEROMETER_Y", readRegister(REG_ACCELEROMETER_Y));
    setJson("REG_ACCELEROMETER_Z", readRegister(REG_ACCELEROMETER_Z));
    setJson("REG_ACCELEROMETER_INTERVAL", readRegister(REG_ACCELEROMETER_INTERVAL));
}

std::string getJson(void) {
    std::string json;
    serializeJson(doc, json);
    return json;
}

RegId_t convertEnum(const std::string& key) {
    if (key == "REG_ACCELEROMETER_INTERVAL") {
        return REG_ACCELEROMETER_INTERVAL;
    }
    return NONE;
}

void receiveBle(void){
    if(isBleConnected()){
        if(getBleMessageStatusApi() == messageReceived){
            std::string bleMessage = receiveBleMessageApi();
            StaticJsonDocument<200> doc;
            deserializeJson(doc, bleMessage);
            for (JsonPair kv : doc.as<JsonObject>()) {
                std::string key = kv.key().c_str();
                uint16_t value = kv.value().as<uint16_t>();
                RegId_t regId = convertEnum(key);
                writeRegister(regId, value);
                startTimer(&transmitTimer, readRegister(REG_ACCELEROMETER_INTERVAL), INTERVAL);
            }
        }
    }
}

void transmitBle(void){
    if(isBleConnected()){
        if(checkTimer(&transmitTimer)){
            accelerometerApp();
            createJson();
            transmitBleMessageApi(getJson());
        }
    }
}

void bleInitApp(std::string bleName){
    bleInitApi(bleName);
    startTimer(&transmitTimer, readRegister(REG_ACCELEROMETER_INTERVAL), INTERVAL);
}

void bleApp(void){
    receiveBle();
    transmitBle();
}