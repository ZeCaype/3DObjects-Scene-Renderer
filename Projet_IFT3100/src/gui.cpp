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
	//Image
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

	//Cercle UI
	guiCircle.setup("Sphere", "", offsetX, 250);
	guiCircle.add(circleRadius.setup("circle radius", defaultCircleRadius, 5, 200));

	//Camera
	guiCamera.setup("Camera", "", offsetX, 320);
	guiCamera.add(fovSlider.setup("Field of view", defaultFov, 0, 120));


	//Primitive
	guiPrimitive.setup("Primitives Vectorielles", "", offsetX, 400);

	guiPrimitive.add(primitiveCarreButton.setup("Rectangle")); primitiveCarreCheck = false;
	guiPrimitive.add(posXSlider.setup("Pos X Rectangle", defaultPosX, -600, 600));
	guiPrimitive.add(posYSlider.setup("Pos Y Rectangle", defaultPosY, -600, 600));

	guiPrimitive.add(primitiveEllipse.setup("Ellipse")); primitiveEllipseCheck = false;
	guiPrimitive.add(posXEllipseSlider.setup("Pos X Ellipse", defaultPosX, -600, 600));
	guiPrimitive.add(posYEllipseSlider.setup("Pos Y Ellipse", defaultPosX, -600, 600));

	guiPrimitive.add(primitiveTriangle.setup("Triangle")); primitiveTriangleCheck = false;
	guiPrimitive.add(posXTriangleSlider.setup("Pos X Triangle", defaultPosX, -600, 600));
	guiPrimitive.add(posYTriangleSlider.setup("Pos Y Triangle", defaultPosX, -600, 600));
	
}

// Fonction
void Gui::update()
{
}

// Fonction
void Gui::draw()
{
	guiImage.draw();
	guiCircle.draw();
	guiCamera.draw();
	guiPrimitive.draw();
}

int Gui::getPosImageX()
{
	return posImageX;
}

int Gui::getPosImageY()
{
	return posImageY;
}

int Gui::getSizeImageWidth()
{
	return sizeImageWidth;
}

int Gui::getSizeImageHeight()
{
	return sizeImageHeight;
}

int Gui::getHueImage()
{
	return hueImage;
}

int Gui::getSaturationImage()
{
	return saturationImage;
}

int Gui::getBrightnessImage()
{
	return brightnessImage;
}

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

float Gui::getposXTriangleSlider()
{
	return posXTriangleSlider; 
}

float Gui::getposYTriangleSlider()
{
	return posYTriangleSlider;
}

float Gui::getposXEllipseSlider() {
	return posXEllipseSlider; 
}

float Gui::getposYEllipseSlider()
{
	return posYEllipseSlider;
}

// Destructeur de la classe
Gui::~Gui()
{
}