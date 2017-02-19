#include "application.h"

//--------------------------------------------------------------
void application::setup() {

	renderer = new Renderer();
	renderer->setup();

	gui = new Gui();
	gui->setup();
}

//--------------------------------------------------------------
void application::update() {

}

//--------------------------------------------------------------
void application::draw() {
	gui->draw();
	renderer->draw();
}

//--------------------------------------------------------------
void application::keyReleased(int key) {

}

