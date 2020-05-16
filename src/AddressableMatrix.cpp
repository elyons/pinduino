#include <Arduino.h>
#include <AddressableMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <AddressableStrip.h>

AddressableMatrix::AddressableMatrix(AddressableStrip* strip, int col, int row, int start)
{
	//_numLEDs = strip->getNumLEDs();
  _cols = col;
  _rows = row;
  _start = start;
  _stop = start+(col*row)-1; // index of last pixel in matrix
	_strip = strip->strip();
}

//set entire strip one color based on RGB values
void AddressableMatrix::colorRGB(int r, int g, int b) {
	if (r<0) {r=0;}
	if (r>255) {r=255;}
	if (g<0) {g=0;}
	if (g>255) {g=255;}
	if (b<0) {b=0;}
	if (b>255) {b=255;}
	for(int i=_start; i<=_stop; i++) {
		_strip->setPixelColor(i, r, g, b);
	}
	_strip->show();
}

int AddressableMatrix::start() {
  return _start;
}

void AddressableMatrix::color(int r, int g, int b) {
    colorRGB(r,g,b);
}

int AddressableMatrix::stop() {
  return _stop;
}

//clear strip  turn off all colors
void AddressableMatrix::clear()
{
	colorRGB(0,0,0);
}

//fade in strip to an RGB color
void AddressableMatrix::fadeInRGB(int r, int g, int b, float time)
{
	time = time/256;
	_strip->setBrightness(1);
	colorRGB(r,g,b);
	if (time < 1) {time = 0;}
	for (int i = 1; i < 256; i++) {
		if (time) {delay(time);}
		_strip->setBrightness(i);
		_strip->show();
	}
	_strip->setBrightness(255);
	_strip->show();
}

//fade strip from RGB color to another RGB color
void AddressableMatrix::fadeRGB2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float time)
{
	time = time/256;
	colorRGB(r1,g1,b1);
	if (time < 1) {time = 0;}
	//calcuate color changes
	float rcs = abs(r1-r2)/256;
	if (r2 > r1){rcs=rcs*-1;}
	float gcs = abs(g1-g2)/256;
	if (g2 > g1){gcs=gcs*-1;}
	float bcs = abs(b1-b2)/256;
	if (b2 > b1){bcs=bcs*-1;}
	for (int i = 1; i < 256; i++) {
		if (time) {delay(time);}
		float r = r1-(rcs*i);
		float g = g1-(gcs*i);
		float b = b1-(bcs*i);
		colorRGB(r,g,b);
		_strip->show();
	}
}

//fade out strip
void AddressableMatrix::fadeOut(float steps)
{
	if (steps < 1){steps=1;}
	uint8_t origBrightness = _strip->getBrightness();
	float brightStep = origBrightness/steps; 

	for (int i=0; i<steps; i++) {
		int brightness = origBrightness-(brightStep+brightStep*i);
		if (brightness < 1) {brightness=1;}
		_strip->setBrightness(brightness);
		_strip->show();
	}
	clear();
	_strip->setBrightness(255);
}

void AddressableMatrix::sparkleRGB(int r, int g, int b, int density, int speed) {
	for(int x=_start; x<_stop; x++) {
		if (random(density)==0) _strip->setPixelColor(x, r, g, b);
		else {
			uint32_t color = _strip->getPixelColor(x);
			uint8_t red = ((color>>16) & 255)*0.88;
			uint8_t green = ((color>>8) & 255)*0.88;
			uint8_t blue = (color & 255)*0.88;
			_strip->setPixelColor(x, red, green, blue);
		}
		//_strip->setPixelColor(x,(_strip->getPixelColor(x)*0.88));
	}
	delay(speed);
	_strip->show();
}
