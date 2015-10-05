
#include "MengMeiUpperArm.h"

MengMeiUpperArm::MengMeiUpperArm()
{

}

void MengMeiUpperArm::onDraw()
{
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(30, 1.0f, 0.0f, 1.0f);
	drawCylinder(3.0f, 0.6f, 0.5f);
	glPopMatrix();
}