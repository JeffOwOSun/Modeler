
#ifndef MENGMEI_ELBOW
#define MENGMEI_ELBOW

#include "model.h"
#include "MengMeiLowerArm.h"

class MengMeiElbow : public Model
{
public:
	MengMeiElbow();
	void onDraw();
private:
	Model* m_lowerArm;
};

#endif