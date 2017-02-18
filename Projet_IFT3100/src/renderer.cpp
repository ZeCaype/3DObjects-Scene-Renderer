#include "renderer.h"

// Constructeur de la classe Renderer
Renderer::Renderer()
{
}

// Fonction invoqu�e pour configurer les �l�ments du framebuffer
void Renderer::setup()
{
	ofSetFrameRate(60);
	ofEnableDepthTest();

	// Initialisation de la sc�ne
	reset();
}

// Fonction qui r�initialise la sc�ne
void Renderer::reset()
{
	ofLog() << "<reset>";
}

void Renderer::update()
{
}

// Fonction invoqu�e pour ajouter des �l�ments dans le framebuffer
void Renderer::draw()
{
	// Application d'un fond en blanc
	ofBackground(255);
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

// Destructeur de la classe Renderer
Renderer::~Renderer()
{
}