#ifndef _IRSensor_H_
#define _IRSensor_H_

#include <inttypes.h>
#include <RTL_StdLib.h>
#include <EventSource.h>


class IRSensor : public EventSource
{
    DECLARE_CLASSNAME;
    
    public: static const EVENT_ID DETECT_EVENT = (EventSourceID::IRSensor | EventCode::DefaultEvent);     
    public: static const uint8_t MODE_STATECHANGE = 0;
    public: static const uint8_t MODE_CONTINUOUS  = 1;

    
    //****************************************************************************
    // Constructors
    //****************************************************************************
    public: IRSensor(const uint8_t pin=12, const uint8_t mode=MODE_STATECHANGE);
    
    //****************************************************************************
    // Public methods
    //****************************************************************************
    public: bool Read();

    public: void Poll();

    //****************************************************************************
    // Internal State & Behavior
    //****************************************************************************  
    struct 
    {
        uint16_t SensorPin   : 5;
        uint16_t Mode        : 1;
        uint16_t LastReading : 1;
    } _state;
};

#endif

