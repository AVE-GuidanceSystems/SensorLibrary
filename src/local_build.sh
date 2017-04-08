#!/bin/bash
g++ ./Sensors.cpp -Wall -o ./../SensorsApp `pkg-config --cflags glib-2.0 --libs glib-2.0` ./drv2605.cpp ./drv2605.h ./jetsonGPIO.c ./Ultrasonic.cpp ./LED.cpp
