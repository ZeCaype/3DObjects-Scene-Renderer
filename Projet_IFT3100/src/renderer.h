#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "gui.h"

enum class Camera { FRONT, BACK, LEFT, RIGHT, TOP, DOWN};
enum class Curve { BEZIER_CUBIC, HERMITE,SPLIN};

inline void bezierCubic(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float p3x, float p3y, float p3z,
	float p4x, float p4y, float p4z,
	float&  x, float& y, float&  z)
{
	float u = 1 - t;
	float uu = u * u;
	float uuu = uu * u;
	float tt = t * t;
	float ttt = tt * t;

	x = uuu * p1x + 3 * uu * t * p2x + 3 * u * tt * p3x + ttt * p4x;
	y = uuu * p1y + 3 * uu * t * p2y + 3 * u * tt * p3y + ttt * p4y;
	z = uuu * p1z + 3 * uu * t * p2z + 3 * u * tt * p3z + ttt * p4z;
}

inline void hermite(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float p3x, float p3y, float p3z,
	float p4x, float p4y, float p4z,
	float&  x, float& y, float&  z)
{
	float u = 1 - t;
	float uu = u * u;
	float uuu = uu * u;
	float tt = t * t;
	float ttt = tt * t;

	x = (2 * ttt - 3 * tt + 1) * p1x + (ttt - 2 * tt + t) * p2x + (ttt - tt) * p3x + (-2 * ttt + 3 * tt) * p4x;
	y = (2 * ttt - 3 * tt + 1) * p1y + (ttt - 2 * tt + t) * p2y + (ttt - tt) * p3y + (-2 * ttt + 3 * tt) * p4y;
	z = (2 * ttt - 3 * tt + 1) * p1z + (ttt - 2 * tt + t) * p2z + (ttt - tt) * p3z + (-2 * ttt + 3 * tt) * p4z;
}

inline void splin(
	float t,
	float p1x, float p1y, float p1z,
	float p2x, float p2y, float p2z,
	float p3x, float p3y, float p3z,
	float p4x, float p4y, float p4z,
	float p5x, float p5y, float p5z,
	float&  x, float& y, float&  z)
{
	float u = 1 - t;
	float uu = u * u;
	float uuu = uu * u;

	float tt = t * t;
	float ttt = tt * t;

	x = uuu * p1x + 3 * uu * t * p2x + 3 * u * tt * p3x + ttt * p4x + p5x;
	y = uuu * p1y + 3 * uu * t * p2y + 3 * u * tt * p3y + ttt * p4y + p5y;
	z = uuu * p1z + 3 * uu * t * p2z + 3 * u * tt * p3z + ttt * p4z + p5z;
}


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
	bool isModelLoaded = false;

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
	float attLight1;
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
	float attLight2;
	ofLight * light2;

	bool light3T = false;
	int RLight3;
	int GLight3;
	int BLight3;
	float xLight3;
	float yLight3;
	float zLight3;
	float attLight3;
	ofVec3f light3Ori;
	ofLight * light3;

	bool light4T = false;
	int xLight4;
	int yLight4;
	int zLight4;
	int RLight4;
	int GLight4;
	int BLight4;
	float attLight4;
	ofLight * light4;

	bool toggleMat = false;
	int shinyMat;
	int hueSpeMat; int satSpeMat;
	int hueEmiMat; int satEmiMat;
	int hueDifMat; int satDifMat;
	int hueAmbMat; int satAmbMat;
	ofMaterial material;

	bool toggleLambert = false;
	bool togglePhong = false;

	// Topologie /////////////////////////////////////////////////////////////////////////////////
	
	Curve curveID;
	Curve curveIDH;
	Curve curveIDS;
	string  curveName;

	ofPolyline lineRenderer;
	ofxPanel panelRenderer; 
	ofShader shader;
	ofVbo sphereVbo, boxVbo, cylinderVbo;
	ofVec3f center;
	float radius12;

	ofVec3f * selectedCtrlPoint;

	ofVec3f ctrlPoint1;
	ofVec3f ctrlPoint2;
	ofVec3f ctrlPoint3;
	ofVec3f ctrlPoint4;
	ofVec3f ctrlPoint5;
	ofVec3f ctrlPoint6;

	ofVec3f initialPosition1;
	ofVec3f initialPosition2;
	ofVec3f initialPosition3;
	ofVec3f initialPosition4;
	ofVec3f initialPosition5;
	ofVec3f initialPosition6;
	ofVec3f initialPosition7;

	ofVec3f position;

	float lineWidthOutline;
	float lineWidthCurve;

	float radius;
	float scale;
	float smooth;
	float offset;

	float xDelta;
	float yDelta;

	float motionSpeed;

	int framebufferWidth;
	int framebufferHeight;

	int lineResolution;

	int index;

	bool courbeBezier = false; 
	bool courbeHermite = false;
	bool courbeSplin = false;

	//Technique de rendu
	bool blurEffect;


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

	void setLightOri(ofLight & light, ofVec3f rot);

	~Renderer();
};