#include "gui.h"

// Constructeur de la classe
Gui::Gui()
{
}

// Fonction invoquée à l'initialisation de l'application
void Gui::setup()
{
	ofSetWindowTitle("Gui");
	
	gui.setup("Panneau");
	gui.add(exportButton.setup("Exportation")); exportCheck = false;
	gui.add(testButton.setup("bouton test"));  

	//Cercle UI
	guiCircle.setup("Circle", "",  0, ofGetWindowHeight()/2);
	guiCircle.add(circleRadius.setup("circle radius", 205/2, 5, 200));
}

// Fonction
void Gui::update()
{
}

// Fonction
void Gui::draw()
{
	if (exportButton && exportCheck == false)
	{
		//imageExport("render", "png"); ----> À corriger!
		ofLog() << "<image is in file /bin/data/" << ">";
		exportCheck = true;
	}
	else if (!exportButton) exportCheck = false;
	gui.draw();
	guiCircle.draw();
}

int Gui::getRadius() {
	return circleRadius;
}

// Destructeur de la classe
Gui::~Gui()
{
}