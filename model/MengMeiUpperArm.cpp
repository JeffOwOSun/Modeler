
#include "MengMeiUpperArm.h"

MengMeiUpperArm::MengMeiUpperArm()
{

	m_elbow = new MengMeiElbow;
	m_elbow->getController()->setTransX(2.1f)->setTransY(-1.8f);
	addChild(m_elbow);
	printf("add elbow\n");

}

void MengMeiUpperArm::onDraw()
{
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(40, 1.0f, 0.0f, 0.0f);
	drawCylinder(2.7f, 0.6f, 0.5f);
	glPopMatrix();
}