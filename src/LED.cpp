/*
 * LED.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: christian
 */
#include "LED.h"
using namespace std;

LED::LED(jetsonGPIO trigger){
	//reset pins for use
	gpioUnexport(trigger);
	
	gpioExport(trigger);
	
	//Set Directions
	gpioSetDirection(trigger,1);
	
	//Set Default values
	gpioSetValue(trigger, 0);
}

void LED::off(){
	gpioSetValue(trigger, 0);
}

void LED::on(){
	gpioSetValue(trigger, 1);
}
