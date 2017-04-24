#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "ofAppNoWindow.h"
#include "application.h"
#include "gui.h"

// Point d'entrée de l'application
int main() 
{
	// Paramétrisation de la fenêtre du rendue
	ofGLWindowSettings settings;
	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(12, 35));
	//settings.resizable = true;
	
	// sélection de la version de OpenGL : option #1
	//settings.setGLVersion(2,1);

	// sélection de la version de OpenGL : option #2
	//settings.setGLVersion(3,3);

	// sélection de la version de OpenGL : option #3
	//settings.setGLVersion(4,1);

	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	// Initialisation du programme
	shared_ptr<Application> mainApp(new Application(new Gui()));
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}