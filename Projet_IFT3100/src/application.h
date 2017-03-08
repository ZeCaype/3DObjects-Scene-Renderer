#pragma once

#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "renderer.h"
#include "gui.h"

class Application : public ofBaseApp {

private:
	
	Gui * gui;
public:

	bool isKeyPressA;
	bool isKeyPressD;
	bool isKeyPressE;
	bool isKeyPressH;
	bool isKeyPressI;
	bool isKeyPressJ;
	bool isKeyPressK;
	bool isKeyPressQ;
	bool isKeyPressR;
	bool isKeyPressS;
	bool isKeyPressU;
	bool isKeyPressW;
	bool isKeyPressY;

	Renderer * renderer;

	Application(Gui *guipam);

	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);

	void dragEvent(ofDragInfo dragInfo);

	~Application();
};
