#ifndef MENGMEI_H
#define MENGMEI_H

#include <FL/gl.h>
#include "../modelerdraw.h"

#include "model.h"
#include "MengMeiUpperBody.h"
#include "MengMeiLowerBody.h"

/**
 * \class This is the connection part between upper body and leg
 */
class MengMei : public Model
{

public:
	MengMei();
	void onDraw();

private:
	Model* m_UpperBody;
	Model* m_LeftLowerBody;
	Model* m_RightLowerBody;
};

#endif