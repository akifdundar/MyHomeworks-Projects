#include "Smart.h"
#include <iostream>

int SmartDevice::deviceCount = 0;

int _strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void _strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  
}

bool _strcmp(const char* str1, const char* str2) {
    int index = 0;
    while(str1[index] != '\0' && str2[index] != '\0') {
        if(str1[index] == str2[index]) {
            index++;
            continue;
        }
        else return false;
    }
    if(str1[index] == '\0' && str2[index] == '\0') return true;
    return false;
}

SmartDevice::SmartDevice() {
    name = new char[_strlen("DefaultName") + 1];
    _strcpy(name, "DefaultName");
    type = new char[_strlen("General") + 1];
    _strcpy(type, "General");

    status = false;
    usageCount = 0;
    deviceCount++;
}

SmartDevice::SmartDevice(const char* _name, const char* _type, int _powerConsumption) {
    name = new char[_strlen(_name) + 1];
    _strcpy(name, _name);
    type = new char[_strlen(_type) + 1];
    _strcpy(type, _type);

    powerConsumption = _powerConsumption;
    status = false;
    usageCount = 0;
    deviceCount++;
}

SmartDevice::SmartDevice(const SmartDevice& copied) {
    name = new char[_strlen(copied.getName()) + 1];
    _strcpy(name, copied.getName());
    type = new char[_strlen(copied.getType()) + 1];
    _strcpy(type, copied.type);

    status = false;
    usageCount = copied.getUsageCount();
    powerConsumption = copied.getPowerConsumption();
    deviceCount++;
}

SmartDevice::~SmartDevice() {
    delete[] name;
    delete[] type;

    deviceCount--;
}

bool SmartDevice::togglePower() {
    status = !status;
    return status;
}

void SmartDevice::showStatus() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Power Consumption: " << powerConsumption << "W" << std::endl;
    std::cout << "Status: " << (status ? "ON" : "OFF") << std::endl;
    usageCount++;
}

int SmartDevice::getUsageCount() const {
    return usageCount;
}

int SmartDevice::getDeviceCount() {
    return deviceCount;
}

const char* SmartDevice::getName() const {
    return name;
}

const char* SmartDevice::getType() const {
    return type;
}

int SmartDevice::getPowerConsumption() const {
    return powerConsumption;
}

void SmartDevice::setName(const char* _name) {
    delete[] name;
    name = new char[_strlen(_name) + 1];
    _strcpy(name, _name);
}

SmartHome::SmartHome(const char* _homeName, int _maxDevices) : maxDevices { _maxDevices } {
    homeName = new char[_strlen(_homeName) + 1];
    _strcpy(homeName, _homeName);
    devices = new SmartDevice*[maxDevices];
    deviceIndex = 0;
}

SmartHome::~SmartHome() {
    delete[] homeName;

    for (int i = 0; i < deviceIndex; i++) {
        delete devices[i];
    }

    delete[] devices;
}
        
void SmartHome::addDevice(const SmartDevice& smartDevice) {
    if(deviceIndex >= maxDevices) {
        std::cout << "Has reached to the max device!!" << std::endl;
        return;
    }
    devices[deviceIndex] = new SmartDevice(smartDevice);    
    deviceIndex++;
    std::cout << "Added: " << smartDevice.getName() << std::endl;
}
        
bool SmartHome::removeDevice(const char* _name) {
    for(int i = 0; i < deviceIndex; i++) {
            const char* name = devices[i]->getName();
            if(_strcmp(name, _name)) {
                delete devices[i];
                for(int k = i; k + 1 < deviceIndex; k++) {
                    devices[k] = devices[k + 1];
                }
                deviceIndex--;
                return true;
            }
    }
    return false;
}
        
void SmartHome::showDevices() const {
    std::cout << "Devices in My Home: " << std::endl; 
    for(int i = 0; i < deviceIndex; i++) {
        devices[i]->showStatus();
        printf("\n");
    }
}