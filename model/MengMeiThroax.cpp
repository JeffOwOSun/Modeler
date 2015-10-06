
#include "MengMeiThroax.h"

MengMeiThroax::MengMeiThroax()
{
	m_LeftUpperArm = new MengMeiUpperArm;
	m_LeftUpperArm->getController()->setTransX(0.2f);
	addChild(m_LeftUpperArm);
	printf("add left upper arm\n");

	m_RightUpperArm = new MengMeiUpperArm;
	m_RightUpperArm->getController()->setTransX(-0.2f)->setRotateY(180);
	addChild(m_RightUpperArm);
	printf("add right upper arm\n");

	m_Head = new MengMeiHead;
	m_Head->getController()->setTransY(0.9f);
	addChild(m_Head);
	printf("add head\n");
}

void MengMeiThroax::onDraw()
{
	drawSphere(0.75f);
}