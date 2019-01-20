/*
   DataPort.h - Library for pinduino shield for Arduinos.
   Created by Eric Lyons, 2019.
   Released into the public domain.
   Play more pinball!
   */
#ifndef DataPort_h
#define DataPort_h

#include <Arduino.h>

class DataPort
{
  public:
    //Constructor
    //set appropriate pin for sending signals
    DataPort(int pin);

    //Functions
    void high(); // set pin output to high
    void low(); // set pin output to low

  private:
    //Variables
    int _pin; //Arduino pin being used
};

#endif
