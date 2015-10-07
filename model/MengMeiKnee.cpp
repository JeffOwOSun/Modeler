
#include "MengMeiKnee.h"

MengMeiKnee::MengMeiKnee()
{
	m_lowerLeg = new MengMeiLowerLeg;
	addChild(m_lowerLeg);
	printf("add lowerleg\n");
}

void MengMeiKnee::onDraw()
{
	drawSphere(0.5f);
}