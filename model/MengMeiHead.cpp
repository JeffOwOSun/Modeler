
#include "MengMeiHead.h"

#define HT1 -0.3f, 0.0f, -0.1f
#define HT2 -0.12f, 0.0f, 0.15f
#define HT3 0.0f, 0.0f, 0.2f
#define HT4 0.12f, 0.0f, 0.15f
#define HT5 0.3f, 0.0f, -0.1f

#define HT11 -0.25f, 0.6f, -0.1f
#define HT12 -0.225f, 0.6f, 0.05f
#define HT13 -0.15f, 0.6f, 0.15f
#define HT14 -0.1f, 0.6f, 0.2f
#define HT15 0.0f, 0.6f, 0.25f
#define HT16 0.1f, 0.6f, 0.2f
#define HT17 0.15f, 0.6f, 0.15f
#define HT18 0.225f, 0.6f, 0.05f
#define HT19 0.25f, 0.6f, -0.1f

MengMeiHead::MengMeiHead() : Model(HEAD)
{
	m_leftEye = new MengMeiEye(LEFTEYE);
	m_leftEye->getController()->setTransX(0.3f)->setTransY(0.85f)->setTransZ(0.35f)->setRotateX(-90)->setRotateY(90);
	addChild(m_leftEye);
	printf("add left eye");

	m_rightEye = new MengMeiEye(RIGHTEYE);
	m_rightEye->getController()->setTransX(-0.3f)->setTransY(0.85f)->setTransZ(0.35f)
		->setRotateX(-90)->setRotateY(90);
	addChild(m_rightEye);
	printf("add right eye");
}

void MengMeiHead::onDraw()
{
	// neck-layer, 头最下面一层，底层4，上层9
	drawTriangle(HT1, HT12, HT11);
	drawTriangle(HT2, HT13, HT12);
	drawTriangle(HT12, HT1, HT2);
	drawTriangle(HT2, HT14, HT13);
	drawTriangle(HT2, HT3, HT15);
	drawTriangle(HT15, HT14, HT2);
	drawTriangle(HT3, HT4, HT15);
	drawTriangle(HT4, HT16, HT15);
	drawTriangle(HT4, HT17, HT16);
	drawTriangle(HT4, HT5, HT17);
	drawTriangle(HT5, HT18, HT17);
	drawTriangle(HT5, HT19, HT18);



}