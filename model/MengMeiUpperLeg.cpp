
#include "MengMeiUpperLeg.h"
MengMeiUpperLeg::MengMeiUpperLeg()
{
	m_knee = new MengMeiKnee;
	m_knee->getController()->setTransX(0.6f)->setTransY(-3.0f);
	addChild(m_knee);
	printf("add knee\n");
}

void MengMeiUpperLeg::onDraw()
{
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(80, 1.0f, 0.0f, 0.0f);
	drawCylinder(2.7f, 0.6f, 0.5f);
	glPopMatrix();
}