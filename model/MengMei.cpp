
#include "MengMei.h"

MengMei::MengMei()
{
	this->getController()->setTransY(1.0f)->setScaleX(0.7)->setScaleY(0.7)->setScaleZ(0.7);

	m_UpperBody = new MengMeiUpperBody;
	addChild(m_UpperBody);
	printf("add upper body\n");

	m_LeftLowerBody = new MengMeiLowerBody;
	m_LeftLowerBody->getController()->setTransX(1.2f)->setTransY(-1.4f);
	addChild(m_LeftLowerBody);
	printf("add left lower body\n");

	m_RightLowerBody = new MengMeiLowerBody;
	m_RightLowerBody->getController()->setTransX(-1.2f)->setTransY(-1.4f)->setRotateY(180);
	addChild(m_RightLowerBody);
	printf("add right lower body\n");
}

void MengMei::onDraw()
{
	glPushMatrix();
	glTranslatef(0.5f, -0.25f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(60, 1.0f, 0.0f, 0.0f);
	drawCylinder(1.0f, 0.5f, 0.5f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5f, -0.25f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(-60, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -1.0f);
	drawCylinder(1.0f, 0.5f, 0.5f);
	
	glPopMatrix();
}