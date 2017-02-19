#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"
#include "Application.h"

// Point d'entrée de l'application
int main() {
	// Initialisation d'une instance ofAppGLFWWindow (GLFW renderer)
	ofAppGLFWWindow window;

	// Configuration du multisample antialiasing (MSAA)
	window.setNumSamples(16);

	// Configuration de la fenêtre principale
	ofSetupOpenGL(&window, 768, 768, OF_WINDOW);

	// Instancier et lancer l'application
	ofRunApp(new Application());
}