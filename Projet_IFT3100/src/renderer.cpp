#include "renderer.h"

// Constructeur de la classe Renderer
Renderer::Renderer()
{
	light = nullptr;

	light1 = nullptr;
	light2 = nullptr;
	light3 = nullptr;
	light4 = nullptr;
}

// Fonction invoquée pour configurer les éléments du framebuffer
void Renderer::setup()
{
	ofLog() << "<renderer::setup>";
	ofSetWindowTitle("Rendu");

	// Application de la résolution
	ofSetCircleResolution(200);
	cylindre.setResolution(50,10,10);
	
	// Application des effets
	ofSetFrameRate(60);
	ofEnableDepthTest();
	ofEnableLighting();

	// Paramétrisation de la lumière (enfin de voir les modèles correctement)
	ofSetSmoothLighting(true);
	light = new ofLight();
	light1 = new ofLight();
	light2 = new ofLight();
	light3 = new ofLight();
	light4 = new ofLight();

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

	//Setup nuage de points////
	intervalleNuage = 2000;
	for (int i = 0; i < 10000; i++) {
		xNuage.push_back(ofRandom(-intervalleNuage, intervalleNuage));
		yNuage.push_back(ofRandom(-intervalleNuage, intervalleNuage));
		zNuage.push_back(ofRandom(-intervalleNuage, intervalleNuage));
		sizePointNuage.push_back(ofRandom(1, 4));
	}
}

void Renderer::reset()
{
	// initialisation des variables
	cameraOffset = 2000;

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

	// Couleur de fond castée par les sliders
	ofBackground(rfond, gfond, bfond);

	// Activation de la lumière de fond
	light->disable();
	light->setAmbientColor(ofColor(127, 127, 127));
	light->setSpecularColor(ofColor(60, 60, 60));
	light->setPosition(0, 0, -1000);

	if (light1T == true) light1->enable();
	else if (!light1T == true) light1->disable();
	if (light2T == true) light2->enable();
	else if (!light2T == true) light2->disable();
	if (light3T == true) light3->enable();
	else if (!light3T == true) light3->disable();
	if (light4T == true) light4->enable();
	else if (!light4T == true) light4->disable();

	camera->begin();

	light1->setPosition(xLight1, yLight1 - 250, zLight1 - 200);
	light1->setDiffuseColor(ofColor(RLight1, GLight1, BLight1));
	light1->setSpecularColor(ofColor(255, 255, 255));
	light1->setAmbientColor(ofColor(0, 0, 0));

	light2->setPosition(xLight2, yLight2 - 250, zLight2 - 200);
	light2->setDiffuseColor(ofColor(RLight2, GLight2, BLight2));
	light2->setSpecularColor(ofColor(255, 255, 255));
	light2->setAmbientColor(ofColor(0, 0, 0));

	light3->setPosition(xLight3, yLight3, zLight3);
	light4->setPosition(xLight4, yLight4, zLight4);

	material.setAmbientColor(ofColor(0, 255, 0));

	light1->draw();
	light2->draw();

	ofFill();

//TEMPORRAIRE J'AVAIS DE LA DIFFICULTÉ A VOIR LA CAMERA
	


	
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



		
	
	
	if (createRectangle == true) 
	{
		if (posRectangleX > 0 && posRectangleY > 0)
		{
			ofSetColor(rfill, gfill, bfill); //Couleur de l'intérieur du Rectangle
			ofDrawRectangle(positionXRectangle + (contourLargeur / 2), positionYRectangle + (contourLargeur / 2), positionZRectangle, posRectangleX, posRectangleY);
			ofSetColor(rstroke, gstroke, bstroke); //Couleur de la stroke du rectangle
			ofDrawRectangle(positionXRectangle, positionYRectangle, positionZRectangle, posRectangleX + contourLargeur, posRectangleY + contourLargeur);
		}

		else if (posRectangleX < 0 && posRectangleY < 0)
		{
			ofSetColor(rfill, gfill, bfill); //Couleur de l'intérieur du Rectangle
			ofDrawRectangle(positionXRectangle - (contourLargeur / 2), positionYRectangle - (contourLargeur / 2), positionZRectangle,  posRectangleX, posRectangleY);
			ofSetColor(rstroke, gstroke, bstroke); //Couleur de la stroke du rectangle
			ofDrawRectangle(positionXRectangle, positionYRectangle, positionZRectangle,  posRectangleX - contourLargeur, posRectangleY - contourLargeur);
		}

		else if (posRectangleX > 0 && posRectangleY < 0)
		{
			ofSetColor(rfill, gfill, bfill); //Couleur de l'intérieur du Rectangle
			ofDrawRectangle(positionXRectangle + (contourLargeur / 2), positionYRectangle - (contourLargeur / 2), positionZRectangle, posRectangleX, posRectangleY);
			ofSetColor(rstroke, gstroke, bstroke); //Couleur de la stroke du rectangle
			ofDrawRectangle(positionXRectangle, positionYRectangle, positionZRectangle, posRectangleX + contourLargeur, posRectangleY - contourLargeur);
		}

		else if (posRectangleX < 0 && posRectangleY > 0)
		{
			ofSetColor(rfill, gfill, bfill); //Couleur de l'intérieur du Rectangle
			ofDrawRectangle(positionXRectangle - (contourLargeur / 2), positionYRectangle + (contourLargeur / 2), positionZRectangle, posRectangleX, posRectangleY);
			ofSetColor(rstroke, gstroke, bstroke); //Couleur de la stroke du rectangle
			ofDrawRectangle(positionXRectangle, positionYRectangle, positionZRectangle, posRectangleX - contourLargeur, posRectangleY + contourLargeur);
		}
	}

	if (createEllipse == true)
	{
		if (posEllipseX > 0 && posEllipseY > 0) 
		{
			ofSetColor(rfill, gfill, bfill);
			ofDrawEllipse(positionXEllipse, positionYEllipse,positionZEllipse, posEllipseX, posEllipseY);
			ofSetColor(rstroke, gstroke, bstroke); //Couleur de la stroke de L'ellipse
			ofDrawEllipse(positionXEllipse, positionYEllipse, positionZEllipse, posEllipseX + contourLargeur, posEllipseY + contourLargeur);
		}

		else if (posEllipseX < 0 && posEllipseY < 0)
		{
			ofSetColor(rfill, gfill, bfill);
			ofDrawEllipse(positionXEllipse, positionYEllipse, positionZEllipse, posEllipseX, posEllipseY);
			ofSetColor(rstroke, gstroke, bstroke); //Couleur de la stroke de L'ellipse
			ofDrawEllipse(positionXEllipse, positionYEllipse, positionZEllipse, posEllipseX - contourLargeur, posEllipseY - contourLargeur);
		}

		else if (posEllipseX > 0 && posEllipseY < 0)
		{
			ofSetColor(rfill, gfill, bfill);
			ofDrawEllipse(positionXEllipse, positionYEllipse, positionZEllipse, posEllipseX, posEllipseY);
			ofSetColor(rstroke, gstroke, bstroke); //Couleur de la stroke de L'ellipse
			ofDrawEllipse(positionXEllipse, positionYEllipse, positionZEllipse, posEllipseX + contourLargeur, posEllipseY - contourLargeur);
		}

		else if (posEllipseX < 0 && posEllipseY > 0)
		{
			ofSetColor(rfill, gfill, bfill);
			ofDrawEllipse(positionXEllipse, positionYEllipse, positionZEllipse, posEllipseX, posEllipseY);
			ofSetColor(rstroke, gstroke, bstroke); //Couleur de la stroke de L'ellipse
			ofDrawEllipse(positionXEllipse, positionYEllipse, positionZEllipse, posEllipseX - contourLargeur, posEllipseY + contourLargeur);
		}
	}

	if (createLigne == true)
	{
		ofSetLineWidth(lineWidth);
		ofSetColor(rstroke, gstroke, bstroke);
		ofDrawLine(tx1, ty1, tz1, tx2, ty2, tz2);
		ofSetLineWidth(1);
	}
	
	ofPushMatrix();
	ofRotate(rotAngle, rotX, rotY, rotZ);
	if (createFormeVectorielle == true)
	{
		int x = posformeVectorielleX;
		int y = posformeVectorielleY;
		int z = posformeVectorielleZ;
		ofSetColor(0, 0, 0);
		ofDrawEllipse(x - 35, y, z, 30, 75);

		ofSetColor(0, 0, 0);
		ofDrawEllipse(x + 35, y, z, 30, 75);

		ofSetColor(255, 255, 255);
		ofDrawEllipse(x, y, z, 250, 100);

		ofSetColor(255, 204, 0);
		ofDrawEllipse(x, y, z, 325, 150);

		ofSetColor(255, 153, 2);
		ofDrawEllipse(x, y, z, 400, 200);

		ofSetColor(51, 204, 0);
		ofDrawRectangle(x + 45, y, z, -90, -250);

		ofDrawTriangle(x + 45, y - 250, z, x + 85, y - 150, z, x + 200, y - 130, z);
		ofDrawTriangle(x + 45, y - 250, z, x + 85 + 60, y - 230, z, x + 200, y - 130, z);

		ofDrawTriangle(x - 45, y - 250, z, x - 85, y - 150, z, x - 200, y - 130, z);
		ofDrawTriangle(x - 45, y - 250, z, x - 85 - 60, y - 230, z, x - 200, y - 130, z);


	}

	

	ofPopMatrix();

	if (primitive3dSphere == true)
	{


		if (primitive3dSphereRotation == true)
		{
			float spinX = sin(ofGetElapsedTimef()*.35f);
			float spinY = cos(ofGetElapsedTimef()*.075f);
			sphere.rotate(spinX, 1.0, 0.0, 0.0);
			sphere.rotate(spinY, 0, 1.0, 0.0);
		}



		sphere.setScale(primitive3dSphereSize);
		sphere.setPosition(positionPrimitive3dXSphere,positionPrimitive3dYSphere, positionPrimitive3dZSphere);
		ofSetColor(215, 135, 0);
		sphere.drawWireframe();




	}

	if (createPrimitive3d == true)
	{

		if (primitive3dRoatation == true) {
			float spinX = sin(ofGetElapsedTimef()*.35f);
			float spinY = cos(ofGetElapsedTimef()*.075f);
			cylindre.rotate(spinX, 1.0, 0.0, 0.0);
			cylindre.rotate(spinY, 0, 1.0, 0.0);

			if (primitice3dStroke == true) {
				bottomCap = cylindre.getBottomCapMesh();
				topCap = cylindre.getTopCapMesh();
				body = cylindre.getCylinderMesh();
				ofSetColor(0, 170, 0);
				cylindre.drawWireframe();
			}

		}

		else if (primitice3dStroke == true) {
			bottomCap = cylindre.getBottomCapMesh();
			topCap = cylindre.getTopCapMesh();
			body = cylindre.getCylinderMesh();
			ofSetColor(0, 170, 0);
			cylindre.drawWireframe();
			if (primitive3dRoatation == true) {
				float spinX = sin(ofGetElapsedTimef()*.35f);
				float spinY = cos(ofGetElapsedTimef()*.075f);
				cylindre.rotate(spinX, 1.0, 0.0, 0.0);
				cylindre.rotate(spinY, 0, 1.0, 0.0);
			}
		}
		cylindre.setScale(primitive3dSize);
		ofSetColor(0, 0, 170);
		cylindre.setPosition(positionPrimitive3dX, positionPrimitive3dY, positionPrimitive3dZ);
		cylindre.draw();

	}



	if (createPrimitive3dBox == true) {


		if (primitive3dRoatationBox == true) {

			float spinX = sin(ofGetElapsedTimef()*.35f);
			float spinY = cos(ofGetElapsedTimef()*.075f);
			box.rotate(spinX, 1.0, 0.0, 0.0);
			box.rotate(spinY, 0, 1.0, 0.0);
			if (primitice3dStrokeBox == true) {
				ofSetColor(0, 0, 170);
				box.drawWireframe();
			}



		}

		else if (primitice3dStrokeBox == true) {
			ofSetColor(0, 0, 170);
			box.drawWireframe();

			if (primitive3dRoatationBox == true) {

				float spinX = sin(ofGetElapsedTimef()*.35f);
				float spinY = cos(ofGetElapsedTimef()*.075f);
				box.rotate(spinX, 1.0, 0.0, 0.0);
				box.rotate(spinY, 0, 1.0, 0.0);
			}
		}


		box.setScale(primitive3dSizeBox);
		box.setPosition(positionPrimitive3dXBox, positionPrimitive3dYBox, positionPrimitive3dZBox);
		ofSetColor(0, 170, 0);
		box.draw();





	}


	if (primitive3dSphereCouleur == true) {

		if (primitive3dSphereRotationCouleur == true)
		{
			float spinX = sin(ofGetElapsedTimef()*.35f);
			float spinY = cos(ofGetElapsedTimef()*.075f);
			sphereCouleur.rotate(spinX, 1.0, 0.0, 0.0);
			sphereCouleur.rotate(spinY, 0, 1.0, 0.0);
		}

		for (int i = 0; i < nbrCercleCouleur; i++) {
			sphereCouleur.setScale(circleRadius);
			ofSetColor(i * 70, 100 - i * 25, 120);
			
			sphereCouleur.setPosition(positionPrimitive3dXSphereCouleur + (i * 300), positionPrimitive3dYSphereCouleur , positionPrimitive3dZSphereCouleur);
			sphereCouleur.draw();
			sphereCouleur.setPosition(positionPrimitive3dXSphereCouleur + (i * -300), positionPrimitive3dYSphereCouleur, positionPrimitive3dZSphereCouleur);
			sphereCouleur.draw();

			ofSetColor(150, 0, 50 + i * 75);
			sphereCouleur.setPosition(positionPrimitive3dXSphereCouleur + (i * 300), positionPrimitive3dYSphereCouleur +300, positionPrimitive3dZSphereCouleur);
			sphereCouleur.draw();
			sphereCouleur.setPosition(positionPrimitive3dXSphereCouleur + (i * -300), positionPrimitive3dYSphereCouleur +300, positionPrimitive3dZSphereCouleur);
			sphereCouleur.draw();


		}

	}

	material.begin();
	// Importation d'un modèle 3D
	if (isModelLoaded == true)
	{
		model.drawFaces();
	}
	material.end();

	// Nuage de points
	if (nuageDePoint == true) {
		for (int i = 0; i < xNuage.size(); i++) {
			ofDrawSphere(xNuage[i], yNuage[i], zNuage[i], sizePointNuage[i]);
		}
	}

	camera->end();


	// Afficher l'image de fond sur toute la surface de la fenêtre seulement si isFondLoaded est true
	if (isFondLoaded == true)
	{
		ofSetColor(ofColor::fromHsb(hueImage, saturationImage, brightnessImage, alphaImage));
		vecteurImage[vecteurImage.size() - 1].draw(posImageX - ofGetWindowWidth() / 2, posImageY - ofGetWindowHeight() / 2, sizeImageWidth, sizeImageHeight);
	}
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
	aspectRatio4_3 = true;

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

	if (aspectRatio4_3) {
		camera->setAspectRatio(1.333333333333333);
	}
	else {
		camera->setAspectRatio(1.777777777777777);
	}
	camera->setNearClip(cameraNear);
	camera->setFarClip(cameraFar);
}

// Destructeur de la classe Renderer
Renderer::~Renderer()
{
	if (light != nullptr) delete light;

	if (light1 != nullptr) delete light1;
	if (light2 != nullptr) delete light2;
	if (light3 != nullptr) delete light3;
	if (light4 != nullptr) delete light4;
}