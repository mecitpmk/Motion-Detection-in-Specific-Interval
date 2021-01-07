#include "motiondetect.h"


MotionDetect::MotionDetect(int sensorPIN,int ledPIN)
{
    this->sensorPIN = sensorPIN;
    this->ledPIN = ledPIN;
}

void MotionDetect::setpinSensor()
{
    pinMode(this->sensorPIN,INPUT);
    pinMode(this->ledPIN,OUTPUT);
}


bool MotionDetect::motionControl()
{
    if (digitalRead(this->sensorPIN))
    {
        this->motion_detected = true;
        return true;
    }
    this->motion_detected = false;
    return false;
}

bool MotionDetect::activetimeControl()
{
    if (motionControl())
    {
        while (millis() - this->elapsed_time <= this->interval)
        {
            motionControl();
        }
    }
    if (this->motion_detected)
    {
        sendSignal(1);
        return true;
    }
    else
    {   
        sendSignal(0);   
        return false;
    }
}

void MotionDetect::sendSignal(int state)
{
    digitalWrite(this->ledPIN,state);
    
}
void MotionDetect::activeforthreeMin()
{
    if (activetimeControl())
    {
        while (millis()-elapsed_time <= this->onTime)
        {}
    }
}