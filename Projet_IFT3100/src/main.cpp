#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "ofAppNoWindow.h"
#include "application.h"
#include "gui.h"

// Point d'entr�e de l'application
int main() 
{
	// Param�trisation de la fen�tre du rendue
	ofGLWindowSettings settings;
	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(12, 35));
	//settings.resizable = true;
	
	// s�lection de la version de OpenGL : option #1
	//settings.setGLVersion(2,1);

	// s�lection de la version de OpenGL : option #2
	//settings.setGLVersion(3,3);

	// s�lection de la version de OpenGL : option #3
	//settings.setGLVersion(4,1);

	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	// Initialisation du programme
	shared_ptr<Application> mainApp(new Application(new Gui()));
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}