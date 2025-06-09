#ifndef SMART
#define SMART

class SmartDevice {
    private: 
        static int deviceCount;
        char* name;
        char* type;
        bool status;
        int powerConsumption;
        mutable int usageCount;

    public:
        SmartDevice();
        SmartDevice(const char* _name, const char* _type, int _powerConsumption);
        SmartDevice(const SmartDevice& copied);
        ~SmartDevice();
        bool togglePower();
        void showStatus() const;
        int getUsageCount() const;
        static int getDeviceCount();
        const char* getName() const;
        const char* getType() const;
        int getPowerConsumption() const;
        void setName(const char* _name);
};

class SmartHome {
    private:
        char* homeName;
        SmartDevice** devices;
        int deviceIndex;
        const int maxDevices;

    public:
        SmartHome(const char* _homeName, int _maxDevices);
        ~SmartHome();
        void addDevice(const SmartDevice& smartDevice);
        bool removeDevice(const char* name);
        void showDevices() const;
};


#endif