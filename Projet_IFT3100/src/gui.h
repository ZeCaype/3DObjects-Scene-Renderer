#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:
	int offsetX;

	// Initialisation des param�tres par d�faut de l'image
	int defaultPosX;
	int defaultPosY;
	int defaultSizeImageWidth;
	int defaultSizeImageHeight;
	int defaultHueImage;
	int defaultSaturationImage;
	int defaultBrightnessImage;
	int defaultAlphaImage;

	int defaultCircleRadius;
	float defaultFov;
	int defaultCameraNear;
	int defaultCameraFar;

	Gui();

	void setup();
	void reset();
	void update();
	void draw();


	float posX;
	float posY;

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
	
	//forme vectorielle 
	float getformeVectorielleXSlider(); 
	float getformeVectorielleYSlider(); 
	float getformeVectorielleZSlider();


	//Primitive 2d
	float getPositionXRectangleSlider();
	float getPositionYRectangleSlider(); 
	float getPositionZRectangleSlider();

	float getPositionXEllipseSlider(); 
	float getPositionYEllipseSlider(); 
	float getPositionZEllipseSlider();

	
	
	ofxToggle getToggleRectangle();
	ofxToggle getToggleEllipse();
	ofxToggle getToggleLigne();

	int getPosImageX();
	int getPosImageY();
	int getSizeImageWidth();
	int getSizeImageHeight();
	int getHueImage();
	int getSaturationImage();
	int getBrightnessImage();
	int getAlphaImage();

	int getXLight();
	int getYLight();
	int getZLight();

	int getRadius();
	float getFov();
	int getCameraNear();
	int getCameraFar();

	// Initialisation des fonctions de l'application
	ofxPanel guiOption;
	ofxButton exitButton;

	// Initialisation des sliders des param�tres de l'image
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

	// Initialisation des param�tres du cercle
	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	// Initialisation des param�tres de la cam�ra
	ofxPanel guiCamera;
	ofxFloatSlider fovSlider;
	ofxIntSlider cameraNearSlider;
	ofxIntSlider cameraFarSlider;

	//�l�ments pour les primitives vectorielles
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



	ofxFloatSlider formeVectorielleXSlider;
	ofxFloatSlider formeVectorielleYSlider;
	ofxFloatSlider formeVectorielleZSlider;

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

	ofxButton primitiveCarreButton; bool primitiveCarreCheck;
	ofxButton primitiveEllipse; bool primitiveEllipseCheck;
	ofxButton primitiveLigne; bool primitiveLigneCheck;

	ofxButton formeVectorielleButton; bool formeVectorielleCheck; 

	// Sc�ne 3D
	ofxPanel guiScene;
	ofxButton modelButton; bool modelCheck;

	// Lumi�re
	ofxPanel guiLight;
	ofxIntSlider xLightSlider;
	ofxIntSlider yLightSlider;
	ofxIntSlider zLightSlider;

	//�l�ments Autres
	ofxPanel guiOptions;
	ofxToggle rec;
	ofxToggle ell;
	ofxToggle lig;

	~Gui();
};