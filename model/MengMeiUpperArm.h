
#ifndef MENGMEI_UPPERARM_H
#define MENGMEI_UPPERARM_H

#include "model.h"
#include "MengMeiLowerArm.h"

class MengMeiUpperArm : public Model
{
public:
	MengMeiUpperArm();
	void onDraw();

private:
	Model* m_lowerArm;
};


#endif

