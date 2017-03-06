#include "Application.h"

Application::Application() 
{
}

//--------------------------------------------------------------
void Application::setup() {
	renderer = new Renderer();
	gui = new Gui();

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

	shared_ptr<Renderer> mainApp(renderer);
	shared_ptr<Gui> guiApp(gui);
	mainApp->gui = guiApp;

	ofRunApp(guiWindow, guiApp);
	ofRunApp(mainWindow, mainApp);
}

//--------------------------------------------------------------
void Application::update() {
	// Configuration du rayon du cercle
	renderer->setRadius(gui->getRadius());
	
	// Exportation du rendue de l'image
	if (gui->exportButton && gui->exportCheck == false)
	{
		HWND hWnd = FindWindow(NULL, L"Rendue de l'image");
		if (hWnd) SetForegroundWindow(hWnd);
		renderer->imageExport("render", "png");
		ofLog() << "<image is in file /bin/data/" << ">";
		gui->exportCheck = true;
	}
	else if (!gui->exportButton) gui->exportCheck = false;
}

//--------------------------------------------------------------
void Application::draw() {
}

//--------------------------------------------------------------
void Application::keyReleased(int key) {

}

Application::~Application(){

}

