#pragma once

#include "ofMain.h"
#include "renderer.h"
#include "gui.h"
#include "ofAppGLFWWindow.h"

class Application : public ofBaseApp {

public:
	Renderer * renderer;
	Gui * gui;

	Application();
	
	void setup();
	void update();
	void draw();

	~Application();

};
