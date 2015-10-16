#include"treeLSystem.h"
#include"../modelerdraw.h"
#include"../modelerapp.h"

TreeLSystem::TreeLSystem() {
	//set variables
	m_variables = { "0", "1" };
	//set constants
	m_constants = { "[", "]" };
	//set axiom
	m_axiom = "0";
	//set evolve rules
	m_evolveRules["1"] = "11";
	m_evolveRules["0"] = "1[0]0";
	//set draw rules
	m_drawRules["0"] = zeroDraw;
	m_drawRules["1"] = oneDraw;
	m_drawRules["["] = openBracketDraw;
	m_drawRules["]"] = closingBracketDraw;

	initialize();
}

void TreeLSystem::zeroDraw() {
	//draw on the y direction
	glBegin(GL_LINES);
	glVertex2d(0.0, 0.0);
	glVertex2d(0.0, 0.1);
	glEnd();
	//move to the end
	glTranslated(0.0, .1, 0.0);
}

void TreeLSystem::oneDraw() {
	//draw on the y direction
	glBegin(GL_LINES);
	glVertex2d(0.0, 0.0);
	glVertex2d(0.0, 0.2);
	glEnd();
	//move to the end
	glTranslated(0.0, .2, 0.0);
}

void TreeLSystem::openBracketDraw() {
	glPushMatrix();
	//rotate with respect to z axis 45 degrees
	glRotated(VAL(LSYS_ANGLE), 0.0, 0.0, 1.0);
}

void TreeLSystem::closingBracketDraw() {
	glPopMatrix();
	//rotate with respect to z axis -45 degrees
	glRotated(-VAL(LSYS_ANGLE), 0.0, 0.0, 1.0);
}

