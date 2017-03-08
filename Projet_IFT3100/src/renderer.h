#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "gui.h"

class Renderer : public ofBaseApp
{
public:
	int circleRadius;

	Renderer();

	void setup();
	void update();
	void draw();
	void setRadius(int radius);

	void keyPressed(int key);
	void keyReleased(int key);

	void imageExport(const string name, const string extension) const;
	void carredessin() const; 
	shared_ptr<Gui> gui;

	~Renderer();
};