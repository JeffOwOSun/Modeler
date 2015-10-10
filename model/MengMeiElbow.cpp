
#include "MengMeiElbow.h"

MengMeiElbow::MengMeiElbow()
{
	m_lowerArm = new MengMeiLowerArm;
	//m_lowerArm->getController()->setTransY(-0.3f);
	addChild(m_lowerArm);
	printf("add lower arm\n");
}

void MengMeiElbow::onDraw()
{
	//drawSphere(0.6f);
}