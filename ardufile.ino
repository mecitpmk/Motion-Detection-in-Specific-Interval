#include <motiondetect.h>



MotionDetect *motionObj = new MotionDetect(2,5);


void setup()
{

    motionObj->setpinSensor();

}

void loop()
{
    motionObj->elapsed_time = millis();
//    motionObj->LightsOn();
    motionObj->activeforthreeMin();
}