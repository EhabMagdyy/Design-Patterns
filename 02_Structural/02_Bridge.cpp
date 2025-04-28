#include <iostream>

// Implementation Layer: Defines the interface that concrete devices must implement
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Device() = default;
};

// Concrete Implementation: TV
class TV : public Device {
public:
    void turnOn() override {
        std::cout << "TV is ON\n";
    }

    void turnOff() override {
        std::cout << "TV is OFF\n";
    }
};

// Concrete Implementation: Radio
class Radio : public Device {
public:
    void turnOn() override {
        std::cout << "Radio is ON\n";
    }

    void turnOff() override {
        std::cout << "Radio is OFF\n";
    }
};

// Abstraction Layer: RemoteControl holds a reference to a Device
class RemoteControl {
protected:
    Device* device;  // Bridge: connects to the implementation

public:
    RemoteControl(Device* d) : device(d) {}
    virtual void powerButton() = 0;
    virtual ~RemoteControl() = default;
};

// Refined Abstraction: BasicRemote
class BasicRemote : public RemoteControl {
public:
    BasicRemote(Device* d) : RemoteControl(d) {}

    void powerButton() override {
        std::cout << "[BasicRemote] Power button pressed:\n";
        device->turnOn();
        device->turnOff();
    }
};

int main() {
    TV tv;
    Radio radio;

    // Create remotes for each device
    BasicRemote tvRemote(&tv);
    BasicRemote radioRemote(&radio);

    // Use the remotes to control the devices
    tvRemote.powerButton();     // Controls TV
    radioRemote.powerButton();  // Controls Radio

    return 0;
}
