#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Abstract class Device
class Device {
protected:
    string manufacturerName;
    string model;
    int quantity;
    double price;
    string color;

public:
    Device(string manufacturerName, string model, int quantity, double price, string color) {
        this->manufacturerName = manufacturerName;
        this->model = model;
        this->quantity = quantity;
        this->price = price;
        this->color = color;
    }

    virtual void printDeviceInfo() = 0; // Abstract method

    string getManufacturerName() const {
        return manufacturerName;
    }

    string getModel() const {
        return model;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }

    string getColor() const {
        return color;
    }
};

// MobilePhone class
class MobilePhone : public Device {
private:
    string networkType;

public:
    MobilePhone(string manufacturerName, string model, int quantity, double price, string color, string networkType)
        : Device(manufacturerName, model, quantity, price, color) {
        this->networkType = networkType;
    }

    void printDeviceInfo() {
        cout << "Mobile Phone: " << getManufacturerName() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << networkType << endl;
    }

    string getNetworkType() const {
        return networkType;
    }
};

// Laptop class
class Laptop : public Device {
private:
    string processorType;

public:
    Laptop(string manufacturerName, string model, int quantity, double price, string color, string processorType)
        : Device(manufacturerName, model, quantity, price, color) {
        this->processorType = processorType;
    }

    void printDeviceInfo() {
        cout << "Laptop: " << getManufacturerName() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << processorType << endl;
    }

    string getProcessorType() const {
        return processorType;
    }
};

// Tablet class
class Tablet : public Device {
private:
    string screenSize;

public:
    Tablet(string manufacturerName, string model, int quantity, double price, string color, string screenSize)
        : Device(manufacturerName, model, quantity, price, color) {
        this->screenSize = screenSize;
    }

    void printDeviceInfo() {
        cout << "Tablet: " << getManufacturerName() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << screenSize << endl;
    }

    string getScreenSize() const {
        return screenSize;
    }
};

// Shop class
class Shop {
private:
    vector<Device*> devices;

public:
    // Add a device to the list
    void addDevice(Device* device) {
        devices.push_back(device);
    }

    // Delete a device from the list by a given criterion (in this case, manufacturer name)
    void deleteDeviceByManufacturerName(string manufacturerName) {
        devices.erase(remove_if(devices.begin(), devices.end(), [&](Device* device) {
            return device->getManufacturerName() == manufacturerName;
            }), devices.end());
    }

    // List printing
    void printDevices() {
        for (auto device : devices) {
            device->printDeviceInfo();
        }
    }

    // Search for a device