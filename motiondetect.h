
#ifndef MOTIONDETECT_H
#define MOTIONDETECH_H
#include <Arduino.h>


class MotionDetect
{
    public:
        bool motion_detected = false;
        bool active_relay = false;
        int sensorPIN;
        int ledPIN;
        unsigned long elapsed_time;
        unsigned long interval = 1500;
        unsigned long onTime = 180000;   // 3 min
        
        MotionDetect(int sensorPIN,int ledPIN);
        void setpinSensor();
        bool motionControl();
        bool activetimeControl();
        void activeforthreeMin();
        void sendSignal(int state);

};

#endif
