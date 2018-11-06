#ifndef __DEVICE_H__
#define __DEVICE_H__

enum class DeviceState: char
{
    RUNNING,
    QUITTING,
    ERROR
};

class Device
{
private:
    DeviceState m_state;

public:
    Device();
    ~Device();

    const DeviceState& GetState() const;
    void SetState(const DeviceState&);
};

#endif