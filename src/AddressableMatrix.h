/*
   AddressableMatrixp.h - Library for Pinduino to handle a matrix of addressable LEDs.
   Created by Eric Lyons 2020.
   Released into the public domain.
   Play more pinball!
   */
#ifndef AddressableMatrix_h
#define AddressableMatrix_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <AddressableStrip.h>

class AddressableMatrix
{
  public:
    //Constructor
    //initialize strip for appropriate data pin
    AddressableMatrix(AddressableStrip* strip, int cols, int rows, int start);

    // Adafruit_NeoPixel (# of LEDs, Signal Pin, Refresh Rate)
    Adafruit_NeoPixel* strip();

    int start();
    int stop();

    //functions for controlling 5V Addressable RGB strips
    //valid colors are (case insensitive):  red, green, blue, yellow, cyan, purple, white, orange, lime, sky, mint, magenta, lavender
    void color2RGB(String color, int &r, int &g, int &b);

    //color the entire strip some color
    void color(String color);
    void color(int r, int g, int b);
    
    //If you want to specify by R, G, B values between 0-255
    void colorRGB(int r, int g, int b);

    void clear();

    //fade in strip to given color by color RGB values
    void fadeInRGB(int r, int g, int b, float time);

    //fade color to color
    void fadeRGB2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float time);

    //fade out 
    void fadeOut(float steps);

    //sparkle
    void sparkleRGB(int r, int g, int b, int density, int speed);



  private:
    int _pin; //data pin 
    int _numLEDs = 0; // number of LEDs in strip;
    int _cols = 0; // number of columns in matrix
    int _rows = 0; // number of rows in matrix
    int _start = 0; // start position along the LED strip for the matrix
    int _stop = 0; // end position along the LED strip for the matrix
    Adafruit_NeoPixel* _strip; 
};

#endif
