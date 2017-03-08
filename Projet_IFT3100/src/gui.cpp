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

	defaultPosX = 0;
	defaultPosY = 0;
	defaultSizeImageWidth = 150;
	defaultSizeImageHeight = 150;

	guiImage.setup("Panneau", "", offsetX, 20);
	guiImage.add(exportButton.setup("Exportation")); exportCheck = false;
	guiImage.add(posImageX.setup("Position X de l'image", defaultPosX, 0, 600));
	guiImage.add(posImageY.setup("Position Y de l'image", defaultPosY, 0, 600));
	guiImage.add(sizeImageWidth.setup("Longueur de l'image", defaultSizeImageWidth, 25, 600));
	guiImage.add(sizeImageHeight.setup("Largeur de l'image", defaultSizeImageHeight, 25, 600));


	guiImage.add(primitiveCarre.setup("Rectangle")); primitiveCarreCheck = false; 
	//guiImage.add(primitiveEllipse.setup("Ellipse")); primitiveEllipseCheck = false;
	//guiImage.add(primitiveTriangle.setup("Triangle")); primitiveTriangleCheck = false;
	//Cercle UI
	guiCircle.setup("Sphere", "", offsetX, 160);
	guiCircle.add(circleRadius.setup("circle radius", defaultCircleRadius, 5, 200));

	//Camera
	guiCamera.setup("Camera", "", offsetX, 230);
	guiCamera.add(fovSlider.setup("Field of view", defaultFov, 0, 120));
}

void Gui::reset() {
	defaultPosX = 0;
	defaultPosY = 0;
	defaultSizeImageWidth = 150;
	defaultSizeImageHeight = 150;
	
	defaultCircleRadius = 205/2;
	defaultFov = 60;
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

int Gui::getRadius() 
{
	return circleRadius;
}

float Gui::getFov()
{
	return fovSlider;
}

// Destructeur de la classe
Gui::~Gui()
{
}