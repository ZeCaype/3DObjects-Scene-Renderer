#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:

	Gui();

	void setup();
	void update();
	void draw();
	int getRadius();

	ofxPanel gui;
	ofxButton exportButton; bool exportCheck;
	ofxButton testButton; 
	ofxLabel testLabel; 

	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	~Gui();
};