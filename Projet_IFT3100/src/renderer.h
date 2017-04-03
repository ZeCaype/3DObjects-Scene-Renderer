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

	// Nuage de Points/////////////////////////////////////////////////////////////////////////////
	int intervalleNuage;
	bool nuageDePoint;
	vector<int> xNuage;
	vector<int> yNuage;
	vector<int> zNuage;
	vector<int> sizePointNuage;

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
	ofVboMesh boxSides[ofBoxPrimitive::SIDES_TOTAL];
	ofBoxPrimitive box;
	ofSpherePrimitive sphere;
	ofSpherePrimitive sphereCouleur; 

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
	bool primitive3dSphereRotation = false;
	float primitive3dSphereSize; 
	float positionPrimitive3dXSphere;
	float positionPrimitive3dYSphere;
	float positionPrimitive3dZSphere;

	bool primitive3dSphereCouleur;
	bool primitive3dSphereRotationCouleur = false;
	bool primitive3dStrokeSphereCouleur = false; 
	float positionPrimitive3dXSphereCouleur;
	float positionPrimitive3dYSphereCouleur;
	float positionPrimitive3dZSphereCouleur;
	float nbrCercleCouleur; 


	bool createPrimitive3dSphereCouleur; 
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
	bool aspectRatio4_3;

	// Autres /////////////////////////////////////////////////////////////////////////////////////
	// Paramétrisation du temps
	float timeCurrent;
	float timeLast;
	float timeElapsed;
	
	// Lumière ///////////////////////////////////////////////////////////////////////////////////
	ofLight * light;
	
	bool light1T = false;
	int xLight1;
	int yLight1;
	int zLight1;
	int RLight1;
	int GLight1;
	int BLight1;
	ofLight * light1;

	bool light2T = false;
	int xLight2;
	int yLight2;
	int zLight2;
	int RLight2;
	int GLight2;
	int BLight2;
	float cutLight2;
	float concLight2;
	ofLight * light2;

	bool light3T = false;
	int xLight3;
	int yLight3;
	int zLight3;
	ofLight * light3;

	bool light4T = false;
	int xLight4;
	int yLight4;
	int zLight4;
	ofLight * light4;

	ofMaterial material;

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