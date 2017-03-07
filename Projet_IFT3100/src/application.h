#pragma once

#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "renderer.h"
#include "gui.h"

class Application : public ofBaseApp {

public:
	Renderer * renderer;
	Gui * gui;

	Application();
	
	void setup();
	void update();

	~Application();
};
