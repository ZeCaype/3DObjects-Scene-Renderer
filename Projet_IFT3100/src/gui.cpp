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
	guiCamera.add(cameraNearSlider.setup("Plan near", defaultCameraNear, 0, 600));
	guiCamera.add(cameraFarSlider.setup("Plan far", defaultCameraFar, 1500, 3000));

	// Primitive
	guiPrimitive.setup("Primitives Vectorielles", "Primitives Vectorielles", offsetX, 375);
	// Rectangle
	guiPrimitive.add(primitiveCarreButton.setup("Rectangle")); primitiveCarreCheck = false;
	guiPrimitive.add(posXSlider.setup("Largeur Rectangle", -600, -900, 900));
	guiPrimitive.add(posYSlider.setup("Hauteur Rectangle", 312, -900, 900));
	guiPrimitive.add(positionXRectangleSlider.setup("Position X Rectangle", -600, -1500, 1500));
	guiPrimitive.add(positionYRectangleSlider.setup("Position Y Rectangle", -600, -1500, 1500));
	// Ellipse
	guiPrimitive.add(primitiveEllipse.setup("Ellipse")); primitiveEllipseCheck = false;
	guiPrimitive.add(posXEllipseSlider.setup("Largeur Ellipse", 450, -1500, 1500));
	guiPrimitive.add(posYEllipseSlider.setup("Hauteur Ellipse", 600, -1500, 1500));
	guiPrimitive.add(positionYEllipseSlider.setup("Position X Ellipse", -600, -1500, 1500));
	guiPrimitive.add(positionYEllipseSlider.setup("Position Y Ellipse", -600, -1500, 1500));
	// Triangle
	guiPrimitive.add(primitiveLigne.setup("Ligne")); primitiveLigneCheck = false;
	guiPrimitive.add(tx1.setup("Sommet #1 - Coord 'x'", 306, -900, 900));
	guiPrimitive.add(ty1.setup("Sommet #1 - Coord 'y'", 300, -850, 850));
	guiPrimitive.add(tx2.setup("Sommet #2 - Coord 'x'", 552, -900, 900));
	guiPrimitive.add(ty2.setup("Sommet #2 - Coord 'y'", -174, -850, 850));

	// Forme Vectorielle 
	guiPrimitive.add(formeVectorielleButton.setup("Forme Vectorielle")); formeVectorielleCheck = false; 
	guiPrimitive.add(formeVectorielleXSlider.setup("Pos X Vecteur", 450, -1500, 1500));
	guiPrimitive.add(formeVectorielleYSlider.setup("Pos Y Vecteur", 600, -1500, 1500));
	
	guiOptions.setup("Option", "", offsetX, 665);
	guiOptions.add(rec.setup("Clear Rectangle", 0, 0, 22));
	guiOptions.add(ell.setup("Clear Ellipse", 0, 0, 22));
	guiOptions.add(lig.setup("Clear Ligne", 0, 0, 22));

	//Couleurs Stroke + Fill
	guiColorPrimitives.setup("Couleur Stroke-Fill", "", 260, 375);
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
	guiScene.add(modelString.setup("Nom+Extension", nameString));
	guiScene.add(modelButton.setup("Modele")); modelCheck = false;

	// Lumière
	guiLight.setup("Lumiere", "", 260, 90);
	guiLight.add(xLightSlider.setup("x Lumiere", 0, -1000, 1000));
	guiLight.add(yLightSlider.setup("y Lumiere", 0, -1000, 1000));
	guiLight.add(zLightSlider.setup("z Lumiere", -1000, -1000, 1000));

	// Options
	guiOption.setup("Options", "", offsetX, 750);
	guiOption.add(exitButton.setup("Quitter l'application"));
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

ofxToggle Gui::getToggleRectangle()
{
	return rec;
}

ofxToggle Gui::getToggleEllipse()
{
	return ell;
}

ofxToggle Gui::getToggleLigne()
{
	return lig;
}

float Gui::getposXEllipseSlider() {
	return posXEllipseSlider; 
}

float Gui::getposYEllipseSlider()
{
	return posYEllipseSlider;
}

float Gui::getformeVectorielleXSlider() {
	return formeVectorielleXSlider;
}

float Gui::getformeVectorielleYSlider() {
	return formeVectorielleYSlider;
}


float Gui::getPositionXEllipseSlider() {
	return positionXEllipseSlider;
}


float Gui::getPositionYEllipseSlider() {
	return positionYEllipseSlider;
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

int Gui::getZLight()
{
	return zLightSlider;
}




// Destructeur de la classe
Gui::~Gui()
{
}