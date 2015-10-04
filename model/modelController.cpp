
#include <FL/gl.h>
#include "modelController.h"


void modelController::Control()
{
	glTranslatef(trans.x, trans.y, trans.z);
	glRotatef(rotate.x, 1.0f, 0.0f, 0.0f);
	glRotatef(rotate.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rotate.z, 0.0f, 0.0f, 1.0f);
	glScalef(scale.x, scale.y, scale.z);
}