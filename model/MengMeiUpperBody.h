#ifndef MODEL_UPPER_BODY_H
#define MODEL_UPPER_BODY_H

#include "model.h"
#include "MengMeiThroax.h"

/**
 * \class Serves as 
 */
class MengMeiUpperBody : public Model
{
public:
	MengMeiUpperBody();
	void onDraw();
private:
	Model* m_Throax;
};

#endif