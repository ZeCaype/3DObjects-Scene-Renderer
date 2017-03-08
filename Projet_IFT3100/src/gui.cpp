#include "gui.h"

// Constructeur de la classe
Gui::Gui()
{
}

// Fonction invoquée à l'initialisation de l'application
void Gui::setup()
{
	ofSetWindowTitle("Gui");
	
	offsetX = 30;
	defaultCircleRadius = 205 / 2;
	defaultFov = 60;

	gui.setup("Panneau", "", offsetX, 30);
	gui.add(exportButton.setup("Exportation")); exportCheck = false;

	//Cercle UI
	guiCircle.setup("Sphere", "", offsetX, 90);
	guiCircle.add(circleRadius.setup("circle radius", defaultCircleRadius, 5, 200));

	//Camera
	guiCamera.setup("Camera", "", offsetX, 150);
	guiCamera.add(fovSlider.setup("Field of view", defaultFov, 0, 120));
}

void Gui::reset() {
	ofLog() << "<reset gui>";
	defaultCircleRadius = 205/2;
	defaultFov = 60;
}

// Fonction
void Gui::update()
{
}

// Fonction
void Gui::draw()
{
	gui.draw();
	guiCircle.draw();
	guiCamera.draw();
}

int Gui::getRadius() 
{
	return circleRadius;
}

float Gui::getFov()
{
	return fovSlider;
}

// Destructeur de la classe
Gui::~Gui()
{
}