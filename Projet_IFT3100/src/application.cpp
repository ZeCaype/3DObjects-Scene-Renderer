#include "Application.h"

// Constructeur de la classe Application
Application::Application(Gui *guipam) 
{
	gui = guipam;

	// Déclaration des touches de clavier
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

	// Paramétrisation de la fenêtre du gui
	ofGLFWWindowSettings settings;
	settings.width = 600;
	settings.height = 800;
	settings.setPosition(ofVec2f(700, 50));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
	guiWindow->setVerticalSync(false);
	shared_ptr<Gui> guiApp(gui);
	ofRunApp(guiWindow, guiApp);
}

// Paramétrisation de la classe Application
void Application::setup() 
{
	ofLog() << "<application::setup>";

	// Initialisation de la paramétrisation du rendue
	renderer = new Renderer();
	renderer->setup();
}

//--------------------------------------------------------------
void Application::update()
{
	// Appel des fonctions de la caméra
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

	renderer->circleRadius = gui->getRadius();
	renderer->setFieldOfView(gui->getFov());
	renderer->cameraNear = gui->getCameraNear();
	renderer->cameraFar = gui->getCameraFar();

	// Appel des fonctions de la paramétrisation des formes géométriques
	renderer->posRectangleX=(gui->getPosXSlider());
	renderer->posRectangleY=(gui->getPosYSlider());

	renderer->positionXEllipse = (gui->getPositionXEllipseSlider());
	renderer->positionYEllipse = (gui->getPositionYEllipseSlider());
	renderer->positionZEllipse = (gui->getPositionZEllipseSlider());

	renderer->positionXRectangle = (gui->getPositionXRectangleSlider());
	renderer->positionYRectangle = (gui->getPositionYRectangleSlider());
	renderer->positionZRectangle = (gui->getPositionZRectangleSlider());


	renderer->posEllipseX=(gui->getposXEllipseSlider());
	renderer->posEllipseY=(gui->getposYEllipseSlider());
	renderer->tx1=(gui->getTX1());
	renderer->tx2=(gui->getTX2());
	renderer->ty1=(gui->getTY1());
	renderer->ty2=(gui->getTY2());
	renderer->tz1 = (gui->getTZ1());
	renderer->tz2 = (gui->getTZ2());

	renderer->rstroke=(gui->getCSRS());
	renderer->gstroke=(gui->getCSGS());
	renderer->bstroke=(gui->getCSBS());
	renderer->rfill=(gui->getCSRF());
	renderer->gfill=(gui->getCSGF());
	renderer->bfill=(gui->getCSBF());

	renderer->rfond=(gui->getFOND_R());
	renderer->gfond=(gui->getFOND_G());
	renderer->bfond=(gui->getFOND_B());

	renderer->posformeVectorielleX=(gui->getformeVectorielleXSlider());
	renderer->posformeVectorielleY=(gui->getformeVectorielleYSlider());
	renderer->posformeVectorielleZ = (gui->getformeVectorielleZSlider());

	renderer->setToggle(gui->getToggleRectangle());
	renderer->setToggle(gui->getToggleEllipse());
	renderer->setToggle(gui->getToggleLigne());

	renderer->contourLargeur = gui->getContour();

	// Appel de la fonction du rectangle
	if (gui->primitiveCarreButton && gui->primitiveCarreCheck == false)
	{
		renderer->primitiveRectangle(10, 10);
		gui->primitiveCarreCheck = true;
	}
	else if (!gui->primitiveCarreButton) gui->primitiveCarreCheck = false;
	// Appel de la fonction de l'ellipse
	if (gui->primitiveEllipse && gui->primitiveEllipseCheck == false)
	{
		renderer->primitiveEllispe(10,10);
		gui->primitiveEllipseCheck = true;
	}
	else if (!gui->primitiveEllipse) gui->primitiveEllipseCheck = false;
	// Appel de la fonction de la ligne
	if (gui->primitiveLigne && gui->primitiveLigneCheck == false)
	{
		renderer->primitiveLigne(10, 10);
		gui->primitiveLigneCheck = true;
	}
	else if (!gui->primitiveLigne) gui->primitiveLigneCheck = false;

	//Forme Vectorielle 
	if (gui->formeVectorielleButton && gui->formeVectorielleCheck == false)
	{
	renderer->FormeVectorielle(10, 10);

	gui->formeVectorielleCheck = true;
	}
	else if (!gui->formeVectorielleButton) gui->formeVectorielleCheck = false;
	// Appel des fonction de la paramétrisation de l'image
	renderer->posImageX=(gui->getPosImageX());
	renderer->posImageY=(gui->getPosImageY());
	renderer->sizeImageWidth=(gui->getSizeImageWidth());
	renderer->sizeImageHeight=(gui->getSizeImageHeight());
	renderer->hueImage=(gui->getHueImage());
	renderer->saturationImage=(gui->getSaturationImage());
	renderer->brightnessImage=(gui->getBrightnessImage());
	renderer->alphaImage=(gui->getAlphaImage());
	// Appel de la fonction d'exportation de l'image
	if (gui->exportButton && gui->exportCheck == false)
	{
		int test = ofGetWidth();
		renderer->imageExport("render", "png");
		ofLog() << "<image is in file /bin/data/" << ">";
		gui->exportCheck = true;
	}
	else if (!gui->exportButton) gui->exportCheck = false;
	// Appel de la rotation des images dans le vecteur d'images importées
	if (gui->importButton && gui->importCheck == false)
	{
		std::rotate(renderer->vecteurImage.begin(),
			renderer->vecteurImage.end() - 1, // Ça va être le premier élément
			renderer->vecteurImage.end());
		gui->importCheck = true;
	}
	else if (!gui->importButton) gui->importCheck = false;

	// Appel de la fonction d'importation d'un modèle 3D
	if (gui->modelButton && gui->modelCheck == false)
	{
		renderer->model.loadModel(renderer->nameModel);
		renderer->model.setRotation(0, 90, 90, 0, 0);
		renderer->model.setPosition(0, -400, -200);
		gui->modelCheck = true;
	}
	else if (!gui->modelButton) gui->modelCheck = false;

	// Appel pour la position de la lumière
	renderer->xLight=(gui->getXLight());
	renderer->yLight=(gui->getYLight());
	renderer->zLight=(gui->getZLight());

	// Appels du Toggle
	if (gui->rec == true && gui->ell == false && gui->lig == false)
	{
		renderer->ReactionRec();
	}
	else if (gui->rec == false && gui->ell == true && gui->lig == false)
	{
		renderer->ReactionEll();
	}
	else if (gui->rec == false && gui->ell == false && gui->lig == true)
	{
		renderer->ReactionLig();
	}

	renderer->update();
}

// Appel de la fonction pour dessiner sur le rendue
void Application::draw() 
{
	renderer->draw();
}

// Appel des fonctions lorsqu'une touche donnée est appuyée
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

// Appel des fonctions d'une touche appuyée donnée lorsqu'elle est relachée
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
	// Message de confirmation dans la console
	ofLog() << "<app::ofDragInfo file[0]: " << dragInfo.files.at(0)
		<< " at : " << dragInfo.position << ">";

	// Importer le premier fichier déposé sur la fenêtre si c'est une image (attention : aucune validation du type de fichier !)
	renderer->fond.load(dragInfo.files.at(0));

	// Ajouter l'image importée au vecteur d'images
	renderer->vecteurImage.push_back(renderer->fond);

	// Activer le chargement de l'image dans le rendue
	renderer->isFondLoaded = true;

	// Redimensionner la fenêtre aux dimensions de l'image
	/*if (renderer->fond.getWidth() > 0 && renderer->fond.getHeight() > 0)
	ofSetWindowShape(renderer->fond.getWidth(), renderer->fond.getHeight());*/
}

// Destructeur de la classe Application
Application::~Application()
{
	if (nullptr != renderer)
		delete renderer;
}
