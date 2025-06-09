 #include "Smart.h"
 #include <iostream>
 
 int main() {
    SmartHome myHome{"MyHome" , 5};
    SmartDevice device1{"Living RoomLight 1" , "Smart Light" , 10};
    SmartDevice device2{device1};
    device2.setName("Living RoomLight 2");
    SmartDevice device3{"Bedroom AC" , "Smart Thermostat" , 1500};
    SmartDevice device4{"Front Door Cam" , "Security Camera" , 5};
    myHome.addDevice(device1);
    myHome.addDevice(device2);
    myHome.addDevice(device3);
    myHome.addDevice(device4);
    std::cout << "Device count: " << SmartDevice::getDeviceCount() << "\n";
    std::cout << "\n−−− All Devices −−−\n";
    std::cout << "Device count: " << SmartDevice::getDeviceCount() << "\n";
    myHome.showDevices() ;
    std::cout << "\n−−−Removing a Device −−−\n";
    if (myHome.removeDevice("Living RoomLight 2")) {
        std::cout << "Removed: " << "Living RoomLight 2" << "\n";
    }
    std::cout << "Device count: " << SmartDevice::getDeviceCount() << "\n";
    myHome.showDevices() ;
    return 0;
 }