#include "Application.h"

// Constructeur de la classe Application
Application::Application(Gui *guipam) 
{
	gui = guipam;

	// Initialisation des touches de clavier
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
	settings.width = 835;
	settings.height = 800;
	settings.setPosition(ofVec2f(600 + 2*12 + 5, 34));
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
	// Image //////////////////////////////////////////////////////////////////////////////////////
	// Appel des fonction de la paramétrisation de l'image
	renderer->posImageX = (gui->getPosImageX());
	renderer->posImageY = (gui->getPosImageY());
	renderer->sizeImageWidth = (gui->getSizeImageWidth());
	renderer->sizeImageHeight = (gui->getSizeImageHeight());
	renderer->hueImage = (gui->getHueImage());
	renderer->saturationImage = (gui->getSaturationImage());
	renderer->brightnessImage = (gui->getBrightnessImage());
	renderer->alphaImage = (gui->getAlphaImage());
	// Appel de la rotation des images dans le vecteur d'images importées
	if (gui->importButton && gui->importCheck == false)
	{
		std::rotate(renderer->vecteurImage.begin(),
			renderer->vecteurImage.end() - 1, // Ça va être le premier élément
			renderer->vecteurImage.end());
		gui->importCheck = true;
	}
	else if (!gui->importButton) gui->importCheck = false;
	// Appel de la fonction d'exportation de l'image de rendu
	if (gui->exportButton && gui->exportCheck == false)
	{
		renderer->imageExport("render", "png");
		ofLog() << "<image is in file /bin/data/" << ">";
		gui->exportCheck = true;
	}
	else if (!gui->exportButton) gui->exportCheck = false;

	// Dessin vectoriel ///////////////////////////////////////////////////////////////////////////
	// Formes 2D
	renderer->createRectangle = gui->getToggleRectangle();
	renderer->createEllipse = gui->getToggleEllipse();
	renderer->createLigne = gui->getToggleLigne();
	renderer->createFormeVectorielle = gui->getToggleFormeVectorielle();
	// Contour des formes 2D
	renderer->contourLargeur = gui->getContour();
	// Position du rectangle 1
	renderer->posRectangleX = (gui->getPosXSlider());
	renderer->posRectangleY = (gui->getPosYSlider());
	// Position du rectangle 2
	renderer->positionXRectangle = (gui->getPositionXRectangleSlider());
	renderer->positionYRectangle = (gui->getPositionYRectangleSlider());
	renderer->positionZRectangle = (gui->getPositionZRectangleSlider());
	// Position de l'ellipse 1
	renderer->posEllipseX = (gui->getposXEllipseSlider());
	renderer->posEllipseY = (gui->getposYEllipseSlider());
	// Position de l'ellipse 2
	renderer->positionXEllipse = (gui->getPositionXEllipseSlider());
	renderer->positionYEllipse = (gui->getPositionYEllipseSlider());
	renderer->positionZEllipse = (gui->getPositionZEllipseSlider());
	// Paramétrisation de la ligne
	renderer->tx1 = (gui->getTX1());
	renderer->tx2 = (gui->getTX2());
	renderer->ty1 = (gui->getTY1());
	renderer->ty2 = (gui->getTY2());
	renderer->tz1 = (gui->getTZ1());
	renderer->tz2 = (gui->getTZ2());
	renderer->lineWidth = (gui->getLineWidth());
	// Couleur des formes
	renderer->rstroke = (gui->getCSRS());
	renderer->gstroke = (gui->getCSGS());
	renderer->bstroke = (gui->getCSBS());
	renderer->rfill = (gui->getCSRF());
	renderer->gfill = (gui->getCSGF());
	renderer->bfill = (gui->getCSBF());

	// Transformation /////////////////////////////////////////////////////////////////////////////
	// Position et rotation de la forme vectorielle (fleur)
	renderer->posformeVectorielleX = (gui->getformeVectorielleRSlider())*sin(gui->getformeVectorielleTSlider())*cos(gui->getformeVectoriellePSlider());
	renderer->posformeVectorielleY = (gui->getformeVectorielleRSlider())*sin(gui->getformeVectorielleTSlider())*sin(gui->getformeVectoriellePSlider());
	renderer->posformeVectorielleZ = (gui->getformeVectorielleRSlider())*cos(gui->getformeVectorielleTSlider());
	renderer->rotAngle = (gui->getRotAngle());
	renderer->rotX = (gui->getRotX());
	renderer->rotY = (gui->getRotY());
	renderer->rotZ = (gui->getRotZ());

	// Géométrie //////////////////////////////////////////////////////////////////////////////////
	// Paramétrisation du cylindre
	renderer->positionPrimitive3dX = (gui->getpositionPrimitive3dX());
	renderer->positionPrimitive3dY = (gui->getpositionPrimitive3dY());
	renderer->positionPrimitive3dZ = (gui->getpositionPrimitive3dZ());
	renderer->primitive3dSize = (gui->getprimitive3dSize());
	renderer->primitice3dStroke = (gui->getToggleprimitive3dStroke());
	renderer->primitive3dRoatation = (gui->getToggleprimitive3dRotation());
	renderer->createPrimitive3d = (gui->getToggleprimitive3d());
	// Paramétrisation du cube
	renderer->positionPrimitive3dXBox = (gui->getpositionPrimitive3dXBox());
	renderer->positionPrimitive3dYBox = (gui->getpositionPrimitive3dYBox());
	renderer->positionPrimitive3dZBox = (gui->getpositionPrimitive3dZBox());
	renderer->primitive3dSizeBox = (gui->getprimitive3dSizeBox());
	renderer->primitice3dStrokeBox = (gui->getToggleprimitive3dStrokeBox());
	renderer->primitive3dRoatationBox = (gui->getToggleprimitive3dRotationBox());
	renderer->createPrimitive3dBox = (gui->getToggleprimitive3dBox());

	//paramétrisation de la sphere 3d 
	renderer->primitive3dSphere = (gui->getprimitive3dSphere());
	renderer->positionPrimitive3dXSphere = (gui->getpositionPrimitive3dXSphere());
	renderer->positionPrimitive3dYSphere = (gui->getpositionPrimitive3dYSphere());
	renderer->positionPrimitive3dZSphere = (gui->getpositionPrimitive3dZSphere());
	renderer->primitive3dSphereSize = (gui->getprimitive3dSizeSphere());
	renderer->primitive3dSphereRotation = (gui->getToggleprimitive3dRotationSphere());


	renderer->primitive3dSphereCouleur = (gui->getprimitive3dSphereCouleur());
	renderer->positionPrimitive3dXSphereCouleur = (gui->getpositionPrimitive3dXSphereCouleur());
	renderer->positionPrimitive3dYSphereCouleur = (gui->getpositionPrimitive3dYSphereCouleur());
	renderer->positionPrimitive3dZSphereCouleur = (gui->getpositionPrimitive3dZSphereCouleur());
	
	renderer->primitive3dStrokeSphereCouleur = (gui->getToggleprimitive3dStrokeSphereCouleur());
	renderer->primitive3dSphereRotationCouleur = (gui->getToggleprimitive3dRotationSphereCouleur());
	renderer->nbrCercleCouleur = (gui->getprimitive3dNombreSphereCouleur());
	
	renderer->circleRadius = gui->getRadius();

	// Appel de la fonction d'importation d'un modèle 3D
	if (gui->modelButton && gui->modelCheck == false)
	{
		renderer->model.loadModel(renderer->nameModel);
		renderer->model.setRotation(0, 90, 90, 0, 0);
		renderer->model.setPosition(0, -400, -200);
		renderer->isModelLoaded = true;
		gui->modelCheck = true;
	}
	else if (!gui->modelButton) gui->modelCheck = false;

	//Nuage de Points
	renderer->nuageDePoint = gui->getNuageDePoint();

	// Caméra /////////////////////////////////////////////////////////////////////////////////////
	// Appel des fonctions de la caméra


	if (renderer->isCameraPerspective && gui->getAspectRatio()) {
		ofSetWindowTitle("Camera " + renderer->cameraName + " Perspective 4:3 (1-6 wasdqe uhjkyi op)");
	}
	else if (renderer->isCameraPerspective) {
		ofSetWindowTitle("Camera " + renderer->cameraName + " Perspective 16:9 (1-6 wasdqe uhjkyi op)");
	}
	else
		ofSetWindowTitle("Camera " + renderer->cameraName + " Orthographique");

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

	renderer->cameraFov = gui->getFov();
	renderer->cameraNear = gui->getCameraNear();
	renderer->cameraFar = gui->getCameraFar();
	


	renderer->aspectRatio4_3 = gui->getAspectRatio();


	// Lumières /////////////////////////////////////////////////////////////////////////////////////
	// Appel pour la position de la lumière
	renderer->light1T = gui->getLight1();
	renderer->xLight1 = (gui->getXLight1());
	renderer->yLight1 = (gui->getYLight1());
	renderer->zLight1 = (gui->getZLight1());
	renderer->RLight1 = gui->getRLight1();
	renderer->GLight1 = gui->getGLight1();
	renderer->BLight1 = gui->getBLight1();

	renderer->light2T = gui->getLight2();
	renderer->xLight2 = (gui->getXLight2());
	renderer->yLight2 = (gui->getYLight2());
	renderer->zLight2 = (gui->getZLight2());
	renderer->RLight2 = gui->getRLight2();
	renderer->GLight2 = gui->getGLight2();
	renderer->BLight2 = gui->getBLight2();
	renderer->cutLight2 = gui->getCutLight2();
	renderer->concLight2 = gui->getConcLight2();

	renderer->light3T = gui->getLight3();
	renderer->xLight3 = (gui->getXLight3());
	renderer->yLight3 = (gui->getYLight3());
	renderer->zLight3 = (gui->getZLight3());
	renderer->RLight3 = gui->getRLight3();
	renderer->GLight3 = gui->getGLight3();
	renderer->BLight3 = gui->getBLight3();

	renderer->light4T = gui->getLight4();
	renderer->xLight4 = (gui->getXLight4());
	renderer->yLight4 = (gui->getYLight4());
	renderer->zLight4 = (gui->getZLight4());
	renderer->RLight4 = gui->getRLight4();
	renderer->GLight4 = gui->getGLight4();
	renderer->BLight4 = gui->getBLight4();


	// Autres /////////////////////////////////////////////////////////////////////////////////////
	
	
	// Couleur du fond
	renderer->rfond = (gui->getFOND_R());
	renderer->gfond = (gui->getFOND_G());
	renderer->bfond = (gui->getFOND_B());

	// Initialisation de update() de la classe Renderer
	renderer->update();
}

// Appel de la fonction pour dessiner sur le rendue
void Application::draw() 
{
	// Initialisation de draw() de la classe Renderer
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
			renderer->isCameraPerspective = true;
			renderer->setupCamera();
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
