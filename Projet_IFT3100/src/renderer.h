#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "gui.h"

enum class Camera { FRONT, BACK, LEFT, RIGHT, TOP, DOWN};

class Renderer : public ofBaseApp {
public:
	// Image //////////////////////////////////////////////////////////////////////////////////////
	// Image importée
	vector<ofImage> vecteurImage;
	ofColor couleur;
	ofImage fond;

	bool isFondLoaded;

	// Initialisation de l'image
	int posImageX;
	int posImageY;
	int sizeImageWidth;
	int sizeImageHeight;
	int hueImage;
	int saturationImage;
	int brightnessImage;
	int alphaImage;

	// Dessin vectoriel ///////////////////////////////////////////////////////////////////////////
	// Initialisation des primitives vectorielles
	float posRectangleX;
	float posRectangleY;

	float posEllipseX;
	float posEllipseY;

	float positionXEllipse;
	float positionYEllipse;
	float positionZEllipse;

	float positionXRectangle;
	float positionYRectangle;
	float positionZRectangle;

	float tx1;
	float tx2;
	float ty2;
	float ty1;
	float tz2;
	float tz1;
	int lineWidth;

	int rstroke = 0;
	int gstroke = 0;
	int bstroke = 0;
	int rfill = 0;
	int gfill = 0;
	int bfill = 0;

	bool createRectangle = false;
	bool createEllipse = false;
	bool createLigne = false;

	int rfond = 0;
	int gfond = 0;
	int bfond = 0;

	int contourLargeur;

	float ellipseStroke = 50;
	float recStroke = 50;
	float triStroke = 50;

	int focusPrime = 0;

	// Transformation /////////////////////////////////////////////////////////////////////////////
	float posformeVectorielleX;
	float posformeVectorielleY;
	float posformeVectorielleZ;
	float rotAngle;
	int rotX;
	int rotY;
	int rotZ;

	bool createFormeVectorielle = false;

	// Géométrie //////////////////////////////////////////////////////////////////////////////////
	ofCylinderPrimitive cylindre;
	ofVboMesh topCap, bottomCap, body;
	ofMaterial material;
	ofVboMesh boxSides[ofBoxPrimitive::SIDES_TOTAL];
	ofBoxPrimitive box;

	float positionPrimitive3dX;
	float positionPrimitive3dY;
	float positionPrimitive3dZ;
	float primitive3dSize;
	bool  primitive3dRoatation = false;
	bool  primitice3dStroke = false;
	float positionPrimitive3dXBox;
	float positionPrimitive3dYBox;
	float positionPrimitive3dZBox;
	float primitive3dSizeBox;
	bool  primitive3dRoatationBox = false;
	bool  primitice3dStrokeBox = false;
	bool primitive3dSphere; 

	bool createPrimitive3dBox = false;
	bool createPrimitive3d = false;
	bool createPrimitice = false;
	
	int circleRadius;

	// Modèle
	ofxAssimpModelLoader model;
	bool isModelLoaded;

	string nameModel = "model.3ds";

	// Caméra /////////////////////////////////////////////////////////////////////////////////////
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

	// Initialisation des constantes booléennes de la caméra
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

	// Autres /////////////////////////////////////////////////////////////////////////////////////
	// Paramétrisation du temps
	float timeCurrent;
	float timeLast;
	float timeElapsed;
	// Lumière
	int xLight;
	int yLight;
	int zLight;
	ofLight * light;

	//---------------------------------------------------------------------------------------------

	Renderer();

	void setup();
	void reset();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void imageExport(const string name, const string extension) const;

	void carredessin() const; 
	shared_ptr<Gui> gui;

	void cameraSetupParameters();
	void setupCamera();
	void updateCamera();

	~Renderer();
};