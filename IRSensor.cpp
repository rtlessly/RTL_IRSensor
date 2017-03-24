#define DEBUG 0

#include <Arduino.h>
#include <Debug.h>
#include "IRSensor.h"


static DebugHelper Debug("IRSensor");


//EVENT_ID IRSensor::DETECT_EVENT = EventSource::GenerateEventID(); 


IRSensor::IRSensor(const int pin, const uint8_t mode=MODE_STATECHANGE, const int ledPin)
{
    _state.SensorPin = pin;
    _state.LedPin = ledPin;
    _state.Mode = mode;
    _state.LastReading = false;
}


bool IRSensor::Read()
{
    // read the IR sensor line
    bool reading = (digitalRead(_state.SensorPin) == LOW);
    bool lastReading = _state.LastReading;

    Debug.Log("Read => reading=%b, lastReading=%b, _state.TriggerCount=%i", reading, lastReading);

    _state.LastReading = reading;

    if (_state.Mode == MODE_CONTINUOUS || reading != lastReading)
    {
        Event event(DETECT_EVENT, reading);

        DispatchEvent(&event);
    }

    return reading;
}


void IRSensor::Poll()
{
    Read();
}

