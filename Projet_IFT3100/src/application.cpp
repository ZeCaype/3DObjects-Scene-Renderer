#include "application.h"

// Constructeur de la classe
Application::Application()
{
	renderer = nullptr;
}

// Fonction invoquée à l'initialisation de l'application
void Application::setup()
{
	ofSetWindowTitle("Rendue de l'image");

	ofLog() << "<app::setup>";

	renderer = new Renderer();
	renderer->setup();
}

// Fonction
void Application::update()
{
	renderer->update();
}

// Fonction invoquée lors d'une mise à jour du rendu de la fenêtre de l'application
void Application::draw()
{
	renderer->draw();
}

// Fonction permettant d'activer une commande en pressant une touche
void Application::keyPressed(int key)
{
	switch (key)
	{
	default:
		renderer->reset();
		break;
	}
}

// Fonction permettant d'activer une commande en relâchant une touche
void Application::keyReleased(int key)
{
	switch (key)
	{
	case 32: // key Space
		renderer->imageExport("render", "png");
		ofLog() << "<image is in file /bin/data/" << ">";
		break;

	default:
		renderer->reset();
		break;
	}
}

// Fonction invoquée quand l'application quitte
void Application::exit()
{
	ofLog() << "<app::exit>";
}

// Destructeur de la classe
Application::~Application()
{
	if (nullptr != renderer)
		delete renderer;
}