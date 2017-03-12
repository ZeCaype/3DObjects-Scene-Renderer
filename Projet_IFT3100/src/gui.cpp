#include "gui.h"

// Constructeur de la classe
Gui::Gui()
{
}

// Fonction invoquée à l'initialisation de l'application
void Gui::setup()
{
	ofSetWindowTitle("Gui");
	
	offsetX = 30;
	defaultCircleRadius = 205 / 2;
	defaultFov = 60;
	defaultCameraNear = 50;
	defaultCameraFar = 2500;

	// Paramétrisation par défaut de l'image
	defaultPosX = 50;
	defaultPosY = 50;
	defaultSizeImageWidth = 150;
	defaultSizeImageHeight = 150;
	defaultHueImage = 0;
	defaultSaturationImage = 0;
	defaultBrightnessImage = 255;
	defaultAlphaImage = 255;

	reset();
}

void Gui::reset() {
	// Image
	guiImage.setup("Image", "", offsetX, 10);
	guiImage.add(exportButton.setup("Exportation")); exportCheck = false;
	guiImage.add(importButton.setup("Importation precedente")); importCheck = false;
	guiImage.add(posImageX.setup("Position X de l'image", defaultPosX, 0, 600));
	guiImage.add(posImageY.setup("Position Y de l'image", defaultPosY, 0, 600));
	guiImage.add(sizeImageWidth.setup("Longueur de l'image", defaultSizeImageWidth, 25, 600));
	guiImage.add(sizeImageHeight.setup("Largeur de l'image", defaultSizeImageHeight, 25, 600));
	guiImage.add(hueImage.setup("Hue", defaultHueImage, 0, 255));
	guiImage.add(saturationImage.setup("Saturation", defaultSaturationImage, 0, 255));
	guiImage.add(brightnessImage.setup("Brightness", defaultBrightnessImage, 0, 255));
	guiImage.add(alphaImage.setup("Alpha", defaultAlphaImage, 0, 255));

	// Cercle UI
	guiCircle.setup("Sphere", "", offsetX, 230);
	guiCircle.add(circleRadius.setup("circle radius", defaultCircleRadius, 5, 200));

	// Caméra
	guiCamera.setup("Camera", "", offsetX, 280);
	guiCamera.add(fovSlider.setup("Field of view", defaultFov, 0, 120));
	guiCamera.add(cameraNearSlider.setup("Plan near", defaultCameraNear, 0, 999));
	guiCamera.add(cameraFarSlider.setup("Plan far", defaultCameraFar, 1000, 6000));


	// Primitive
	guiPrimitive.setup("Primitives Vectorielles", "Primitives Vectorielles", 260, 200);
	// Rectangle
	guiPrimitive.add(rec.setup("Rectangle", false));
	guiPrimitive.add(posXSlider.setup("Largeur Rectangle", -600, -900, 900));
	guiPrimitive.add(posYSlider.setup("Hauteur Rectangle", 312, -900, 900));

	guiPrimitive.add(positionXRectangleSlider.setup("Position X Rectangle", 300, -1500, 1500));
	guiPrimitive.add(positionYRectangleSlider.setup("Position Y Rectangle", 300, -1500, 1500));
	guiPrimitive.add(positionZRectangleSlider.setup("Position Z Rectangle", 300, -1500, 1500));
	// Ellipse
	guiPrimitive.add(ell.setup("Ellipse", false));
	guiPrimitive.add(posXEllipseSlider.setup("Largeur Ellipse", 450, -1500, 1500));
	guiPrimitive.add(posYEllipseSlider.setup("Hauteur Ellipse", 600, -1500, 1500));

	guiPrimitive.add(positionXEllipseSlider.setup("Position X Ellipse", 300, -1500, 1500));
	guiPrimitive.add(positionYEllipseSlider.setup("Position Y Ellipse", 300, -1500, 1500));
	guiPrimitive.add(positionZEllipseSlider.setup("Position Z Ellipse", 300, -1500, 1500));
	// Ligne
	guiPrimitive.add(lig.setup("Ligne", false));
	guiPrimitive.add(tx1.setup("Sommet #1 - Coord 'x'", 306, -900, 900));
	guiPrimitive.add(ty1.setup("Sommet #1 - Coord 'y'", 300, -850, 850));
	guiPrimitive.add(tz1.setup("Sommet #1 - Coord 'z'", 300, -850, 850));
	guiPrimitive.add(tx2.setup("Sommet #2 - Coord 'x'", 552, -900, 900));
	guiPrimitive.add(ty2.setup("Sommet #2 - Coord 'y'", 552, -900, 900));
	guiPrimitive.add(tz2.setup("Sommet #2 - Coord 'z'", -174, -850, 850));

	// Forme Vectorielle 
	guiPrimitive.add(formeVec.setup("Forme Vectorielle", false));
	guiPrimitive.add(formeVectorielleRSlider.setup("Rayon", 0, 0, 1000));
	guiPrimitive.add(formeVectorielleTSlider.setup("Angle Theta", PI, 0, PI));
	guiPrimitive.add(formeVectoriellePSlider.setup("Angle Phi", 0, 0, 2*PI));
	// Rotation
	guiPrimitive.add(rotAngleSlider.setup("Angle de rotation", 0, 0, 180));
	guiPrimitive.add(rotXSlider.setup("X Rotation", 0, -1, 1));
	guiPrimitive.add(rotYSlider.setup("Y Rotation", 0, -1, 1));
	guiPrimitive.add(rotZSlider.setup("Z Rotation", 0, -1, 1));

	//Couleurs Stroke + Fill
	guiColorPrimitives.setup("Couleur Stroke-Fill", "", offsetX, 375);
	guiColorPrimitives.add(sliderContour.setup("Largeur Contour", 50, 0, 100));
	guiColorPrimitives.add(sliderRStroke.setup("Stroke/Red", 0, 0, 255));
	guiColorPrimitives.add(sliderGStroke.setup("Stroke/Green", 0, 0, 255));
	guiColorPrimitives.add(sliderBStroke.setup("Stroke/Blue", 0, 0, 255));
	guiColorPrimitives.add(sliderRFill.setup("Fill/Red", 0, 0, 255));
	guiColorPrimitives.add(sliderGFill.setup("Fill/Green", 0, 0, 255));
	guiColorPrimitives.add(sliderBFill.setup("Fill/Blue", 0, 0, 255));
	guiColorPrimitives.add(sliderFONDR.setup("Fond/Red", 255, 0, 255));
	guiColorPrimitives.add(sliderFONDG.setup("Fond/Green", 255, 0, 255));
	guiColorPrimitives.add(sliderFONDB.setup("Fond/Blue", 255, 0, 255));

	// Scène 3D
	guiScene.setup("Scene 3D", "", 260, 10);
	guiScene.add(modelButton.setup("Modele")); modelCheck = false;

	// Lumière
	guiLight.setup("Lumiere", "", 260, 90);
	guiLight.add(xLightSlider.setup("x Lumiere", 0, -1000, 1000));
	guiLight.add(yLightSlider.setup("y Lumiere", 0, -1000, 1000));
	guiLight.add(zLightSlider.setup("z Lumiere", -1000, -1000, 1000));

	// Options
	guiOption.setup("Options", "", offsetX, 750);
	guiOption.add(exitButton.setup("Quitter l'application"));


	//primitive 3d 
	guiPrimitive3d.setup("Primitives 3D", "Primitive3D ", 495, 10);
	guiPrimitive3d.add(primitive3dSphere.setup("Sphere", true)); 
	guiPrimitive3d.add(primitive3dToggle.setup("Primitive 3D Cylindre" , false));
	guiPrimitive3d.add(primitive3dStroke.setup("WireFrame", false));
	guiPrimitive3d.add(primitive3dRotation.setup("Rotation", false));
	guiPrimitive3d.add(positionPrimitive3dX.setup("Position X", 450,-1500,1500));
	guiPrimitive3d.add(positionPrimitive3dY.setup("Position Y", 450, -1500, 1500));
	guiPrimitive3d.add(positionPrimitive3dZ.setup("Position Z", 450, -1500, 1500));
	guiPrimitive3d.add(Primitive3dSize.setup("Size",1,1,10));

	guiPrimitive3d.add(primitive3dToggleBox.setup("Primitive 3D Cube", false));
	guiPrimitive3d.add(primitive3dStrokeBox.setup("WireFrame", false));
	guiPrimitive3d.add(primitive3dRotationBox.setup("Rotation", false));
	guiPrimitive3d.add(positionPrimitive3dXBox.setup("Position X", 450, -1500, 1500));
	guiPrimitive3d.add(positionPrimitive3dYBox.setup("Position Y", 450, -1500, 1500));
	guiPrimitive3d.add(positionPrimitive3dZBox.setup("Position Z", 450, -1500, 1500));
	guiPrimitive3d.add(Primitive3dSizeBox.setup("Size", 1, 1, 10));


	//primitive 3d 2 

}

// Fonction de mise à jour du gui
void Gui::update()
{
	if (exitButton) std::exit(0);
}

// Fonction de dessin du gui
void Gui::draw()
{
	guiOption.draw();
	guiImage.draw();
	guiCircle.draw();
	guiCamera.draw();
	guiPrimitive.draw();
	guiOptions.draw();
	guiColorPrimitives.draw();
	guiScene.draw();
	guiLight.draw();
	guiPrimitive3d.draw();
}

int  Gui::getFOND_R() 
{
	return sliderFONDR;
}
int  Gui::getFOND_G() 
{
	return sliderFONDG;
}
int  Gui::getFOND_B() 
{
	return sliderFONDB;
}

int  Gui::getContour()
{
	return sliderContour;
}

// Retourne la position en X de l'image
int Gui::getPosImageX()
{
	return posImageX;
}
// Retourne la position en Y de l'image
int Gui::getPosImageY()
{
	return posImageY;
}
// Retourne la longueur de l'image
int Gui::getSizeImageWidth()
{
	return sizeImageWidth;
}
// Retourne la largeur de l'image
int Gui::getSizeImageHeight()
{
	return sizeImageHeight;
}
// Retourne Hue de l'image
int Gui::getHueImage()
{
	return hueImage;
}
// Retourne Saturation de l'image
int Gui::getSaturationImage()
{
	return saturationImage;
}
// Retourne Brightness de l'image
int Gui::getBrightnessImage()
{
	return brightnessImage;
}
// Retourne Alpha de l'image
int Gui::getAlphaImage()
{
	return alphaImage;
}

int Gui::getRadius() 
{
	return circleRadius;
}

float Gui::getFov()
{
	return fovSlider;
}

int Gui::getCameraNear() {
	return cameraNearSlider;
}

int Gui::getCameraFar() {
	return cameraFarSlider;
}

float Gui::getPosXSlider()
{
	return posXSlider;
}

float Gui::getPosYSlider()
{
	return posYSlider;
}

float Gui::getTX1()
{
	return tx1; 
}

float Gui::getTX2()
{
	return tx2;
}

float Gui::getTY1()
{
	return ty1;
}

float Gui::getTY2()
{
	return ty2;
}
float Gui::getTZ1()
{
	return tz1;
}
float Gui::getTZ2()
{
	return tz2;
}

int Gui::getCSRS() 
{
	return sliderRStroke;
}
int Gui::getCSGS()
{
	return sliderGStroke;
}
int Gui::getCSBS()
{
	return sliderBStroke;
}
int Gui::getCSRF()
{
	return sliderRFill;
}
int Gui::getCSGF()
{
	return sliderGFill;
}
int Gui::getCSBF()
{
	return sliderBFill;
}

bool Gui::getToggleRectangle()
{
	return rec;
}

bool Gui::getToggleEllipse()
{
	return ell;
}

bool Gui::getToggleLigne()
{
	return lig;
}

bool Gui::getToggleFormeVectorielle()
{
	return formeVec;
}

float Gui::getposXEllipseSlider() {
	return posXEllipseSlider; 
}

float Gui::getposYEllipseSlider()
{
	return posYEllipseSlider;
}

float Gui::getformeVectorielleRSlider() {
	return formeVectorielleRSlider;
}

float Gui::getformeVectorielleTSlider() {
	return formeVectorielleTSlider;
}

float Gui::getformeVectoriellePSlider() {
	return formeVectoriellePSlider;
}

float Gui::getRotAngle() {
	return rotAngleSlider;
}

int Gui::getRotX() {
	return rotXSlider;
}

int Gui::getRotY() {
	return rotYSlider;
}

int Gui::getRotZ() {
	return rotZSlider;
}

float Gui::getPositionXEllipseSlider() {
	return positionXEllipseSlider;
}


float Gui::getPositionYEllipseSlider() {
	return positionYEllipseSlider;
}

float Gui::getPositionZEllipseSlider() {
	return positionZEllipseSlider;
}


float Gui::getPositionXRectangleSlider() {
	return positionXRectangleSlider;
}
float Gui::getPositionYRectangleSlider() {
	return positionYRectangleSlider;
}
float Gui::getPositionZRectangleSlider() {
	return positionZRectangleSlider;
}



float Gui::getpositionPrimitive3dX() {
	return positionPrimitive3dX;
}
float Gui::getpositionPrimitive3dY() {
	return positionPrimitive3dY;
}
float Gui::getpositionPrimitive3dZ() {
	return positionPrimitive3dZ;
}
bool Gui::getToggleprimitive3d() {
	return primitive3dToggle;
}

bool Gui::getToggleprimitive3dStroke() {
	return primitive3dStroke;
}

bool Gui::getToggleprimitive3dRotation() {
	return primitive3dRotation;
}

float Gui::getprimitive3dSize() {
	return Primitive3dSize;
}


float Gui::getpositionPrimitive3dXBox() {
	return positionPrimitive3dXBox;
}
float Gui::getpositionPrimitive3dYBox() {
	return positionPrimitive3dYBox;
}
float Gui::getpositionPrimitive3dZBox() {
	return positionPrimitive3dZBox;
}



float Gui::getprimitive3dSizeBox() {
	return Primitive3dSizeBox;
}
bool Gui::getToggleprimitive3dBox() {
	return primitive3dToggleBox;
}


bool Gui::getToggleprimitive3dStrokeBox() {
	return primitive3dStrokeBox;
}

bool Gui::getToggleprimitive3dRotationBox() {
	return  primitive3dRotationBox;
}

bool Gui::getprimitive3dSphere() {
	return primitive3dSphere;
}

int Gui::getXLight()
{
	return xLightSlider;
}

int Gui::getYLight()
{
	return yLightSlider;
}

int Gui::getZLight()
{
	return zLightSlider;
}






// Destructeur de la classe
Gui::~Gui()
{
}