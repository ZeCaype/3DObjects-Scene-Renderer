#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Gui : public ofBaseApp {
public:
	int offsetX;

	// Initialisation des paramètres par défaut de l'image
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

	Gui();

	void setup();
	void reset();
	void update();
	void draw();

	float getPosXSlider();
	float getPosYSlider();

	float posX;
	float posY;

	float getTX1(); 
	float getTX2();
	float getTY1();
	float getTY2();

	int getCSRS();
	int getCSGS();
	int getCSBS();
	int getCSRF();
	int getCSGF();
	int getCSBF();

	float getposXEllipseSlider(); 
	float getposYEllipseSlider();	

	float getformeVectorielleXSlider(); 
	float getformeVectorielleYSlider(); 
	
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
	

	int getRadius();
	float getFov();
	
	// Initialisation des fonctions de l'application
	ofxPanel guiOption;
	ofxButton exitButton;

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

	// Initialisation des paramètres du cercle
	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	// Initialisation des paramètres de la caméra
	ofxPanel guiCamera;
	ofxFloatSlider fovSlider;

	//Éléments pour les primitives vectorielles
	ofxPanel guiPrimitive;
	ofxFloatSlider posXSlider;
	ofxFloatSlider posYSlider;
	ofxFloatSlider tx1;
	ofxFloatSlider tx2;
	ofxFloatSlider ty1;
	ofxFloatSlider ty2;
	ofxFloatSlider posXEllipseSlider;
	ofxFloatSlider posYEllipseSlider;

	ofxFloatSlider formeVectorielleXSlider;
	ofxFloatSlider formeVectorielleYSlider;
	
	ofxPanel guiColorPrimitives;
	ofxIntSlider sliderRStroke;
	ofxIntSlider sliderGStroke;
	ofxIntSlider sliderBStroke;
	ofxIntSlider sliderRFill;
	ofxIntSlider sliderGFill;
	ofxIntSlider sliderBFill;

	ofxButton primitiveCarreButton; bool primitiveCarreCheck;
	ofxButton primitiveEllipse; bool primitiveEllipseCheck;
	ofxButton primitiveLigne; bool primitiveLigneCheck;

	ofxButton formeVectorielleButton; bool formeVectorielleCheck; 

	//Éléments Autres
	ofxPanel guiOptions;
	ofxToggle rec;
	ofxToggle ell;
	ofxToggle lig;

	~Gui();
};