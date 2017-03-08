#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:

	Gui();

	void setup();
	void update();
	void draw();
	void dessinerCarre(); 
	void dessinerCercle();
	void dessinerTriangle(); 
	int getRadius();

	ofxPanel gui;
	ofxButton exportButton; bool exportCheck;
	ofxButton carreButton; bool carreCheck;
	ofxButton cercleButton; bool cercleCheck; 
	ofxButton triangleButton;  bool triangleCheck; 
	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	~Gui();
};