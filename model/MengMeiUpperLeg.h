
#ifndef MENGMEI_UPPERLEG_H
#define MENGMEI_UPPERLEG_H

#include "model.h"
#include "MengMeiKnee.h"

class MengMeiUpperLeg : public Model
{
public:
	MengMeiUpperLeg();
	void onDraw();
private:
	Model* m_knee;
};

#endif

