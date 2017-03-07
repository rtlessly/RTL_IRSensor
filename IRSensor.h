#ifndef _IRSensor_H_
#define _IRSensor_H_

#include <inttypes.h>
#include <EventSource.h>


class IRSensor : public EventSource
{
    public: static EVENT_ID DETECT_EVENT; 
    
    public: static const uint8_t MODE_STATECHANGE = 0;
    public: static const uint8_t MODE_CONTINUOUS  = 1;

    //****************************************************************************
    // Constructors
    //****************************************************************************
    public: IRSensor(const int pin=12, const uint8_t mode=MODE_STATECHANGE, const int ledPin=13);
    
    //****************************************************************************
    // Public methods
    //****************************************************************************
    public: virtual bool Read();

    public: virtual void Poll();

    //****************************************************************************
    // Internal State & Behavior
    //****************************************************************************  
    struct 
    {
        uint16_t SensorPin   : 5;
        uint16_t LedPin      : 5;
        uint16_t Mode        : 1;
        uint16_t LastReading : 1;
    } _state;
};

#endif

