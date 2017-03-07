#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "ofAppNoWindow.h"
#include "application.h"

// Point d'entr�e de l'application
int main() 
{
	ofAppNoWindow window;
	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
	ofRunApp(new Application());
}