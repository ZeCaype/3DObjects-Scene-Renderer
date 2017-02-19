#include "gui.h"

// Constructeur de la classe
Gui::Gui()
{
}

// Fonction invoqu�e � l'initialisation de l'application
void Gui::setup()
{
	ofSetWindowTitle("Gui");
	
	gui.setup("Panneau");
	gui.add(exportButton.setup("Exportation")); exportCheck = false;
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
		//imageExport("render", "png"); ----> � corriger!
		ofLog() << "<image is in file /bin/data/" << ">";
		exportCheck = true;
	}
	else if(!exportButton) exportCheck = false;

}

// Destructeur de la classe
Gui::~Gui()
{
}