

#include "MengMeiUpperBody.h"

MengMeiUpperBody::MengMeiUpperBody()
{
	m_Throax = new MengMeiThroax;
	m_Throax->getController()->setTransY(3.0f);
	addChild(m_Throax);
}

void MengMeiUpperBody::onDraw()
{
	drawSphere(1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 2.5f, 0.0f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	drawCylinder(3.0, 0.75, 0.5);
	glPopMatrix();
}