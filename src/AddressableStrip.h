/*
   RGBStrip.h - Library for pinduino shield for Arduinos.
   Created by Eric Lyons and Wes Sparks, 2015.
   Released into the public domain.
   Play more pinball!
   */
#ifndef AddressableStrip_h
#define AddressableStrip_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <pinduinoPins.h>

class AddressableStrip
{
  public:
    //Constructor
    //initialize strip for appropriate data pin
    AddressableStrip(int num, int pin, pinduinoPins* pinState);

    void setNumLEDs(int num);
    int getNumLEDs();
    int getDataPin();
    AddressableStrip* next();
    void setNext(AddressableStrip* strip);
    AddressableStrip* previous();
    void setPrevious(AddressableStrip* strip);


    // Adafruit_NeoPixel (# of LEDs, Signal Pin, Refresh Rate)
    Adafruit_NeoPixel* strip();

    //functions for controlling 5V Addressable RGB strips
    //valid colors are (case insensitive):  red, green, blue, yellow, cyan, purple, white, orange, lime, sky, mint, magenta, lavender
    void color2RGB(String color, int &r, int &g, int &b);

		//return a random valid color
		String randomColor();
    
    //color the entire strip some color
    void color(String color, int brightness);
    void color(String color);
    void color(int r, int g, int b);
    
    //If you want to specify by R, G, B values between 0-255
    void colorRGB(int r, int g, int b, int brightness);
    void colorRGB(int r, int g, int b);

    void clear();
    // fade in strip to given color by color name
    void fadeIn(String color, float time);

    //fade in strip to given color by color RGB values
    void fadeInRGB(int r, int g, int b, float time);

    //fade out strip
    void fadeOut(float steps);

    //fade strip from color 1 to color 2 by RGB values
    void fadeRGB2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float time);

    //fade strip from color 1 to color 2 by color names
    void fadeColor2Color(String color1, String Color2, float time);

    //create a band of color with the middle at position pos of size span.  Colors are RGB and fade towards ends of band
    void RGBBand(int pos, int r, int g, int b, int span);

    //create a moving band of light from one of the strip to the other that changes from color1 to color2 (RGB values).  dir is the direction of the light (which end it begins); span is the size of the band
    void chase2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir);

    // same as chase2RGB but uses color names
    void chase2Color(String color1, String color2, float span, int time, int dir);

    //same as chase2RGB but for one color
    void chaseRGB(int r, int g, int b, int span, int time, int dir);

    //same as chaseRGB, but uses color name
    void chase(String color, float span, int time, int dir);

    //create two moving bands of light from position pos that changes from color 1 to color2 (RGB values). dir is the direction of the light (which end it begins); span is the size of the band
    void chase2RGBFromPoint(int pos, float r1, float g1, float b1, float r2, float g2, float b2, int span, int time);

    //same as chase2RGBFromPoint, but uses color names
    void chase2ColorFromPoint(int pos, String color1, String color2, int span, int time);

    //starting a position pos, fill the entire strip with light to both ends.  Color changes from color 1 to color2 (RGB values)
    void spreadInFromPoint2RGB (int pos, float r1, float g1, float b1, float r2, float g2, float b2, int time);

    //same as spreadInFromPoint2RGB, but uses color names
    void spreadInFromPoint2Color (int pos, String color1, String color2, int time);

    // same as spreadInFromPoint2RGB, but remains one color (RGB value)
    void spreadInFromPointRGB (int pos, float r, float g, float b, int time);

    //same as spreadInFromPointRGB, but uses color name
    void spreadInFromPoint (int pos, String color, int time);

    //with the strip already colored, turn off LEDs starting at position pos and spreading to the ends of the strip
    void spreadOutFromPoint (int pos, float time);

    //with the stirp already colored, turn off LEDs start at ends of the stip and spreading to position pos
    void spreadOutToPoint (int pos, float time);

    //create a splash of color (RGB values) at position pos for width span
    void explosionRGB(int pos, int r, int g, int b, int span);

    //same as explosionRGB but uses color name
    void explosion(int pos, String color, int span);

    //Rainbow effect
    void rainbow(int wait);
    void rainbowCycle(int wait);
    int Wheel(int WheelPos);

    void chase2RGBCont(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir, int startLED, int endLED);
    void chase2ColorCont(String Color1, String Color2, float span, int time, int dir, int startLED, int endLED);
    void chaseColorCont(String color, float span, int time, int dir, int startLED, int endLED);
    void RGBBandCont(int pos, int r, int g, int b, int span, int startLED, int endLED);
    
    //bullet and overloaded constructors for bullet lighting functions
		//RGBBullet is the routine that draws the bullet.  The other routines specify where the bullet is drawn, its colors, and how it moves
    void RGBBullet(int pos, int r, int g, int b, int span, int dir);
    void RGBBulletCont(int pos, int r, int g, int b, int span, int dir);

    void bullet(String color, float span, int time, int dir);
    void bullet(String color1, String color2, float span, int time, int dir);
    void bullet(int r, int g, int b, float span, int time, int dir);
    void bullet(int r1, int g1, int b1, int r2, int g2, int b2, float span, int time, int dir);
    void bullet(String color, float span, int time, int dir, int start, int stop);
    void bullet(String color1, String color2, float span, int time, int dir, int start, int stop);
    void bullet(int r, int g, int b, float span, int time, int dir, int start, int stop);
    void bullet(int r1, int g1, int b1, int r2, int g2, int b2, float span, int time, int dir, int start, int stop);
   
    void bullet2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir);
    void bullet2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir, int start, int stop);
    void bullet2Color(String color1, String color2, float span, int time, int dir, int start, int stop);
    void bullet2Color(String color1, String color2, float span, int time, int dir);
    void bulletRGB(int r, int g, int b, int span, int time, int dir);
    void bulletRGB(int r, int g, int b, int span, int time, int dir, int start, int stop);

    void bulletFromPoint2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int start_pos);
    void bulletFromPoint2Color(String color1, String color2, float span, int time, int start_pos);
    void bulletFromPointRGB(int r, int g, int b, int span, int time, int start_pos);
    void bulletFromPoint(String color, float span, int time, int start_pos);
    void multiBullet2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir, int num);
    void multiBullet2Color(String color1, String color2, float span, int time, int dir, int num);
    void multiBulletRGB(int r, int g, int b, int span, int time, int dir, int num);
    void multiBullet(String color, float span, int time, int dir, int num);
    void bulletP2P_2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir, int start, int stop);
    void bulletP2P_2Color(String color1, String color2, float span, int time, int dir, int start, int stop);
    void RGBMatrix(int rows, int r, int g, int b, int span, int dir);
    void Matrix2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir);
    void Matrix2Color(String color1, String color2, float span, int time, int dir);
    void sparkle (String color, int density, int speed);
    void sparkle (String color, int speed);
    void sparkleRGB (int r, int g, int b, int speed);
    void sparkleRGB (int r, int g, int b, int density, int speed);
    void marqueeRGB (int r, int g, int b, int span, int dist, int speed, int dir);
    void dataStreamRGB(int r, int g, int b, int density, int speed, int dir);
    void dataStream(String color, int density, int speed, int dir);
    void dataStreamNoTailRGB(int r, int g, int b, int density, int speed, int dir);
    void dataStreamNoTail(String color, int density, int speed, int dir);
    void dataStreamNoTail2RGB(float r1, float g1, float b1, float r2, float g2, float b2, int density, int speed, int dir);
    void dataStreamNoTail2Color(String color1, String color2, int density, int speed, int dir);
    void equalizerRGB(float r1, float g1, float b1, float r2, float g2, float b2, int span, int spd, int tipFallDelaySpan, int dir, int nofade);
    void equalizer(String color1, String color2, int span, int spd, int tipFallDelaySpan, int dir, int nofade);
    void equalizer(String color1, String color2, int span, int spd, int tipFallDelaySpan, int dir);
		void fire(int density, int speed);
    void meteorRain(int r, int g, int b, int meteorSize, int meteorTrailDecay, boolean meteorRandomDecan, int SpeedDelay);
    void fadeToBlack(int ledNo, byte fadeValue);

  private:
    int _pin; //data pin 
    int _numLEDs = 0; // number of LEDs in strip;
    Adafruit_NeoPixel* _strip; 
    pinduinoPins* _pinState;
    AddressableStrip* _next;
    AddressableStrip* _previous;

};

#endif

