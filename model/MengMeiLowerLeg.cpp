
#include "MengMeiLowerLeg.h"

MengMeiLowerLeg::MengMeiLowerLeg()
{

}

void MengMeiLowerLeg::onDraw()
{
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	drawCylinder(2.7f, 0.6f, 0.5f);
	glPopMatrix();
}