
#include "MengMeiLowerBody.h"

MengMeiLowerBody::MengMeiLowerBody()
{
	m_leftUpperLeg = new MengMeiUpperLeg;
	addChild(m_leftUpperLeg);
	printf("add left upper leg\n");
	m_rightUpperLeg = new MengMeiUpperLeg;
	addChild(m_rightUpperLeg);
	printf("add right upper leg\n");
}

void MengMeiLowerBody::onDraw()
{
	drawSphere(0.7f);
}