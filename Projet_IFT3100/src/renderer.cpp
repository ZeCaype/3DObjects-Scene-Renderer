#include "renderer.h"

// Constructeur de la classe Renderer
Renderer::Renderer()
{
}

// Fonction invoqu�e pour configurer les �l�ments du framebuffer
void Renderer::setup()
{
	ofSetWindowTitle("Rendue");

	// Application d'un fond en blanc
	ofBackground(255);
	ofSetCircleResolution(200);

	ofSetFrameRate(60);
	ofEnableDepthTest();

	circleRadius = 0;
}

// Ajouter les fonctions des boutons du Gui ici
void Renderer::update()
{
	// Configuration du rayon du cercle
	setRadius(gui->getRadius());

	// Exportation du rendue de l'image


	if (gui->exportButton && gui->exportCheck == false)
	{
		int test = ofGetWidth();
		imageExport("render", "png");
		ofLog() << "<image is in file /bin/data/" << ">";
		gui->exportCheck = true;
	}
	else if (!gui->exportButton) gui->exportCheck = false;


	if (gui->carreButton && gui->carreCheck == false) {

		carredessin(); 
		gui->carreCheck = true; 
		ofLog() << "Carre"  ;
			
	}
	else if (!gui->carreButton) gui->carreCheck == false; 
}

// Fonction invoqu�e pour ajouter des �l�ments dans le framebuffer
void Renderer::draw()
{
	ofSetColor(0, 255, 0);
	ofDrawCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, circleRadius);
	ofDrawRectangle(10, 10, 10, 10); 
}

void Renderer::setRadius(int radius) 
{
	circleRadius = radius;
}

// Fonction permettant d'activer une commande en pressant une touche
void Renderer::keyPressed(int key)
{
	switch (key)
	{
	}
}

// Fonction permettant d'activer une commande en rel�chant une touche
void Renderer::keyReleased(int key)
{
	switch (key)
	{
	}
}

// Fonction qui exporte une image � partir de son nom et de son extension, � partir du r�pertoire ./bin/data ou d'un chemin absolue
void Renderer::imageExport(const string name, const string extension) const
{
	ofImage imageTemp;

	// Extraire des donn�es temporelles format�es
	string timestamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");

	// G�n�rer un nom de fichier unique et ordonn�
	string fileName = name + timestamp + "." + extension;

	// Capturer le contenu du framebuffer actif
	imageTemp.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	// Sauvegarder le fichier image
	imageTemp.save(fileName);

	ofLog() << "<export image: " << fileName << ">";
}

void Renderer::carredessin() const {
	ofSetColor(0, 255, 0);
	ofDrawCircle(50, 50, 20);
	ofLog() << "carre dessin"; 
}

// Destructeur de la classe Renderer
Renderer::~Renderer()
{
}