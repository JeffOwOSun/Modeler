
#include "MengMeiHead.h"

#define point1 0.0f, 0.0f, 0.0f
#define point2 0.5f, 0.3f, 0.0f
#define point3 0.7f, 0.9f, 0.4f
#define point4 -0.5f, 0.3f, 0.0f
#define point5 -0.7f, 0.9f, 0.4f
#define point6 0.6f, 1.2f, 0.3f
#define point7 -0.6f, 1.2f, 0.3f
#define point8 0.0f, 1.5f, 0.0f

#define point9 0.7f, 0.9f, -0.3f
#define point10 -0.7f, 0.9f, -0.3f
#define point11 0.0f, 1.1f, -0.6f
#define point12 0.6f, 1.2f, -0.1f
#define point13 -0.6f, 1.2f, -0.1f
#define point14 0.0f, 1.5f, 0.0f

#define point15 0.0f, 0.3f, 0.3f
#define point16 0.0f, 1.2f, 0.3f


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
	//drawSphere(0.7f);

	// starting lower poing
	drawTriangle(point1, point2, point3);
	drawTriangle(point1, point4, point5);
	drawTriangle(point1, point3, point15);
	drawTriangle(point1, point15, point5);
	drawTriangle(point3, point6, point8);
	drawTriangle(point7, point5, point8);
	drawTriangle(point5, point16, point8);
	drawTriangle(point3, point8, point16);
	drawTriangle(point5, point3, point16);
	drawTriangle(point5, point15, point3);

	drawTriangle(point1, point2, point9);
	drawTriangle(point4, point1, point10);
	drawTriangle(point1, point9, point11);
	drawTriangle(point10, point1, point11);
	
	drawTriangle(point2, point3, point9);
	drawTriangle(point4, point5, point10);
	drawTriangle(point9, point12, point11);
	drawTriangle(point11, point10, point13);
	drawTriangle(point12, point11, point14);
	drawTriangle(point11, point13, point14);

	drawTriangle(point10, point5, point13);
	drawTriangle(point13, point5, point14);
	drawTriangle(point9, point3, point12);
	drawTriangle(point12, point3, point14);
	
}