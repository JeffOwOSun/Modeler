#ifndef MENGMEI_LOWERARM_H
#define MENGMEI_LOWERARM_H

#include "model.h"
#include "MengMeiHand.h"

class  MengMeiLowerArm : public Model
{
public:
	MengMeiLowerArm();
	void onDraw();
private:
	GLuint m_texture;
	Model* m_hand;
};

#endif