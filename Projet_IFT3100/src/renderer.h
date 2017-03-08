#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "gui.h"

enum class Camera { FRONT, BACK, LEFT, RIGHT, TOP, DOWN};

class Renderer : public ofBaseApp
{
public:

	//Camera
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

	float cameraFov;
	float cameraNear;
	float cameraFar;

	float fovDelta;

	float timeCurrent;
	float timeLast;
	float timeElapsed;

	float speedDelta;
	float speedTranslation;
	float speedRotation;

	float sceneOffset;

	float colorOffset;

	float cameraOffset;

	int xIndex;
	int yIndex;
	int zIndex;

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
	ofImage fond;

	ofColor couleur;

	bool isFondLoaded;

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

	shared_ptr<Gui> gui;

	~Renderer();

	void cameraSetupParameters();
	void setupCamera();
	void updateCamera();
	void cameraDraw();
};