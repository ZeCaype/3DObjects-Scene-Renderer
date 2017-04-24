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
	ofEnableAlphaBlending();

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
	lineResolution = 100;

	radius = 32.0f;
	scale = 10.0f;
	offset = 64.0f;

	lineWidthOutline = 4.0f;
	lineWidthCurve = 8.0f;

	motionSpeed = 250.0f;
	for (index = 0; index <= lineResolution; ++index)
		lineRenderer.addVertex(ofPoint());
		//panelRenderer.addVertex(ofPoint());
	

	// courbe au lancement de l'application
	curveID = Curve::BEZIER_CUBIC;
	ctrlPoint1 = initialPosition1;
	ctrlPoint2 = initialPosition2;
	ctrlPoint3 = initialPosition4;
	ctrlPoint4 = initialPosition5;

	//technique de rendu
	//setup rain
	intervalleRain = 3500;
	rainNumber = 2000;
	for (int i = 0; i < rainNumber; i++) {
		rainX.push_back(ofRandom(-intervalleRain, intervalleRain));
		rainY.push_back(ofRandom(1000, intervalleRain));
		rainZ.push_back(ofRandom(500, -500));
		rainSpeed.push_back(ofRandom(-20, -30));
		rainSize.push_back(ofRandom(15, 25));
		rainColorR.push_back(ofRandom(0, 255));
		rainColorG.push_back(ofRandom(0, 255));
		rainColorB.push_back(ofRandom(0, 255));

	};

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
	framebufferWidth = ofGetWidth();
	framebufferHeight = ofGetHeight();

	//Topologie/////////////////////////////////////////////////////////////////////////////
	// ratios de positionnement dans la fenêtre
	float w_1_8 = framebufferWidth / 8.0f;
	float w_1_4 = framebufferWidth / 4.0f;
	float w_1_2 = framebufferWidth / 2.0f;
	float w_3_4 = framebufferWidth * 3.0f / 4.0f;
	float w_7_8 = framebufferWidth * 7.0f / 8.0f;
	float h_1_5 = framebufferHeight / 5.0f;
	float h_1_3 = framebufferHeight / 3.0f;
	float h_4_5 = framebufferHeight * 4.0f / 5.0f;

	initialPosition1 = { w_1_8, h_4_5, 0 };
	initialPosition2 = { w_1_4, h_1_3, 0 };
	initialPosition3 = { w_1_2, h_1_5, 0 };
	initialPosition4 = { w_3_4, h_1_3, 0 };
	initialPosition5 = { w_7_8, h_4_5, 0 };

	// paramètres selon le type de courbe
	switch (curveID)
	{
	

	case Curve::BEZIER_CUBIC:

		curveName = "Bézier cubique";

		ctrlPoint1 = initialPosition1;
		ctrlPoint2 = initialPosition2;
		ctrlPoint3 = initialPosition4;
		ctrlPoint4 = initialPosition5;

		selectedCtrlPoint = &ctrlPoint2;

		break;

	default:
		break;
	}
	xDelta = motionSpeed;
	yDelta = motionSpeed;
	ofLog() << "<reset>";
}

// Ajouter les fonctions des boutons du Gui ici
void Renderer::update()
{
	updateCamera();


	//Topologie/////////////////////////////////////////////////////////////////////////////


	for (index = 0; index <= lineResolution; ++index)
	{
		// paramètres selon le type de courbe
		switch (curveID)
		{
		

		case Curve::BEZIER_CUBIC:
			bezierCubic(
				index / (float)lineResolution,
				ctrlPoint1.x, ctrlPoint1.y, ctrlPoint1.z,
				ctrlPoint2.x, ctrlPoint2.y, ctrlPoint2.z,
				ctrlPoint3.x, ctrlPoint3.y, ctrlPoint3.z,
				ctrlPoint4.x, ctrlPoint4.y, ctrlPoint4.z,
				position.x, position.y, position.z);
			break;

		default:
			break;
		}
		// affecter la position du point sur la courbe
		lineRenderer[index] = position;
		 
	}
}

// Fonction invoquée pour ajouter des éléments dans le framebuffer
void Renderer::draw()
{
	ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	// Couleur de fond castée par les sliders
	ofBackground(rfond, gfond, bfond);

	// Activation de la lumière de fond
	light->disable(); // Semble être une lumière inutile




	// Lumières //////////////////////////////////////////////////////////////////////////

	if (light1T == true) { light1->enable(); light->enable(); }
	else if (!light1T == true) { light1->disable(); light->disable(); }
	light->setPosition(0, 3000, 0);
	light->setAmbientColor(ofColor(RLight1, GLight1, BLight1));
	light->setSpecularColor(ofColor(RLight1 / 2, GLight1 / 2, BLight1 / 2));
	light->setDiffuseColor(ofColor(RLight1, GLight1, BLight1));
	light->setAttenuation(attLight1);
	light1->setPosition(0, -3000, 0);
	light1->setDiffuseColor(ofColor(RLight1, GLight1, BLight1));
	light1->setSpecularColor(ofColor(RLight1 / 2, GLight1 / 2, BLight1 / 2));
	light1->setAmbientColor(ofColor(RLight1, GLight1, BLight1));
	light1->setAttenuation(attLight1);

	if (light2T == true) light2->enable();
	else if (!light2T == true) light2->disable();
	light2->setPosition(xLight2, yLight2 - 250, zLight2 - 200);
	light2->setDiffuseColor(ofColor(RLight2, GLight2, BLight2));
	light2->setSpecularColor(ofColor(255, 255, 255));
	light2->setAmbientColor(ofColor(0, 0, 0));
	light2->setSpotlightCutOff(cutLight2);
	light2->setSpotConcentration(concLight2);
	light2->setAttenuation(attLight2);

	if (light3T == true) light3->enable();
	else if (!light3T == true) light3->disable();
	light3->setPosition(0, 0 - 250, 0 - 200);
	light3Ori = ofVec3f(xLight3, yLight3, zLight3);
	setLightOri(*light3, light3Ori);
	light3->setDiffuseColor(ofColor(RLight3, GLight3, BLight3));
	light3->setSpecularColor(ofColor(255, 255, 255));
	light3->setAmbientColor(ofColor(0, 0, 0));
	light3->setDirectional();
	light3->setAttenuation(attLight3);

	if (light4T == true) light4->enable();
	else if (!light4T == true) light4->disable();
	light4->setPosition(xLight4, yLight4 - 250, zLight4 - 200);
	light4->setDiffuseColor(ofColor(RLight4, GLight4, BLight4));
	light4->setSpecularColor(ofColor(255, 255, 255));
	light4->setAmbientColor(ofColor(0, 0, 0));
	light4->setPointLight();
	light4->setAttenuation(attLight4);
	
	if (toggleMat) {
		material.setShininess(shinyMat);
		material.setEmissiveColor(ofColor::fromHsb(hueEmiMat, satEmiMat, 255, 255));
		material.setSpecularColor(ofColor::fromHsb(hueSpeMat, satSpeMat, 255, 255));
		material.setDiffuseColor(ofColor::fromHsb(hueDifMat, satDifMat, 255, 255));
		material.setAmbientColor(ofColor::fromHsb(hueAmbMat, satAmbMat, 255, 255));
	}

	camera->begin();

	//if (light1T) light1->draw();
	if (light2T) light2->draw();
	//if (light3T) light3->draw();
	if (light4T) light4->draw();

	
	//Topologie/////////////////////////////////////////////////////////////////////////////
	
	if (courbeBezier == true) {
		// dessiner les positions initiales
		ofSetColor(63, 63, 63);

		ofDrawEllipse(initialPosition1.x, initialPosition1.y, radius / 2, radius / 2);
		ofDrawEllipse(initialPosition2.x, initialPosition2.y, radius / 2, radius / 2);
		ofDrawEllipse(initialPosition3.x, initialPosition3.y, radius / 2, radius / 2);
		ofDrawEllipse(initialPosition4.x, initialPosition4.y, radius / 2, radius / 2);
		ofDrawEllipse(initialPosition5.x, initialPosition5.y, radius / 2, radius / 2);

		// dessiner la ligne contour
		ofSetColor(0, 0, 255);
		ofSetLineWidth(lineWidthOutline);

		ofDrawLine(ctrlPoint1.x, ctrlPoint1.y, ctrlPoint2.x, ctrlPoint2.y);
		ofDrawLine(ctrlPoint2.x, ctrlPoint2.y, ctrlPoint3.x, ctrlPoint3.y);
		ofDrawLine(ctrlPoint3.x, ctrlPoint3.y, ctrlPoint4.x, ctrlPoint4.y);
		ofDrawLine(ctrlPoint4.x, ctrlPoint4.y, ctrlPoint1.x, ctrlPoint1.y);

		// dessiner la courbe
		ofSetColor(0, 255, 0);
		ofSetLineWidth(lineWidthCurve);

		lineRenderer.draw();

		// dessiner les points de contrôle
		ofSetColor(255, 0, 0);

		ofDrawEllipse(ctrlPoint1.x, ctrlPoint1.y, radius, radius);
		ofDrawEllipse(ctrlPoint2.x, ctrlPoint2.y, radius, radius);
		ofDrawEllipse(ctrlPoint3.x, ctrlPoint3.y, radius, radius);
		ofDrawEllipse(ctrlPoint4.x, ctrlPoint4.y, radius, radius);
		
		}
	ofFill();

//TEMPORAIRE J'AVAIS DE LA DIFFICULTÉ A VOIR LA CAMERA
	


	
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

	if (toggleMat) material.begin();
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
	if (toggleMat) material.end();

	// Importation d'un modèle 3D
	if (isModelLoaded == true)
	{
		model.drawFaces();
	}

	// Nuage de points
	if (nuageDePoint == true) {
		for (int i = 0; i < xNuage.size(); i++) {
			ofDrawSphere(xNuage[i], yNuage[i], zNuage[i], sizePointNuage[i]);
		}
	}

	//Techniques de rendu
	//Blur
	if (antialiasingEffect == true) {
		ofEnableAntiAliasing();
		ofEnableSmoothing();
	}
	else {
		ofDisableAntiAliasing();
		ofDisableSmoothing();
	}

	//Rain
	if (rainEffect == true) {
		makeItRain();
		showTheRain();
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

void Renderer::setLightOri(ofLight &light, ofVec3f rot)
{
	ofVec3f xax(1, 0, 0);
	ofVec3f yax(0, 1, 0);
	ofVec3f zax(0, 0, 1);
	ofQuaternion q;
	q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
	light.setOrientation(q);
}

void Renderer::makeItRain() {

	
	for (int i = 0; i < rainNumber; i++) {
		ofSetColor(rainColorR[i], rainColorG[i], rainColorB[i]);
		ofDrawLine(rainX[i], rainY[i], rainZ[i], rainX[i], rainY[i] + rainSize[i], rainZ[i]);
	}


}

void Renderer::showTheRain() {
	for (int i = 0; i < rainNumber; i++) {
		rainY[i] = rainY[i] + rainSpeed[i];
		rainSpeed[i] = rainSpeed[i] + 0,3 * rainSpeed[i];
		if (rainY[i] < -1500) {
			rainY[i] = ofRandom(1000, intervalleRain);
			rainSpeed[i] = ofRandom(-20, -30);
		}
	}

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