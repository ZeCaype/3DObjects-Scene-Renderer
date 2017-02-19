#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "renderer.h"
#include "gui.h"

// Point d'entrée de l'application
int main() 
{
	// Déclaration des configurations des fenêtres
	ofGLFWWindowSettings settings;

	settings.width = 768;
	settings.height = 768;
	settings.setPosition(ofVec2f(600, 200));
	settings.resizable = true;
	settings.numSamples = 16;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	
	settings.width = 256;
	settings.height = 768;
	settings.setPosition(ofVec2f(326, 200));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

	shared_ptr<Renderer> mainApp(new Renderer());
	shared_ptr<Gui> guiApp(new Gui());
	mainApp->gui = guiApp;

	ofRunApp(guiWindow, guiApp);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
	//Test Louis
}