#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:

	int offsetX;




	Gui();

	void setup();
	void update();
	void draw();
	int getRadius();
	float getFov();

	ofxPanel gui;
	ofxButton exportButton; bool exportCheck;

	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	ofxPanel guiCamera;
	ofxFloatSlider fovSlider;

	~Gui();
};