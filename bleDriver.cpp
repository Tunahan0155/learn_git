/*
 * bleDriver.cpp
 * These procedures handle bluetooth low energy driver
 *
 * Created on: 05/04/2024 by Tunahan Arslan
 * Updated on: 05/04/2024 by Tunahan Arslan
 */

/*- Includes ------------------------------------------*/
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include "bleDriver.h"
#include "bleHal.h"

BLEServer *pServer = NULL;

BLECharacteristic *pCharacteristic_Receive = NULL;
BLECharacteristic *pCharacteristic_Transmit = NULL;

class MyServerCallbacks : public BLEServerCallbacks
{
  void onDisconnect(BLEServer *pServer)
  {
    setBleDisconnectionHal();
    BLEDevice::startAdvertising();
  }
  void onConnect(BLEServer *pServer)
  {
    setBleConnectionHal();
  }
};

class MyCallbacks_Receive : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic_Receive)
  {
    std::string value = pCharacteristic_Receive->getValue();
    const char *charArray = value.c_str();
    if (value.length() > 0)
    {
      receiveBleMessageHal(value);
    }
  }
};

void transmitBleMessageDriver(std::string message)
{
  pCharacteristic_Transmit->setValue(message.c_str());
  pCharacteristic_Transmit->notify();
}

/*- Implamentations -----------------------------------*/
void bleInitDriver(std::string bleName)
{
  BLEDevice::init(bleName);
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic_Receive = pService->createCharacteristic(
      CHARACTERISTIC_UUID_Receive,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_WRITE |
      BLECharacteristic::PROPERTY_INDICATE
  );
  pCharacteristic_Transmit = pService->createCharacteristic(
      CHARACTERISTIC_UUID_Transmit,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_WRITE |
      BLECharacteristic::PROPERTY_NOTIFY |
      BLECharacteristic::PROPERTY_INDICATE
  );
  pCharacteristic_Receive->setCallbacks(new MyCallbacks_Receive());
  pCharacteristic_Transmit->addDescriptor(new BLE2902());
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);
  BLEDevice::startAdvertising();
}