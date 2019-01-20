#include <Arduino.h>
#include <DataPort.h>

DataPort::DataPort(int pin)
{
  //Set up arduino pin to be used
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void DataPort::high()
{
  digitalWrite(_pin,HIGH);
}

void DataPort::low()
{
  digitalWrite(_pin, LOW);
}
