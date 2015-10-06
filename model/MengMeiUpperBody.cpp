

#include "MengMeiUpperBody.h"

MengMeiUpperBody::MengMeiUpperBody()
{
	m_Throax = new MengMeiThroax;
	m_Throax->getController()->setTransY(3.0f);
	addChild(m_Throax);
	printf("add throax\n");
}

void MengMeiUpperBody::onDraw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texture);
		drawTexture(std::string("./res/MengMeiBody.jpg"), m_texture);

		drawSphere(0.8f);
		glPushMatrix();
		glTranslatef(0.0f, 2.5f, 0.0f);
		glRotatef(90, 1.0f, 0.0f, 0.0f);
		drawCylinder(3.0, 0.75, 0.5);
		glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}
