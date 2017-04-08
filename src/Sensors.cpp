// exampleApp.c

#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
#include "jetsonGPIO.h"
#include <stdio.h>
#include "drv2605.h"
#include "Ultrasonic.h"
#include "LED.h"


//Ultrasonic Sensor Object Declaration
UltrasoundSensor Sensor[2] = {UltrasoundSensor(gpio38, gpio37), UltrasoundSensor(gpio184, gpio219)}; //Sensor(trigger, echo, led)
LED LEDS[2] = {LED(gpio186), LED(gpio63)};
DRV2605 Haptics[2] = {DRV2605(gpio186,0), DRV2605(gpio63,0)};

using namespace std;


int main(int argc, char *argv[]){

    cout << "Range Finding Test" << endl;
    while(1){
		for (int i = 0; i<2; i++){
			Sensor[i].getDistance();
			cout << Sensor[i].distance << endl;
			//Range Threshold
			if ((Sensor[i].distance >= 300) || (Sensor[i].distance <= 20)){
				//Turn off Indicators Indicators
				LEDS[i].off();
				Haptics[i].setTrigger(off);
			}
			else{
				//Turn on Indicators
				LEDS[i].off();
				Haptics[i].setTrigger(on);
			}	
				Sensor[i].printDistance(1);
				usleep(30);
		} 
	}   
}

