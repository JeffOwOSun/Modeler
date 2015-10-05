
#include "MengMeiLowerBody.h"

MengMeiLowerBody::MengMeiLowerBody()
{
	m_leftUpperLeg = new MengMeiUpperLeg;
	addChild(m_leftUpperLeg);
	m_rightUpperLeg = new MengMeiUpperLeg;
	addChild(m_rightUpperLeg);
}

void MengMeiLowerBody::onDraw()
{
	drawSphere(0.7f);
}