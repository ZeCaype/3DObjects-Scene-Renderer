#include "renderer.h"

// Constructeur de la classe Renderer
Renderer::Renderer()
{
	light = nullptr;
}

// Fonction invoquée pour configurer les éléments du framebuffer
void Renderer::setup()
{
	ofLog() << "<renderer::setup>";
	ofSetWindowTitle("Rendu");

	// Application d'un fond en blanc
	ofBackground(255);
	ofSetCircleResolution(200);

	// Application des effets
	ofSetFrameRate(60);
	ofEnableDepthTest();
	ofEnableLighting();

	// Paramétrisation de la lumière (enfin de voir les modèles correctement)
	ofSetSmoothLighting(true);
	light = new ofLight();

	// Paramétrisation de l'image
	posRectangleX = 0;
	posImageX = 0;
	posImageY = 0;
	sizeImageWidth = 150;
	sizeImageHeight = 150;
	hueImage = 0;
	saturationImage = 0;
	brightnessImage = 255;
	alphaImage = 255;

	circleRadius = 0;
	cameraSetupParameters();
}

void Renderer::reset()
{
	// Initialisation de la lumière
	light->setAmbientColor(ofColor(255, 255, 255));
	light->setDiffuseColor(ofColor(255, 255, 255));
	light->enable();

	// initialisation des variables
	sceneOffset = 1000 / 2.0f * -1.0f;
	cameraOffset = sceneOffset * 3.5f * -1.0f;

	// position initiale de chaque caméra
	cameraFront.setPosition(0, 0, -cameraOffset);
	cameraBack.setPosition(0, 0, cameraOffset);
	cameraLeft.setPosition(-cameraOffset, 0, 0);
	cameraRight.setPosition(cameraOffset, 0, 0);
	cameraTop.setPosition(0, cameraOffset, 0);
	cameraDown.setPosition(0, -cameraOffset, 0);

	// orientation de chaque caméra
	cameraFront.lookAt(cameraTarget);
	cameraBack.lookAt(cameraTarget);
	cameraLeft.lookAt(cameraTarget);
	cameraRight.lookAt(cameraTarget);
	cameraTop.lookAt(cameraTarget, ofVec3f(1, 0, 0));
	cameraDown.lookAt(cameraTarget, ofVec3f(1, 0, 0));

	// caméra par défault
	cameraActive = Camera::FRONT;

	ofLog() << "<reset>";
}

// Ajouter les fonctions des boutons du Gui ici
void Renderer::update()
{
	updateCamera();
}

// Fonction invoquée pour ajouter des éléments dans le framebuffer
void Renderer::draw()
{
	ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	// Afficher l'image de fond sur toute la surface de la fenêtre seulement si isFondLoaded est true
	ofSetColor(ofColor::fromHsb(hueImage, saturationImage, brightnessImage, alphaImage));
	if (isFondLoaded == true)
		fond.draw(posImageX - ofGetWindowWidth() / 2, posImageY - ofGetWindowHeight() / 2, sizeImageWidth, sizeImageHeight);

	camera->begin();
	
	// Activation de la lumière
	light->setPosition(0, 0, -1000);

	// Activation des différentes caméras
	if (isVisibleCamera)
	{
		if (cameraActive != Camera::FRONT)
			cameraFront.draw();
		if (cameraActive != Camera::BACK)
			cameraBack.draw();
		if (cameraActive != Camera::LEFT)
			cameraLeft.draw();
		if (cameraActive != Camera::RIGHT)
			cameraRight.draw();
		if (cameraActive != Camera::TOP)
			cameraTop.draw();
		if (cameraActive != Camera::DOWN)
			cameraDown.draw();
	}

	for (int i = 0; i < 2; i++) {
		ofSetColor(i * 70, 100 - i * 25, 120);
		ofDrawSphere(i * 300, 0, circleRadius);
		ofDrawSphere(i * -300, 0, circleRadius);
		ofSetColor(150, 0, 50 + i * 75);
		ofDrawSphere(i * 300, 300, circleRadius);
		ofDrawSphere(i * -300, 300, circleRadius);
	}
	
	if (createRectangle == true) 
	{
		if (posRectangleX > 0 && posRectangleY > 0)
		{
			ofSetColor(0, 255, 0); //Couleur de l'intérieur du Rectangle
			ofDrawRectangle(50 + (recStroke / 2), 50 + (recStroke / 2), posRectangleX, posRectangleY);
			ofSetColor(0, 0, 0); //Couleur de la stroke du rectangle
			ofDrawRectangle(50, 50, posRectangleX + recStroke, posRectangleY + recStroke);
		}

		else if (posRectangleX < 0 && posRectangleY < 0)
		{
			ofSetColor(0, 255, 0); //Couleur de l'intérieur du Rectangle
			ofDrawRectangle(50 - (recStroke / 2), 50 - (recStroke / 2), posRectangleX, posRectangleY);
			ofSetColor(0, 0, 0); //Couleur de la stroke du rectangle
			ofDrawRectangle(50, 50, posRectangleX - recStroke, posRectangleY - recStroke);
		}

		else if (posRectangleX > 0 && posRectangleY < 0)
		{
			ofSetColor(0, 255, 0); //Couleur de l'intérieur du Rectangle
			ofDrawRectangle(50 + (recStroke / 2), 50 - (recStroke / 2), posRectangleX, posRectangleY);
			ofSetColor(0, 0, 0); //Couleur de la stroke du rectangle
			ofDrawRectangle(50, 50, posRectangleX + recStroke, posRectangleY - recStroke);
		}

		else if (posRectangleX < 0 && posRectangleY > 0)
		{
			ofSetColor(0, 255, 0); //Couleur de l'intérieur du Rectangle
			ofDrawRectangle(50 - (recStroke / 2), 50 + (recStroke / 2), posRectangleX, posRectangleY);
			ofSetColor(0, 0, 0); //Couleur de la stroke du rectangle
			ofDrawRectangle(50, 50, posRectangleX - recStroke, posRectangleY + recStroke);
		}
	}

	if (createEllipse == true)
	{
		if (posEllipseX > 0 && posEllipseY > 0) 
		{
			ofSetColor(0, 255, 0);
			ofDrawEllipse(10, 10, posEllipseX, posEllipseY);
			ofSetColor(0, 0, 0); //Couleur de la stroke de L'ellipse
			ofDrawEllipse(10, 10, posEllipseX + ellipseStroke, posEllipseY + ellipseStroke);
		}

		else if (posEllipseX < 0 && posEllipseY < 0)
		{
			ofSetColor(0, 255, 0);
			ofDrawEllipse(10, 10, posEllipseX, posEllipseY);
			ofSetColor(0, 0, 0); //Couleur de la stroke de L'ellipse
			ofDrawEllipse(10, 10, posEllipseX - ellipseStroke, posEllipseY - ellipseStroke);
		}

		else if (posEllipseX > 0 && posEllipseY < 0)
		{
			ofSetColor(0, 255, 0);
			ofDrawEllipse(10, 10, posEllipseX, posEllipseY);
			ofSetColor(0, 0, 0); //Couleur de la stroke de L'ellipse
			ofDrawEllipse(10, 10, posEllipseX + ellipseStroke, posEllipseY - ellipseStroke);
		}

		else if (posEllipseX < 0 && posEllipseY > 0)
		{
			ofSetColor(0, 255, 0);
			ofDrawEllipse(10, 10, posEllipseX, posEllipseY);
			ofSetColor(0, 0, 0); //Couleur de la stroke de L'ellipse
			ofDrawEllipse(10, 10, posEllipseX - ellipseStroke, posEllipseY + ellipseStroke);
		}
	}

	if (createLigne == true)
	{
		ofSetColor(0, 255, 0);
		ofDrawLine(tx1, ty1, tx2, ty2);
	}
	
	if (createFormeVectorielle == true)
	{
		int x = posformeVectorielleX;
		int y = posformeVectorielleY;
		//int x =-600;
		//int y = -600;
		ofSetColor(0, 0, 0);
		ofDrawEllipse(x - 35, y, 30, 75);

		ofSetColor(0, 0, 0);
		ofDrawEllipse(x + 35, y, 30, 75);

		ofSetColor(255, 255, 255);
		ofDrawEllipse(x, y, 250, 100);


		ofSetColor(255, 204, 0);
		ofDrawEllipse(x, y, 325, 150);

		ofSetColor(255, 153, 2);
		ofDrawEllipse(x, y, 400, 200);

		ofSetColor(51, 204, 0);
		ofDrawRectangle(x + 45, y, -90, -250);

		ofDrawTriangle(x + 45, y - 250, x + 85, y - 150, x + 200, y - 130);
		ofDrawTriangle(x + 45, y - 250, x + 85 + 60, y - 230, x + 200, y - 130);

		ofDrawTriangle(x - 45, y - 250, x - 85, y - 150, x - 200, y - 130);
		ofDrawTriangle(x - 45, y - 250, x - 85 - 60, y - 230, x - 200, y - 130);
	}
	
	

	





	camera->end();
}
void Renderer::setformeVectorielXSlider(int posX)
{
	posformeVectorielleX= posX;
}
void Renderer::setformeVectorielYSlider(int posX)
{
	posformeVectorielleY = posX;
}

void Renderer::setPosXSlider(int posX)
{
	posRectangleX = posX;
}

void Renderer::setPosYSlider(int posY)
{
	posRectangleY = posY;
}

void Renderer::setTX1(int posX)
{
	tx1 = posX;
}

void Renderer::setTX2(int posX)
{
	tx2 = posX;
}

void Renderer::setTY1(int posY)
{
	ty1 = posY;
}

void Renderer::setTY2(int posY)
{
	ty2 = posY;
}

void Renderer::setposXEllipseSlider(int posX)
{
	posEllipseX = posX;
}

void Renderer::setposYEllipseSlider(int posY)
{
	posEllipseY = posY;
}

void Renderer::setToggle(ofxToggle bouton)
{
	stateToggle = bouton;
}

void Renderer::ReactionRec() 
{
	ofLog() << "<JE TOGGLE RECTANGLE>";
}

void Renderer::ReactionEll()
{
	ofLog() << "<JE TOGGLE ELLIPSE>";
}

void Renderer::ReactionLig()
{
	ofLog() << "<JE TOGGLE LIGNE>";
}


// Fonction de paramétrisation de l'image
// Update la position en X de l'image
void Renderer::setPosImageX(int posX)
{
	posImageX = posX;
}
// Update la position en Y de l'image
void Renderer::setPosImageY(int posY)
{
	posImageY = posY;
}
// Update la longueur de l'image
void Renderer::setSizeImageWidth(int sizeW)
{
	sizeImageWidth = sizeW;
}
// Update la largeur de l'image
void Renderer::setSizeImageHeight(int sizeH)
{
	sizeImageHeight = sizeH;
}
// Update Hue du HSB de l'image
void Renderer::setHueImage(int hue)
{
	hueImage = hue;
}
// Update Saturation du HSB de l'image
void Renderer::setSaturationImage(int sat)
{
	saturationImage = sat;
}
// Update Brightness du HSB de l'image
void Renderer::setBrightnessImage(int bright)
{
	brightnessImage = bright;
}
// Update Alpha de l'image
void Renderer::setAlphaImage(int alpha)
{
	alphaImage = alpha;
}


void Renderer::setRadius(int radius) 
{
	circleRadius = radius;
}

void Renderer::setFieldOfView(float fov) {
	cameraFov = fov;
}

// Fonction permettant d'activer une commande en pressant une touche
void Renderer::keyPressed(int key)
{
}

// Fonction permettant d'activer une commande en relâchant une touche
void Renderer::keyReleased(int key)
{
}

// Fonction qui exporte une image à partir de son nom et de son extension, à partir du répertoire ./bin/data ou d'un chemin absolue
void Renderer::imageExport(const string name, const string extension) const
{
	ofImage imageTemp;

	// Extraire des données temporelles formatées
	string timestamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");

	// Générer un nom de fichier unique et ordonné
	string fileName = name + timestamp + "." + extension;

	// Capturer le contenu du framebuffer actif
	imageTemp.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	// Sauvegarder le fichier image
	imageTemp.save(fileName);

	ofLog() << "<export image: " << fileName << ">";
}

void Renderer::primitiveRectangle(int x, int y)
{
	createRectangle = true;
	ofLog() << "<Test Rectangle:>";
}

void Renderer::primitiveLigne(int x, int y)
{
	createLigne = true;
	ofLog() << "<Test Ligne:>";

}

void Renderer::FormeVectorielle(int x, int y)
{
	createFormeVectorielle = true; 
	ofLog() << "FORME VECTOR";
}

void Renderer::primitiveEllispe(int x, int y)
{
	createEllipse = true;
	ofLog() << "<Test Ellipse:>";

}

void Renderer::cameraSetupParameters() {
	// paramètres
	cameraFov = 60.0f;
	cameraNear = 50.0f;
	cameraFar = 2500.0f;

	cameraTarget = { 0.0f, 0.0f, 0.0f };

	fovDelta = 16.0f;

	speedDelta = 250.0f;

	isVisibleCamera = false;

	isCameraMoveLeft = false;
	isCameraMoveRight = false;
	isCameraMoveUp = false;
	isCameraMoveDown = false;
	isCameraMoveForward = false;
	isCameraMoveBackward = false;

	isCameraTiltUp = false;
	isCameraTiltDown = false;
	isCameraPanLeft = false;
	isCameraPanRight = false;
	isCameraRollLeft = false;
	isCameraRollRight = false;

	isCameraFovNarrow = false;
	isCameraFovWide = false;

	isCameraPerspective = true;

	isFondLoaded = false;

	reset();

	setupCamera();
}

// fonction de configuration de la caméra active
void Renderer::setupCamera()
{
	switch (cameraActive)
	{
	case Camera::FRONT:
		camera = &cameraFront;
		cameraName = "front";
		break;

	case Camera::BACK:
		camera = &cameraBack;
		cameraName = "back";
		break;

	case Camera::LEFT:
		camera = &cameraLeft;
		cameraName = "left";
		break;

	case Camera::RIGHT:
		camera = &cameraRight;
		cameraName = "right";
		break;

	case Camera::TOP:
		camera = &cameraTop;
		cameraName = "top";
		break;

	case Camera::DOWN:
		camera = &cameraDown;
		cameraName = "down";
		break;

	default:
		break;
	}

	cameraPosition = camera->getPosition();

	cameraOrientation = camera->getOrientationQuat();

	if (isCameraPerspective)
	{
		camera->disableOrtho();
		camera->setupPerspective(false, cameraFov, cameraNear, cameraFar, ofVec2f(0, 0));
	}
	else
	{
		camera->enableOrtho();
	}

	camera->setPosition(cameraPosition);
	camera->setOrientation(cameraOrientation);

	ofLog() << "<setup camera: " << cameraName << ">";
}

void Renderer::updateCamera() {
	timeCurrent = ofGetElapsedTimef();
	timeElapsed = timeCurrent - timeLast;
	timeLast = timeCurrent;

	speedTranslation = speedDelta * timeElapsed;
	speedRotation = speedTranslation / 8.0f;

	if (isCameraMoveLeft)
		camera->truck(-speedTranslation);
	if (isCameraMoveRight)
		camera->truck(speedTranslation);

	if (isCameraMoveUp)
		camera->boom(speedTranslation);
	if (isCameraMoveDown)
		camera->boom(-speedTranslation);

	if (isCameraMoveForward)
		camera->dolly(-speedTranslation);
	if (isCameraMoveBackward)
		camera->dolly(speedTranslation);

	if (isCameraTiltUp)
		camera->tilt(-speedRotation);
	if (isCameraTiltDown)
		camera->tilt(speedRotation);

	if (isCameraPanLeft)
		camera->pan(speedRotation);
	if (isCameraPanRight)
		camera->pan(-speedRotation);

	if (isCameraRollLeft)
		camera->roll(-speedRotation);
	if (isCameraRollRight)
		camera->roll(speedRotation);

	if (isCameraPerspective)
	{
		camera->setFov(cameraFov);
	}
}

// Destructeur de la classe Renderer
Renderer::~Renderer()
{
	if (light != nullptr) delete light;
}