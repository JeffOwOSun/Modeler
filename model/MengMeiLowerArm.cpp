
#include "MengMeiLowerArm.h"

MengMeiLowerArm::MengMeiLowerArm()
{
	m_hand = new MengMeiHand;
	m_hand->getController()->setTransX(2.7f);
	addChild(m_hand);
	printf("add hand\n");
}

void MengMeiLowerArm::onDraw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texture);
		drawTexture(std::string("./res/MengMeiSkin.jpg"), m_texture);
		glPushMatrix();
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		//glRotatef(75, 1.0f, 0.0f, 0.0f);
		drawCylinder(3.0f, 0.15f, 0.1f);
		glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}