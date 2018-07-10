#define DEBUG 0

#include <Arduino.h>
#include <Debug.h>
#include "IRSensor.h"


DEFINE_CLASSNAME(IRSensor);


IRSensor::IRSensor(const uint8_t pin, const uint8_t mode)
{
    _id = "IRSensor";
    _state.SensorPin = pin;
    _state.Mode = mode;
    _state.LastReading = false;
}


bool IRSensor::Read()
{
    // read the IR sensor line
    bool reading = (digitalRead(_state.SensorPin) == LOW);

    TRACE(Logger(_classname_, this) << F(":Read: reading=") << reading << endl);
    _state.LastReading = reading;

    return reading;
}


void IRSensor::Poll()
{
    TRACE(Logger(_classname_, this) << F("Poll") << endl);

    bool oldReading = _state.LastReading;
    bool newReading = Read();

    if (_state.Mode == MODE_CONTINUOUS || newReading != oldReading)
    {
        TRACE(Logger(_classname_, this) << F(":Poll: newReading=") << newReading << F(", oldReading=") << oldReading << endl);
        QueueEvent(DETECT_EVENT, newReading);
    }
}

