
#include "MengMeiLowerLeg.h"

MengMeiLowerLeg::MengMeiLowerLeg()
{
	m_foot = new MengMeiFoot;
	m_foot->getController()->setTransY(-3.0f);
	addChild(m_foot);
}

void MengMeiLowerLeg::onDraw()
{
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	drawCylinder(2.7f, 0.6f, 0.5f);
	glPopMatrix();
}