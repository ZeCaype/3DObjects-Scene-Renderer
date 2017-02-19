#pragma once

#include "ofMain.h"

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