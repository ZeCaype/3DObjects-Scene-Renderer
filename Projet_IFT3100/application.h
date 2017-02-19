#pragma once

#include "ofMain.h"
#include "renderer.h"
#include "gui.h"


class application : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyReleased(int key);

};
