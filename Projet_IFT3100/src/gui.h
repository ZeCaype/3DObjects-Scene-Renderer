#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:

	int offsetX;

	int defaultPosX;
	int defaultPosY;

	int defaultCircleRadius;
	float defaultFov;

	Gui();

	void setup();
	void reset();
	void update();
	void draw();

	int getPosImageX();
	int getPosImageY();

	int getRadius();
	float getFov();

	ofxPanel guiImage;
	ofxButton exportButton; bool exportCheck;
	ofxIntSlider posImageX;
	ofxIntSlider posImageY;

	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	ofxPanel guiCamera;
	ofxFloatSlider fovSlider;

	~Gui();
};