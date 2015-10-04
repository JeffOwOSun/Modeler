#ifndef MENGMEI_H
#define MENGMEI_H

#include "model.h"

class MengMei : public Model
{
public:
	MengMei();
	void OnDraw();
private:
	Model* m_upperBody;
	Model* m_LeftUpperLeg;
	Model* m_RightUpperLeg;
};

#endif