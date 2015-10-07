
#include "model.h"
#include "MengMeiUpperLeg.h"

class MengMeiLowerBody : public Model
{
public:
	MengMeiLowerBody();
	void onDraw();
private:
	Model* m_leftUpperLeg;
	Model* m_rightUpperLeg;
};