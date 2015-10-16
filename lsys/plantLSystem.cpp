#include"plantLSystem.h"
#include"../modelerdraw.h"
#include"../modelerapp.h"

PlantLSystem::PlantLSystem() {
	//set variables
	m_variables = { "X", "F" };
	//set constants
	m_constants = { "+", "-", "[", "]" };
	//set axiom
	m_axiom = "X";
	//set evolve rules
	m_evolveRules["X"] = "F-[[X]+X]+F[+FX]-X";
	m_evolveRules["F"] = "FF";
	//set draw rules
	m_drawRules["F"] = drawForward;
	m_drawRules["-"] = turnLeft;
	m_drawRules["+"] = turnRight;
	m_drawRules["["] = saveAngles;
	m_drawRules["]"] = loadAngles;

	initialize();
}

void PlantLSystem::drawForward() {
#ifdef _DEBUG
	printf("drawForward()\n");
#endif
	//draw on the y direction
	glBegin(GL_LINES);
	glVertex2d(0.0, 0.0);
	glVertex2d(0.0, 0.1);
	glEnd();
	//move to the end
	glTranslated(0.0, .1, 0.0);
}

void PlantLSystem::turnLeft() {
#ifdef _DEBUG
	printf("turnLeft()\n");
#endif
	//rotate with respect to z axis 45 degrees
	glRotated(VAL(LSYS_ANGLE), 0.0, 0.0, 1.0);
}

void PlantLSystem::turnRight() {
#ifdef _DEBUG
	printf("turnRight()\n");
#endif
	//rotate with respect to z axis -45 degrees
	glRotated(-VAL(LSYS_ANGLE), 0.0, 0.0, 1.0);
}

void PlantLSystem::saveAngles() {
#ifdef _DEBUG
	printf("saveAngles()\n");
#endif
	glPushMatrix();
}

void PlantLSystem::loadAngles() {
#ifdef _DEBUG
	printf("loadAngles()\n");
#endif
	glPopMatrix();
}

