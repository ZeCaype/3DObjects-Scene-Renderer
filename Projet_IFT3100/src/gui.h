#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:
	Gui();

	void setup();
	void update();
	void draw();

	ofxPanel gui;

	~Gui();
};