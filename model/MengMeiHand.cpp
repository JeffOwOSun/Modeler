
#include "MengMeiHand.h"

void MengMeiHand::onDraw()
{
	drawSphere(0.5f);


	glPushMatrix();
	glTranslated(0.0f, 0.4f, 0.0f);
	

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texture);
	drawTexture(std::string("./res/MengMeiBracelet.jpg"), m_texture);
	drawTorus(0.6f, 0.15f);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}