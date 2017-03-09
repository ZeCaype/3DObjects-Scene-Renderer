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

	float getposXEllipseSlider(); 
	float getposYEllipseSlider();	
	
	bool getToggle();

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

	ofxPanel guiImage;

	ofxButton exportButton; bool exportCheck;
	

	// Initialisation des sliders des param�tres de l'image
	ofxIntSlider posImageX;
	ofxIntSlider posImageY;
	ofxIntSlider sizeImageWidth;
	ofxIntSlider sizeImageHeight;
	ofxIntSlider hueImage;
	ofxIntSlider saturationImage;
	ofxIntSlider brightnessImage;
	ofxIntSlider alphaImage;

	ofxPanel guiCircle;
	ofxIntSlider circleRadius;

	ofxPanel guiCamera;
	ofxFloatSlider fovSlider;

	//�l�ments pour les primitives vectorielles
	ofxPanel guiPrimitive;
	ofxFloatSlider posXSlider;
	ofxFloatSlider posYSlider;
	ofxFloatSlider tx1;
	ofxFloatSlider tx2;
	ofxFloatSlider ty1;
	ofxFloatSlider ty2;
	ofxFloatSlider posXEllipseSlider;
	ofxFloatSlider posYEllipseSlider;

	ofxButton primitiveCarreButton; bool primitiveCarreCheck;
	ofxButton primitiveEllipse; bool primitiveEllipseCheck;
	ofxButton primitiveLigne; bool primitiveLigneCheck;

	//�l�ments Autres
	ofxPanel guiOptions;
	ofxToggle test;

	~Gui();
};