// ../myTP2/renderer.h
// Classe responsable du rendu de l'image

#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"

class Renderer
{
public:
	Renderer();

	void setup();
	void reset();
	void update();
	void draw();

	void imageExport(const string name, const string extension) const;

	~Renderer();
};