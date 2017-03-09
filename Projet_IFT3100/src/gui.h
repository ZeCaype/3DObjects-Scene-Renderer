#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:

	int offsetX;

	int defaultPosX;
	int defaultPosY;
	int defaultSizeImageWidth;
	int defaultSizeImageHeight;
	int defaultHueImage;
	int defaultSaturationImage;
	int defaultBrightnessImage;
	int defaultAlphaImage;

	int defaultCircleRadius;
	float defaultFov;

	Gui();

	void setup();
	void reset();
	void update();
	void draw();

	float getPosXSlider();
	float getPosYSlider();

	float posX;
	float posY;

	int getPosImageX();
	int getPosImageY();
	int getSizeImageWidth();
	int getSizeImageHeight();
	int getHueImage();
	int getSaturationImage();
	int getBrightnessImage();
	int getAlphaImage();



	int getRadius();
	float getFov();

	ofxPanel guiImage;

	ofxButton exportButton; bool exportCheck;
	


	ofxIntSlider posImageX;
	ofxIntSlider posImageY;
	ofxIntSlider sizeImageWidth;
	ofxIntSlider sizeImageHeight;
	ofxIntSlider hueImage;
	ofxIntSlider saturationImage;
	ofxIntSlider brightnessImage;
	ofxIntSlider alphaImage;

	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	ofxPanel guiCamera;
	ofxFloatSlider fovSlider;

	ofxPanel guiPrimitive;
	ofxFloatSlider posXSlider;
	ofxFloatSlider posYSlider;

	ofxButton primitiveCarreButton; bool primitiveCarreCheck;
	ofxButton primitiveEllipse; bool primitiveEllipseCheck;
	ofxButton primitiveTriangle; bool primitiveTriangleCheck;

	~Gui();
};