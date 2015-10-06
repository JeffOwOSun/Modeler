


#include "MengMeiView.h"

void MengMeiView::draw()
{
	ModelerView::draw();
	setAmbientColor(0.1f, 0.1f, 0.1f);
	m_MengMei.Draw();
}

void MengMeiView::onLighting()
{
	GLfloat pos0[] = { VAL(LIGHT0_X), VAL(LIGHT0_Y), VAL(LIGHT0_Z), 0.0f };
	GLfloat diffuse0[] = { VAL(LIGHT0_R), VAL(LIGHT0_G), VAL(LIGHT0_B) };
	GLfloat pos1[] = { VAL(LIGHT1_X), VAL(LIGHT1_Y), VAL(LIGHT1_Z), 0.0f };
	GLfloat diffuse1[] = { VAL(LIGHT1_R), VAL(LIGHT1_G), VAL(LIGHT1_B) };

	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
}