#include "Application.h"

Application::Application() 
{
}

//--------------------------------------------------------------
void Application::setup() 
{
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
	ofRunMainLoop();
}

//--------------------------------------------------------------
void Application::update() 
{
}

Application::~Application()
{
}

