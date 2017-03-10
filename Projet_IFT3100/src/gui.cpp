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
	guiImage.setup("Image", "", offsetX, 20);
	guiImage.add(exportButton.setup("Exportation")); exportCheck = false;
	guiImage.add(posImageX.setup("Position X de l'image", defaultPosX, 0, 600));
	guiImage.add(posImageY.setup("Position Y de l'image", defaultPosY, 0, 600));
	guiImage.add(sizeImageWidth.setup("Longueur de l'image", defaultSizeImageWidth, 25, 600));
	guiImage.add(sizeImageHeight.setup("Largeur de l'image", defaultSizeImageHeight, 25, 600));
	guiImage.add(hueImage.setup("Hue", defaultHueImage, 0, 255));
	guiImage.add(saturationImage.setup("Saturation", defaultSaturationImage, 0, 255));
	guiImage.add(brightnessImage.setup("Brightness", defaultBrightnessImage, 0, 255));
	guiImage.add(alphaImage.setup("Alpha", defaultAlphaImage, 0, 255));

	// Cercle UI
	guiCircle.setup("Sphere", "", offsetX, 220);
	guiCircle.add(circleRadius.setup("circle radius", defaultCircleRadius, 5, 200));

	// Caméra
	guiCamera.setup("Camera", "", offsetX, 270);
	guiCamera.add(fovSlider.setup("Field of view", defaultFov, 0, 120));


	// Primitive
	guiPrimitive.setup("Primitives Vectorielles", "", offsetX, 330);
	// Rectangle
	guiPrimitive.add(primitiveCarreButton.setup("Rectangle")); primitiveCarreCheck = false;
	guiPrimitive.add(posXSlider.setup("Pos X Rectangle", -600, -900, 900));
	guiPrimitive.add(posYSlider.setup("Pos Y Rectangle", 312, -900, 900));
	// Ellipse
	guiPrimitive.add(primitiveEllipse.setup("Ellipse")); primitiveEllipseCheck = false;
	guiPrimitive.add(posXEllipseSlider.setup("Pos X Ellipse", 450, -1500, 1500));
	guiPrimitive.add(posYEllipseSlider.setup("Pos Y Ellipse", 600, -1500, 1500));
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
	//Autres (Couleur slider)
	guiOptions.setup("Couleur : Primitives", "", offsetX, 665);
 	guiOptions.add(test.setup("Toggle", 0, 0, 30));
	
	

	guiOptions.setup("Option", "", offsetX, 565);
	guiOptions.add(rec.setup("Focus Rectangle", 0, 0, 22));
	guiOptions.add(ell.setup("Focus Ellipse", 0, 0, 22));
	guiOptions.add(lig.setup("Focus Ligne", 0, 0, 22));


	// Optiosn
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

// Destructeur de la classe
Gui::~Gui()
{
}