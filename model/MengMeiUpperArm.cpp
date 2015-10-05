
#include "MengMeiUpperArm.h"

MengMeiUpperArm::MengMeiUpperArm()
{
	m_lowerArm = new MengMeiLowerArm;
	m_lowerArm->getController()->setTransX(2.2f)->setTransY(-1.3f);
	addChild(m_lowerArm);
}

void MengMeiUpperArm::onDraw()
{
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(30, 1.0f, 0.0f, 0.0f);
	drawCylinder(2.7f, 0.6f, 0.5f);
	glPopMatrix();
}