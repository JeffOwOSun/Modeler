
#include "MengMeiLowerArm.h"

MengMeiLowerArm::MengMeiLowerArm()
{
	m_hand = new MengMeiHand;
	m_hand->getController()->setTransX(0.7f)->setTransY(-2.6f);
	addChild(m_hand);
}

void MengMeiLowerArm::onDraw()
{
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(75, 1.0f, 0.0f, 0.0f);
	drawCylinder(3.0f, 0.5f, 0.4f);
	glPopMatrix();
}