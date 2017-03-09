#include "Application.h"

Application::Application(Gui *guipam) 
{
	gui = guipam;

	isKeyPressA = false;
	isKeyPressD = false;
	isKeyPressE = false;
	isKeyPressH = false;
	isKeyPressI = false;
	isKeyPressJ = false;
	isKeyPressK = false;
	isKeyPressQ = false;
	isKeyPressR = false;
	isKeyPressS = false;
	isKeyPressU = false;
	isKeyPressW = false;
	isKeyPressY = false;

	renderer = nullptr;

	ofGLFWWindowSettings settings;

	settings.width = 300;
	settings.height = 800;
	settings.setPosition(ofVec2f(700, 50));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
	guiWindow->setVerticalSync(false);
	shared_ptr<Gui> guiApp(gui);
	ofRunApp(guiWindow, guiApp);
}

//--------------------------------------------------------------
void Application::setup() 
{
	ofLog() << "<application::setup>";

	renderer = new Renderer();
	renderer->setup();
}

//--------------------------------------------------------------
void Application::update()
{
	//Camera/////////////////////////////////////////////////////////////
	if (renderer->isCameraPerspective)
		ofSetWindowTitle("camera " + renderer->cameraName + " perpective (1-6 wasdqe uhjkyi r)");
	else
		ofSetWindowTitle("camera " + renderer->cameraName + " orthographic");

	renderer->isCameraMoveForward = isKeyPressW;
	renderer->isCameraMoveBackward = isKeyPressS;

	renderer->isCameraMoveLeft = isKeyPressA;
	renderer->isCameraMoveRight = isKeyPressD;

	renderer->isCameraMoveUp = isKeyPressQ;
	renderer->isCameraMoveDown = isKeyPressE;

	renderer->isCameraTiltUp = isKeyPressJ;
	renderer->isCameraTiltDown = isKeyPressU;

	renderer->isCameraPanLeft = isKeyPressH;
	renderer->isCameraPanRight = isKeyPressK;

	renderer->isCameraRollLeft = isKeyPressY;
	renderer->isCameraRollRight = isKeyPressI;

	//renderer->isCameraFovNarrow = isKeyPressZ;
	//renderer->isCameraFovWide = isKeyPressX;

	///////////////////////////////////////////////////////////////////////////

	renderer->setRadius(gui->getRadius());
	renderer->setFieldOfView(gui->getFov());
	renderer->setPosXSlider(gui->getPosXSlider());
	renderer->setPosYSlider(gui->getPosYSlider());
	renderer->setposXTriangleSlider(gui->getposXTriangleSlider());
	renderer->setposYTriangleSlider(gui->getposYTriangleSlider());
	renderer->setposXEllipseSlider(gui->getposXEllipseSlider());
	renderer->setposYEllipseSlider(gui->getposYEllipseSlider());
	// Image
	if (gui->exportButton && gui->exportCheck == false)
	{
		int test = ofGetWidth();
		renderer->imageExport("render", "png");
		ofLog() << "<image is in file /bin/data/" << ">";
		gui->exportCheck = true;
	}
	else if (!gui->exportButton) gui->exportCheck = false;

	// Rectangle
	if (gui->primitiveCarreButton && gui->primitiveCarreCheck == false)
	{
		renderer->primitiveRectangle(10, 10);
		gui->primitiveCarreCheck = true;
	}
	else if (!gui->primitiveCarreButton) gui->primitiveCarreCheck = false;


	// Ellipse
	if (gui->primitiveEllipse && gui->primitiveEllipseCheck == false)
	{
		renderer->primitiveEllispe(10,10);
		gui->primitiveEllipseCheck = true;
	}
	else if (!gui->primitiveEllipse) gui->primitiveEllipseCheck = false;

	// Triangle
	if (gui->primitiveTriangle && gui->primitiveTriangleCheck == false)
	{
		renderer->primitiveTriangle(10, 10);
		gui->primitiveTriangleCheck = true;
	}
	else if (!gui->primitiveTriangle) gui->primitiveTriangleCheck = false;

	

	renderer->setPosImageX(gui->getPosImageX());
	renderer->setPosImageY(gui->getPosImageY());
	renderer->setSizeImageWidth(gui->getSizeImageWidth());
	renderer->setSizeImageHeight(gui->getSizeImageHeight());
	renderer->setHueImage(gui->getHueImage());
	renderer->setSaturationImage(gui->getSaturationImage());
	renderer->setBrightnessImage(gui->getBrightnessImage());
	renderer->setAlphaImage(gui->getAlphaImage());

	renderer->update();
}

void Application::draw() {
	renderer->draw();
}


Application::~Application()
{
	if (nullptr != renderer)
		delete renderer;
}

void Application::keyPressed(int key) {

	switch (key) {
		case 97:  // key A
			isKeyPressA = true;
			break;

		case 100: // key D
			isKeyPressD = true;
			break;

		case 101: // key E
			isKeyPressE = true;
			break;

		case 104: // key H
			isKeyPressH = true;
			break;

		case 105: // key I
			isKeyPressI = true;
			break;

		case 106: // key J
			isKeyPressJ = true;
			break;

		case 107: // key K
			isKeyPressK = true;
			break;

		case 113: // key Q
			isKeyPressQ = true;
			break;

		case 115: // key S
			isKeyPressS = true;
			break;

		case 117: // key U
			isKeyPressU = true;
			break;

		case 119: // key W
			isKeyPressW = true;
			break;

		case 121: // key Y
			isKeyPressY = true;
			break;

		default:
			break;
	}
}


void Application::keyReleased(int key) {
	switch (key) {
		case 49:  // key 1
			renderer->cameraActive = Camera::FRONT;
			renderer->setupCamera();
			break;

		case 50:  // key 2
			renderer->cameraActive = Camera::BACK;
			renderer->setupCamera();
			break;

		case 51:  // key 3
			renderer->cameraActive = Camera::LEFT;
			renderer->setupCamera();
			break;

		case 52:  // key 4
			renderer->cameraActive = Camera::RIGHT;
			renderer->setupCamera();
			break;

		case 53:  // key 5
			renderer->cameraActive = Camera::TOP;
			renderer->setupCamera();
			break;

		case 54:  // key 6
			renderer->cameraActive = Camera::DOWN;
			renderer->setupCamera();
			break;

		case 97:  // key A
			isKeyPressA = false;
			break;

		case 100: // key D
			isKeyPressD = false;
			break;

		case 101: // key E
			isKeyPressE = false;
			break;

		case 104: // key H
			isKeyPressH = false;
			break;

		case 105: // key I
			isKeyPressI = false;
			break;

		case 106: // key J
			isKeyPressJ = false;
			break;

		case 107: // key K
			isKeyPressK = false;
			break;

		case 111: // key O
			renderer->isCameraPerspective = false;
			renderer->setupCamera();
			ofLog() << "<orthographic projection>";
			break;

		case 112: // key P
			renderer->isCameraPerspective = true;
			renderer->setupCamera();
			ofLog() << "<perpective projection>";
			break;

		case 113: // key Q
			isKeyPressQ = false;
			break;

		case 114: // key R
			renderer->reset();
			gui->reset();
			break;

		case 115: // key S
			isKeyPressS = false;
			break;

		case 117: // key U
			isKeyPressU = false;
			break;

		case 119: // key W
			isKeyPressW = false;
			break;

		case 121: // key Y
			isKeyPressY = false;
			break;

		default:
			break;
	}
}

// Fonction invoquée quand une sélection de fichiers est déposée sur la fenêtre de l'application
void Application::dragEvent(ofDragInfo dragInfo)
{
	ofLog() << "<app::ofDragInfo file[0]: " << dragInfo.files.at(0)
		<< " at : " << dragInfo.position << ">";

	// Importer le premier fichier déposé sur la fenêtre si c'est une image (attention : aucune validation du type de fichier !)
	renderer->fond.load(dragInfo.files.at(0));

	// Activer le chargement de l'image dans le rendue
	renderer->isFondLoaded = true;

	/*// Redimensionner la fenêtre aux dimensions de l'image
	if (renderer->fond.getWidth() > 0 && renderer->fond.getHeight() > 0)
	ofSetWindowShape(renderer->fond.getWidth(), renderer->fond.getHeight());*/
}