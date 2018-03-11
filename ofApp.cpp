#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(39);
	ofSetLineWidth(2);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(22, 22);

	float radius = 90;
	for (int x = 0; x < 4; x++) {

		for (int y = 0; y < 4; y++) {

			float rotate_deg = (x + y) % 2 == 0 ? ofGetFrameNum() * 0.5 : ofGetFrameNum() * -0.5;
			ofPoint point = ofPoint(radius + x * (radius * 2 * 0.9), radius + y * (radius * 2 * 0.9));

			ofPushMatrix();
			ofTranslate(point);
			ofRotate(rotate_deg);

			ofDrawCircle(0, 0, radius * 0.65);

			ofBeginShape();
			for (int deg = 0; deg < 360; deg += 1) {

				if (deg % 60 < 30) {

					ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
				}
				else {

					ofVertex(radius * 0.8 * cos(deg * DEG_TO_RAD), radius * 0.8 * sin(deg * DEG_TO_RAD));
				}
			}
			ofEndShape(true);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}