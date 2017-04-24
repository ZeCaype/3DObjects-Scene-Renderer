#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "ofAppNoWindow.h"
#include "application.h"
#include "gui.h"

// Point d'entr�e de l'application
int main() 
{
	// Param�trisation de la fen�tre du rendue
	ofGLFWWindowSettings settings;
	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(12, 35));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	settings.setGLVersion(4, 1);
	// Initialisation du programme
	shared_ptr<Application> mainApp(new Application(new Gui()));
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}