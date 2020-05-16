/*
  pinduino.h - Library for pinduino shield for Arduinos.
  Created by Eric Lyons and Wes Sparks, 2015.
  Released into the public domain.
  Play more pinball!
*/
#ifndef pinduino_h
#define pinduino_h

#include <Arduino.h>
#include <RGBStrip.h>
#include <AddressableStrip.h>
#include <AddressableMatrix.h>
#include <pinduinoPins.h>
#include <DataPort.h>
class pinduino
{
  protected:

  public:
  	//Constructor with no parameters
  	pinduino();
  	
    //Overloaded Constructor for addressable strips (arduinoType defaults to Mega)
    pinduino(int num1, int num2, int num3);


    //Overloaded Constructor for addressable strips
    pinduino(int num1, String arduinoType);
    pinduino(int num1, int num2, String arduinoType);
    pinduino(int num1, int num2, int num3, String arduinoType);
		
    //initialize pins for communication to/from arduino
		pinduinoPins* pinState();

    //functions for controlling 12V RGB strips
    RGBStrip* rgbLED1();
    RGBStrip* rgbLED2();
    RGBStrip* rgbLED3();
    RGBStrip* rgbLED4();

    //functions for controlling 5V Addressable LED strips
    AddressableStrip* adrLED1();    
    AddressableStrip* adrLED2();    
    AddressableStrip* adrLED3();    

    //functions for creating 5V Addressable LED matrices
    AddressableMatrix* adrMatrix(AddressableStrip* adr, int col, int row, int start);    

    //Functions for controlling output ports 
    DataPort* port1();
    DataPort* port2();
    DataPort* port3();

    //functions that affect multiple AddressableStrips simultaneously
    // color all strips
    void colorAllAdrRGB(int r, int g, int b);
    void colorAllAdr(String color);    
    //fade out all strips
    void fadeOutAllAdr(float time);
    //fade in all strips (note, colors on strips need to be set first using ALED1->color("red",1);)
    void fadeInAllAdr(String color, float time);
    void fadeInAllAdrRGB(int r, int g, int b, float time);
    void fadeAllAdrRGB2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float time);
    void fadeAllAdrColor2Color(String color1, String color2, float time);
    void chaseAllAdr2RGB (float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir);
    void chaseAllAdr2Color (String color1, String color2, float span, int time, int dir);
    void chaseAllAdr2RGBFromPoint(int pos, float r1, float g1, float b1, float r2, float g2, float b2, int span, int time);
	
    void testRGBStrip(RGBStrip* strip);
    void testRGBStrip1();
    void testRGBStrip2();
    void testRGBStrip3();
    void testRGBStrip4();

  	void testSpeakerAdrLED(AddressableStrip* strip);
	void testSpeakerAdrLED1();

	void testAdrLED(AddressableStrip* strip);
    void testAdrLED1();
    void testAdrLED2();
    void testAdrLED3();
    void testAdrLED4();
	
	void testAdrLEDAlpha(AddressableStrip* strip);
    void testAdrLED1Alpha();
    void testAdrLED2Alpha();
    void testAdrLED3Alpha();
	
     
  private:
		//internal object for monitoring pinball machine states
	pinduinoPins* _pinState;

		//internal objects for RGB strip control`
    RGBStrip* RGB1;
    RGBStrip* RGB2;
    RGBStrip* RGB3;
    RGBStrip* RGB4;

		//internal objects for AddressableStrip control
    AddressableStrip* ALED1;
    AddressableStrip* ALED2;
    AddressableStrip* ALED3;

    //internal objects for control output ports (set high and low for transistor/relay control)
    DataPort* DATAPORT1;
    DataPort* DATAPORT2;
    DataPort* DATAPORT3;

    
    void init(int aledNum1, int aledNum2, int aledNum3, String arduinoType);
};



#endif
