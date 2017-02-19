#include "renderer.h"

// Constructeur de la classe Renderer
Renderer::Renderer()
{
}

// Fonction invoquée pour configurer les éléments du framebuffer
void Renderer::setup()
{
	ofSetWindowTitle("Rendue de l'image");

	// Application d'un fond en blanc
	ofBackground(255);
	ofSetCircleResolution(200);

	ofSetFrameRate(60);
	ofEnableDepthTest();
}

void Renderer::update()
{
}

// Fonction invoquée pour ajouter des éléments dans le framebuffer
void Renderer::draw()
{
}

// Fonction permettant d'activer une commande en pressant une touche
void Renderer::keyPressed(int key)
{
	switch (key)
	{
	}
}

// Fonction permettant d'activer une commande en relâchant une touche
void Renderer::keyReleased(int key)
{
	switch (key)
	{
	case 32: // key Space
		imageExport("render", "png");
		ofLog() << "<image is in file /bin/data/" << ">";
		break;
	}
}

// Fonction qui exporte une image à partir de son nom et de son extension, à partir du répertoire ./bin/data ou d'un chemin absolue
void Renderer::imageExport(const string name, const string extension) const
{
	ofImage imageTemp;

	// Extraire des données temporelles formatées
	string timestamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");

	// Générer un nom de fichier unique et ordonné
	string fileName = name + timestamp + "." + extension;

	// Capturer le contenu du framebuffer actif
	imageTemp.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	// Sauvegarder le fichier image
	imageTemp.save(fileName);

	ofLog() << "<export image: " << fileName << ">";
}

// Destructeur de la classe Renderer
Renderer::~Renderer()
{
}