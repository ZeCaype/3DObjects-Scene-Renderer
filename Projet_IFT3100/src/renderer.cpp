#include "renderer.h"

// Constructeur de la classe Renderer
Renderer::Renderer()
{
}

// Fonction invoquée pour configurer les éléments du framebuffer
void Renderer::setup()
{
	ofLog() << "<renderer::setup>";
	ofSetWindowTitle("Rendue");

	// Application d'un fond en blanc
	ofBackground(255);
	ofSetCircleResolution(200);

	ofSetFrameRate(60);
	ofEnableDepthTest();

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
	//ofSetColor(255, 255, 255, 255)
	ofSetColor(ofColor::fromHsb(hueImage, saturationImage, brightnessImage, alphaImage));
	if (isFondLoaded == true)
		fond.draw(posImageX - ofGetWindowWidth() / 2, posImageY - ofGetWindowHeight() / 2, sizeImageWidth, sizeImageHeight);

	camera->begin();

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

	for (int i = 0; i < 3; i++) {
		ofSetColor(i * 70, 100 - i * 25, 120);
		ofDrawSphere(i * 300, 0, circleRadius);
		ofDrawSphere(i * -300, 0, circleRadius);
		ofSetColor(150, 0, 50 + i * 75);
		ofDrawSphere(i * 300, 300, circleRadius);
		ofDrawSphere(i * -300, 300, circleRadius);
	}

	if (createRectangle == true) 
	{
		ofSetColor(0, 255, 0);
		ofDrawRectangle(posRectangleX,50, 100, 100);
	}

	camera->end();
}
void Renderer::setPosXSlider(int posX)
{
	posRectangleX = posX;
}

void Renderer::setPosImageX(int posX)
{
	posImageX = posX;
}

void Renderer::setPosImageY(int posY)
{
	posImageY = posY;
}

void Renderer::setSizeImageWidth(int sizeW)
{
	sizeImageWidth = sizeW;
}

void Renderer::setSizeImageHeight(int sizeH)
{
	sizeImageHeight = sizeH;
}

void Renderer::setHueImage(int hue)
{
	hueImage = hue;
}

void Renderer::setSaturationImage(int sat)
{
	saturationImage = sat;
}

void Renderer::setBrightnessImage(int bright)
{
	brightnessImage = bright;
}

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

// Destructeur de la classe Renderer
Renderer::~Renderer()
{
}

void Renderer::cameraSetupParameters() {
	// paramètres
	cameraFov = 60.0f;
	cameraNear = 50.0f;
	cameraFar = 1750.0f;

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

