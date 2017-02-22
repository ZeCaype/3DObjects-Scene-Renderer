#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "application.h"

#include "ofAppNoWindow.h"

// Point d'entrée de l'application
int main() 
{
	ofAppNoWindow window;
	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
	ofRunApp(new Application());
}