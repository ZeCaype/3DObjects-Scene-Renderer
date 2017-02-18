#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("The Project");

	ofSetFrameRate(30);
	ofSetCircleResolution(1000);
}

//--------------------------------------------------------------
void ofApp::update(){

	red = ofRandom(0, 255);
	green = ofRandom(0, 255);
	blue = ofRandom(0, 255);
	size = ofRandom(20, 300);

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(red, green, blue);
	ofDrawCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, size);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
