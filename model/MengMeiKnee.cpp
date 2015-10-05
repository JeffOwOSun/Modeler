
#include "MengMeiKnee.h"

MengMeiKnee::MengMeiKnee()
{
	m_lowerLeg = new MengMeiLowerLeg;
	addChild(m_lowerLeg);
}

void MengMeiKnee::onDraw()
{
	drawSphere(0.5f);
}