
#include "BH1750Lib.h"


BH1750Lib lightSensor;

//I go 100 due to my room got read as dark but if I would put it outside it would be around 10000 lx
int Brightness = 100;
int MSecond = 1000;
bool IsDark = true;

// bool wasDark = false;

String EventName = "LightTest";

void setup() {
    
    Serial.begin(9600);
    lightSensor.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
}

void loop() {
    
    // delay(MSecond * 5);
    int lux = lightSensor.lightLevel();
    
    if(lux >= Brightness && IsDark){
        IsDark = false;
        Particle.publish(EventName,"Light");
    }else if(!(lux >= Brightness) && !(IsDark)){
        IsDark = true;
        Particle.publish(EventName,"Dark");
    }

    delay(MSecond * 5);

}
