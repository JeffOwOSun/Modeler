
#include "MengMeiThroax.h"

MengMeiThroax::MengMeiThroax()
{
	m_LeftUpperArm = new MengMeiUpperArm;
	m_LeftUpperArm->getController()->setTransX(0.2f);
	addChild(m_LeftUpperArm);

	m_RightUpperArm = new MengMeiUpperArm;
	m_RightUpperArm->getController()->setTransX(-0.2f)->setRotateY(180);
	addChild(m_RightUpperArm);

	m_Head = new MengMeiHead;
	m_Head->getController()->setTransY(0.9f);
	addChild(m_Head);
}

void MengMeiThroax::onDraw()
{
	drawSphere(0.75f);
}