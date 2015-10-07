
#ifndef MENGMEI_UPPERARM_H
#define MENGMEI_UPPERARM_H

#include "model.h"
#include "MengMeiElbow.h"

class MengMeiUpperArm : public Model
{
public:
	MengMeiUpperArm();
	void onDraw();

private:
	Model* m_elbow;
};


#endif

