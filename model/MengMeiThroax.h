
#ifndef MENGMEI_THROAX_H
#define MENGMEI_THROAX_H

#include "model.h"
#include "MengMeiUpperArm.h";
#include "MengMeiHead.h";

class MengMeiThroax : public Model
{
public:
	MengMeiThroax();
	void onDraw();

private:
	Model* m_LeftUpperArm;
	Model* m_RightUpperArm;
	Model* m_Head;
};


#endif