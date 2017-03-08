#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "ofAppNoWindow.h"
#include "application.h"
#include "gui.h"

// Point d'entrée de l'application
int main() 
{
	ofGLFWWindowSettings settings;
	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(50, 50));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	shared_ptr<Application> mainApp(new Application(new Gui()));
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}