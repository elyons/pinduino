#Functions for controlling 5V Addressable RGB strips


These functions are accessed using the addressable LED object (adrLED)
Normally called:

`pd.adrLED1()->function_name(parameters);`


Many functions take in color parameters.  Color parameters can be specified in two way:
* RGB (red, green, blue) values
* By color name.  
** Valid color names are (case insensitive):  red, green, blue, yellow, cyan, purple, white, orange, lime, sky, mint, magenta, lavender


There are usually two types of each function.  One for using RGB values and one for using color names.

Time:  Time is in milliseconds, so time = 1000 means 1 second

Direction (dir):  direction of effect.  1 is from input to end (of LED strip); -1 is end to input     

```arduino
// Clear the strip of all colors
void clear();
Example: pd.adrLED1()->clear();

//fade out strip (fades strip to all LEDs off)
void fadeOut(float steps);
Example: pd.adrLED1()->fadeOut(200);

//color the entire strip some color (brightness is a value between 1-255)
//note: I’ve seen problems when brightness is set to 0 and the LEDs not working afterwards
void color(String color, int brightness);
Example: pd.adrLED1()->color("red", 255);

//If you want to specify by R, G, B values between 0-255
void colorRGB(int r, int g, int b, int brightness);
Example: pd.adrLED1()->colorRGB(255, 0, 0, 255);

// fade in strip to given color by color name
void fadeIn(String color, float time);
Example: pd.adrLED1()->fadeIn("red", 1000);

//fade in strip to given color by color RGB values
void fadeInRGB(int r, int g, int b, float time);
Example: pd.adrLED1()->fadeInRGB(255, 0, 0, 255);  

//fade strip from color 1 to color 2 by color names
void fadeColor2Color(String color1, String Color2, float time);
Example: pd.adrLED1()->fadeColor2Color("red", "yellow", 1000);

//fade strip from color 1 to color 2 by RGB values
void fadeRGB2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float time);
Example: pd.adrLED1()->fadeRGB2RGB(255,0,0, 255,255,0, 1000);

//create a band of color with the middle at position pos of size span.  Colors are RGB and fade towards ends of band.  Note:  This is RARELY used directly
void RGBBand(int pos, int r, int g, int b, int span);
Example: pd.adrLED1()->RGBBand(10, 255,0,0, 10);
  
//create a moving band of light from one of the strip to the other that changes from color1 to color2 (RGB values).  dir is the direction of the light (which end it begins); span is the size of the band (values 1 for input to end; -1 for end to input)
void chase2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir);
Example: pd.adrLED1()->chase2RGB(255,0,0, 255,255,0, 10, 1000, 1);

// same as chase2RGB but uses color names
void chase2Color(String color1, String color2, float span, int time, int dir);
Example: pd.adrLED1()->chase2Color("red", "yellow", 10, 1000, 1);

//same as chase2RGB but for one color
void chaseRGB(int r, int g, int b, int span, int time, int dir);
Example: pd.adrLED1()->chaseRGB(255,0,0, 10, 1000, 1);

//same as chaseRGB, but uses color name
void chase(String color, float span, int time, int dir);
Example: pd.adrLED1()->chase("red", 10, 1000, 1);

//create two moving bands of light from position pos that changes from color 1 to color2 (RGB values). dir is the direction of the light (which end it begins); span is the size of the band
void chase2RGBFromPoint(int pos, float r1, float g1, float b1, float r2, float g2, float b2, int span, int time);
Example: pd.adrLED1()->chase2RGBFromPoint(20, 255,0,0, 255,255,0, 10, 1000);

//same as chase2RGBFromPoint, but uses color names
void chase2ColorFromPoint(int pos, String color1, String color2, int span, int time);
Example: pd.adrLED1()->chase2ColorFromPoint(20, "red", "yellow", 10, 1000);

//starting a position pos, fill the entire strip with light to both ends.  Color changes from color 1 to color2 (RGB values)
void spreadInFromPoint2RGB (int pos, float r1, float g1, float b1, float r2, float g2, float b2, int time);
Example: pd.adrLED1()->spreadInFromPoint2RGB(10, 255,0,0, 255,255,0, 1000);


//same as spreadInFromPoint2RGB, but uses color names
void spreadInFromPoint2Color (int pos, String color1, String color2, int time);
Example: pd.adrLED1()->spreadInFromPoint2Color(20, "red", "yellow", 1000);


// same as spreadInFromPoint2RGB, but remains one color (RGB value)
void spreadInFromPointRGB (int pos, float r, float g, float b, int time);
Example: pd.adrLED1()->spreadInFromPointRGB(20, 255,0,0, 1000);

//same as spreadInFromPointRGB, but uses color name
void spreadInFromPoint (int pos, String color, int time);
Example: pd.adrLED1()->spreadInFromPoint(20, "red", 1000);

//with the strip already colored, turn off LEDs starting at position pos and spreading to the ends of the strip
void spreadOutFromPoint (int pos, float time);
Example: pd.adrLED1()->spreadOutFromPoint(50, 1000);
  
//with the stirp already colored, turn off LEDs start at ends of the stip and spreading to position pos
void spreadOutToPoint (int pos, float time);
Example: pd.adrLED1()->spreadOutToPoint(50, 1000);
  
//create a splash of color (RGB values) at position pos for width span
void explosionRGB(int pos, int r, int g, int b, int span);  
Example: pd.adrLED1()->explosion(255, 0, 0, 5);

//same as explosionRGB but uses color name
void explosion(int pos, String color, int span);
Example: pd.adrLED1()->explosion(20, "red", 5);
Means:  Do explosion effect for LED strip 1 at position 10th LED, color red, span (size of explosion) 5 LEDs
```
