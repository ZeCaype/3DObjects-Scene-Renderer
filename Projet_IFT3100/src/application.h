#pragma once

#include "ofMain.h"
#include "renderer.h"

class Application : public ofBaseApp {
public:
	Renderer * renderer;

	Application();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void exit();

	~Application();
};
