#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "gui.h"

enum class Camera { FRONT, BACK, LEFT, RIGHT, TOP, DOWN};

class Renderer : public ofBaseApp {
public:
	// Paramétrisation du temps
	float timeCurrent;
	float timeLast;
	float timeElapsed;

	// Lumière
	ofLight * light;

	// Caméra
	Camera cameraActive;

	ofCamera cameraFront;
	ofCamera cameraBack;
	ofCamera cameraLeft;
	ofCamera cameraRight;
	ofCamera cameraTop;
	ofCamera cameraDown;

	ofCamera * camera;

	ofQuaternion cameraOrientation;

	ofVec3f cameraPosition;
	ofVec3f cameraTarget;

	string cameraName;
	
	// Initialisation de la caméra
	float cameraFov;
	float cameraNear;
	float cameraFar;

	float fovDelta;

	float speedDelta;
	float speedTranslation;
	float speedRotation;

	float sceneOffset;

	float colorOffset;

	float cameraOffset;

	int xIndex;
	int yIndex;
	int zIndex;

	// Initialisation des constantes booléennes
	bool isVisibleCamera;

	bool isCameraMoveLeft;
	bool isCameraMoveRight;
	bool isCameraMoveUp;
	bool isCameraMoveDown;
	bool isCameraMoveForward;
	bool isCameraMoveBackward;

	bool isCameraTiltUp;
	bool isCameraTiltDown;
	bool isCameraPanLeft;
	bool isCameraPanRight;
	bool isCameraRollLeft;
	bool isCameraRollRight;

	bool isCameraFovNarrow;
	bool isCameraFovWide;

	bool isCameraPerspective;

	bool isKeyPressUp;
	bool isKeyPressDown;
	bool isKeyPressLeft;
	bool isKeyPressRight;

	bool isKeyPressA;
	bool isKeyPressD;
	bool isKeyPressE;
	bool isKeyPressH;
	bool isKeyPressI;
	bool isKeyPressJ;
	bool isKeyPressK;
	bool isKeyPressQ;
	bool isKeyPressS;
	bool isKeyPressU;
	bool isKeyPressW;
	bool isKeyPressX;
	bool isKeyPressY;
	bool isKeyPressZ;

	// Image importée
	vector<ofImage> vecteurImage;
	ofColor couleur;
	ofImage fond;

	bool isFondLoaded;

	// Initialisation des primitives vectorielles
	float posRectangleX;
	float posRectangleY;
	float posformeVectorielleX; 
	float posformeVectorielleY; 

	float tx1;
	float tx2;
	float ty2;
	float ty1;
	
	float posEllipseX;
	float posEllipseY;

	bool createRectangle = false;
	bool createEllipse = false;
	bool createLigne = false;
	bool createFormeVectorielle = false; 

	void primitiveRectangle(int x, int y);
	void primitiveLigne(int x, int y);
	void primitiveEllispe(int x, int y);
	void FormeVectorielle(int x, int y);

	void setformeVectorielXSlider(int posX);
	void setformeVectorielYSlider(int posY);

	void setPosXSlider(int posX);
	void setPosYSlider(int posY);

	void setTX1(int posX);
	void setTX2(int posY);
	void setTY1(int posY);
	void setTY2(int posY);

	void setposXEllipseSlider(int posX);
	void setposYEllipseSlider(int posY);


	float ellipseStroke = 50;
	float recStroke = 50;
	float triStroke = 50;

	ofxToggle stateToggle;
	void setToggle(ofxToggle bouton);
	void ReactionRec();
	void ReactionEll();
	void ReactionLig();

	//------------------------------------------------------------
	// Initialisation de l'image
	int posImageX;
	int posImageY;
	int sizeImageWidth;
	int sizeImageHeight;
	int hueImage;
	int saturationImage;
	int brightnessImage;
	int alphaImage;

	int circleRadius;

	Renderer();

	void setup();
	void reset();
	void update();
	void draw();

	// Fonctions de la paramétrisation de l'image
	void setPosImageX(int posX);
	void setPosImageY(int posY);
	void setSizeImageWidth(int sizeW);
	void setSizeImageHeight(int sizeH);
	void setHueImage(int hue);
	void setSaturationImage(int sat);
	void setBrightnessImage(int bright);
	void setAlphaImage(int alpha);

	void setRadius(int radius);
	void setFieldOfView(float fov);

	void keyPressed(int key);
	void keyReleased(int key);

	void imageExport(const string name, const string extension) const;


	void carredessin() const; 
	shared_ptr<Gui> gui;

	void cameraSetupParameters();
	void setupCamera();
	void updateCamera();
	void cameraDraw();

	~Renderer();
};