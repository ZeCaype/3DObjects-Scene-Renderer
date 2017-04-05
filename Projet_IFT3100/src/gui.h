#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:
	// Image //////////////////////////////////////////////////////////////////////////////////////
	// Initialisation des paramètres par défaut de l'image
	int defaultPosX;
	int defaultPosY;
	int defaultSizeImageWidth;
	int defaultSizeImageHeight;
	int defaultHueImage;
	int defaultSaturationImage;
	int defaultBrightnessImage;
	int defaultAlphaImage;

	// Initialisation des sliders des paramètres de l'image
	ofxPanel guiImage;
	ofxButton exportButton; bool exportCheck;
	ofxButton importButton; bool importCheck;
	ofxIntSlider posImageX;
	ofxIntSlider posImageY;
	ofxIntSlider sizeImageWidth;
	ofxIntSlider sizeImageHeight;
	ofxIntSlider hueImage;
	ofxIntSlider saturationImage;
	ofxIntSlider brightnessImage;
	ofxIntSlider alphaImage;

	int getPosImageX();
	int getPosImageY();
	int getSizeImageWidth();
	int getSizeImageHeight();
	int getHueImage();
	int getSaturationImage();
	int getBrightnessImage();
	int getAlphaImage();

	// Dessin vectoriel ///////////////////////////////////////////////////////////////////////////
	//Primitive 2d
	//Éléments pour les primitives vectorielles
	ofxPanel guiPrimitive;
	ofxFloatSlider posXSlider;
	ofxFloatSlider posYSlider;
	ofxFloatSlider tx1;
	ofxFloatSlider tx2;
	ofxFloatSlider ty1;
	ofxFloatSlider ty2;
	ofxFloatSlider tz1;
	ofxFloatSlider tz2;
	ofxIntSlider lineWidth;
	ofxFloatSlider posXEllipseSlider;
	ofxFloatSlider posYEllipseSlider;

	ofxFloatSlider positionYEllipseSlider;
	ofxFloatSlider positionXEllipseSlider;
	ofxFloatSlider positionZEllipseSlider;

	ofxFloatSlider positionXRectangleSlider;
	ofxFloatSlider positionYRectangleSlider;
	ofxFloatSlider positionZRectangleSlider;

	ofxPanel guiColorPrimitives;
	ofxIntSlider sliderRStroke;
	ofxIntSlider sliderGStroke;
	ofxIntSlider sliderBStroke;
	ofxIntSlider sliderRFill;
	ofxIntSlider sliderGFill;
	ofxIntSlider sliderBFill;

	ofxIntSlider sliderFONDR;
	ofxIntSlider sliderFONDG;
	ofxIntSlider sliderFONDB;

	ofxIntSlider sliderContour;

	float getPositionXRectangleSlider();
	float getPositionYRectangleSlider();
	float getPositionZRectangleSlider();

	float getPositionXEllipseSlider();
	float getPositionYEllipseSlider();
	float getPositionZEllipseSlider();

	bool getToggleRectangle();
	bool getToggleEllipse();
	bool getToggleLigne();
	bool getToggleFormeVectorielle();

	float getTX1();
	float getTX2();
	float getTY1();
	float getTY2();
	float getTZ1();
	float getTZ2();
	int getLineWidth();

	int getCSRS();
	int getCSGS();
	int getCSBS();
	int getCSRF();
	int getCSGF();
	int getCSBF();

	int getFOND_R();
	int getFOND_G();
	int getFOND_B();

	int getContour();

	float getposXEllipseSlider();
	float getposYEllipseSlider();

	float getPosXSlider();
	float getPosYSlider();

	// Transformation /////////////////////////////////////////////////////////////////////////////
	// Forme vectorielle
	ofxFloatSlider formeVectorielleRSlider;
	ofxFloatSlider formeVectorielleTSlider;
	ofxFloatSlider formeVectoriellePSlider;
	// Rotation
	ofxFloatSlider rotAngleSlider;
	ofxIntSlider rotXSlider;
	ofxIntSlider rotYSlider;
	ofxIntSlider rotZSlider;

	float getformeVectorielleRSlider();
	float getformeVectorielleTSlider();
	float getformeVectoriellePSlider();

	float getRotAngle();
	int getRotX();
	int getRotY();
	int getRotZ();

	// Géométrie //////////////////////////////////////////////////////////////////////////////////
	// Initialisation des paramètres du cercle
	int defaultCircleRadius;

	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	int getRadius();

	//Primitive 3D
	ofxPanel guiPrimitive3d;
	ofxToggle primitive3dToggle;
	ofxToggle primitive3dStroke;
	ofxToggle primitive3dRotation;
	ofxFloatSlider positionPrimitive3dX;
	ofxFloatSlider positionPrimitive3dY;
	ofxFloatSlider positionPrimitive3dZ;
	ofxFloatSlider Primitive3dSize;

	ofxToggle primitive3dToggleBox;
	ofxToggle primitive3dStrokeBox;
	ofxToggle primitive3dRotationBox;
	ofxFloatSlider positionPrimitive3dXBox;
	ofxFloatSlider positionPrimitive3dYBox;
	ofxFloatSlider positionPrimitive3dZBox;
	ofxFloatSlider Primitive3dSizeBox;

	ofxToggle nuageDePoint;

	float getpositionPrimitive3dX();
	float getpositionPrimitive3dY();
	float getpositionPrimitive3dZ();
	float getprimitive3dSize();
	bool getToggleprimitive3d();
	bool getToggleprimitive3dStroke();
	bool getToggleprimitive3dRotation();

	float getpositionPrimitive3dXBox();
	float getpositionPrimitive3dYBox();
	float getpositionPrimitive3dZBox();
	float getprimitive3dSizeBox();
	bool getToggleprimitive3dBox();
	bool getToggleprimitive3dStrokeBox();
	bool getToggleprimitive3dRotationBox();

	bool getNuageDePoint();

	// Scène 3D
	ofxPanel guiScene;
	ofxButton modelButton; bool modelCheck;
	ofxToggle primitive3dSphere; 

	ofxToggle primitive3dRotationSphere;
	ofxFloatSlider positionPrimitive3dXSphere;
	ofxFloatSlider positionPrimitive3dYSphere;
	ofxFloatSlider positionPrimitive3dZSphere;
	ofxFloatSlider Primitive3dSizeSphere;
	
	bool getprimitive3dSphere(); 
	float getpositionPrimitive3dXSphere();
	float getpositionPrimitive3dYSphere();
	float getpositionPrimitive3dZSphere();
	float getprimitive3dSizeSphere();
	bool getToggleprimitive3dRotationSphere();



	ofxToggle primitive3dSphereCouleur;
	ofxToggle primitive3dStrokeSphereCouleur;
	ofxToggle primitive3dRotationSphereCouleur;
	ofxFloatSlider positionPrimitive3dXSphereCouleur;
	ofxFloatSlider positionPrimitive3dYSphereCouleur;
	ofxFloatSlider positionPrimitive3dZSphereCouleur;
	ofxFloatSlider primitive3dNombreSphereCouleur; 

	bool getprimitive3dSphereCouleur();
	float getpositionPrimitive3dXSphereCouleur();
	float getpositionPrimitive3dYSphereCouleur();
	float getpositionPrimitive3dZSphereCouleur();
	float getprimitive3dNombreSphereCouleur(); 
	bool getToggleprimitive3dStrokeSphereCouleur();
	bool getToggleprimitive3dRotationSphereCouleur();

	// Caméra /////////////////////////////////////////////////////////////////////////////////////
	float defaultFov;
	int defaultCameraNear;
	int defaultCameraFar;

	// Initialisation des paramètres de la caméra
	ofxPanel guiCamera;
	ofxFloatSlider fovSlider;
	ofxIntSlider cameraNearSlider;
	ofxIntSlider cameraFarSlider;
	ofxToggle aspectRatio4_3;

	float getFov();
	int getCameraNear();
	int getCameraFar();
	bool getAspectRatio();

	// Lumière /////////////////////////////////////////////////////////////////////////////////////
	ofxPanel guiLightPart1;
	ofxToggle light1Toggle;
	ofxIntSlider xLight1Slider;
	ofxIntSlider yLight1Slider;
	ofxIntSlider zLight1Slider;
	ofxIntSlider RLight1Slider;
	ofxIntSlider GLight1Slider;
	ofxIntSlider BLight1Slider;
	ofxToggle light2Toggle;
	ofxIntSlider xLight2Slider;
	ofxIntSlider yLight2Slider;
	ofxIntSlider zLight2Slider;
	ofxIntSlider RLight2Slider;
	ofxIntSlider GLight2Slider;
	ofxIntSlider BLight2Slider;
	ofxFloatSlider cut2Slider;
	ofxFloatSlider conc2Slider;
	ofxFloatSlider vectXLight2Slider;
	ofxFloatSlider vectYLight2Slider;
	ofxFloatSlider vectZLight2Slider;

	ofxPanel guiLightPart2;
	ofxToggle light3Toggle;
	ofxIntSlider RLight3Slider;
	ofxIntSlider GLight3Slider;
	ofxIntSlider BLight3Slider;
	ofxFloatSlider xLight3Slider;
	ofxFloatSlider yLight3Slider;
	ofxFloatSlider zLight3Slider;
	ofxToggle light4Toggle;
	ofxIntSlider xLight4Slider;
	ofxIntSlider yLight4Slider;
	ofxIntSlider zLight4Slider;
	ofxIntSlider RLight4Slider;
	ofxIntSlider GLight4Slider;
	ofxIntSlider BLight4Slider;

	bool getLight1();
	int getXLight1();
	int getYLight1();
	int getZLight1();
	int getRLight1();
	int getGLight1();
	int getBLight1();

	bool getLight2();
	int getXLight2();
	int getYLight2();
	int getZLight2();
	int getRLight2();
	int getGLight2();
	int getBLight2();
	float getCutLight2();
	float getConcLight2();

	bool getLight3();
	float getXLight3();
	float getYLight3();
	float getZLight3();
	int getRLight3();
	int getGLight3();
	int getBLight3();

	bool getLight4();
	int getXLight4();
	int getYLight4();
	int getZLight4();
	int getRLight4();
	int getGLight4();
	int getBLight4();

	// Autres /////////////////////////////////////////////////////////////////////////////////////
	int offsetX;

	// Éléments Autres
	ofxPanel guiOptions;
	ofxToggle rec;
	ofxToggle ell;
	ofxToggle lig;
	ofxToggle formeVec;
	// Initialisation des fonctions de l'application
	ofxPanel guiOption;
	ofxButton exitButton;

	float posX;
	float posY;

	//---------------------------------------------------------------------------------------------
	
	Gui();

	void setup();
	void reset();
	void update();
	void draw();

	~Gui();
};