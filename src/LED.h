/*
 * LED.hpp
 *
 *  Created on: Apr 7, 2017
 *      Author: christian
 */
#ifndef LED_HPP_
#define LED_HPP_

#include "jetsonGPIO.h"

class LED {
public:
	pinValue state;
	jetsonGPIO trigger;
	
	//LED object with trigger gpio value and initial state. State Defaulted to off
	LED(jetsonGPIO trigger);
	void off();
	void on();
};
#endif
