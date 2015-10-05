
#include "MengMeiLowerArm.h"

MengMeiLowerArm::MengMeiLowerArm()
{

}

void MengMeiLowerArm::onDraw()
{
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(75, 1.0f, 0.0f, 0.0f);
	drawCylinder(3.5f, 0.5f, 0.3f);
	glPopMatrix();
}