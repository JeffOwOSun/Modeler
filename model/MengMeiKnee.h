
#ifndef MENGMEI_KNEE_H
#define MENGMEI_KNEE_H

#include "model.h"
#include "MengMeiLowerLeg.h"

class MengMeiKnee : public Model
{
public:
	MengMeiKnee();
	void onDraw();
private:
	Model* m_lowerLeg;
};

#endif