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

	// Scène 3D
	ofxPanel guiScene;
	ofxButton modelButton; bool modelCheck;
	ofxToggle primitive3dSphere; 
	bool getprimitive3dSphere(); 

	


	

	// Caméra /////////////////////////////////////////////////////////////////////////////////////
	float defaultFov;
	int defaultCameraNear;
	int defaultCameraFar;

	// Initialisation des paramètres de la caméra
	ofxPanel guiCamera;
	ofxFloatSlider fovSlider;
	ofxIntSlider cameraNearSlider;
	ofxIntSlider cameraFarSlider;

	float getFov();
	int getCameraNear();
	int getCameraFar();

	// Autres /////////////////////////////////////////////////////////////////////////////////////
	int offsetX;
	// Lumière
	ofxPanel guiLight;
	ofxIntSlider xLightSlider;
	ofxIntSlider yLightSlider;
	ofxIntSlider zLightSlider;
	int getXLight();
	int getYLight();
	int getZLight();
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