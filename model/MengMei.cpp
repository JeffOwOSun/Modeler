
#include "MengMei.h"
#include "MengMeiHand.h"
#include "MengMeiHead.h"
#include "MengMeiLowerLeg.h"
#include "MengMeiFoot.h"

MengMei::MengMei() :Model("MengMei")
{
	this->getController()->setTransY(6.0f);

	GeneralModel* upperBody = new GeneralModel("UpperBody", GeneralModel::CYLINDER_SHAPE);
	upperBody->setTexture("./res/MengMeiBody.jpg");
	upperBody->setParam(3.0f, 0.5f, 0.75f);
	upperBody->getController()->setRotate(-90, 90, 0);
		
		GeneralModel* thorax = new GeneralModel("Thorax", GeneralModel::SPHERE_SHAPE);
		thorax->getController()->setTransZ(3.5f);
		thorax->setParam(0.75f);
		
			//--------------------------------
			//leftUpperArm
			//--------------------------------
			GeneralModel* leftUpperArm = new GeneralModel("LeftUpperArm", GeneralModel::CYLINDER_SHAPE);
			leftUpperArm->setParam(2.7f, 0.6f, 0.5f);
			leftUpperArm->getController()->setRotate(70, 180, 0);
			
				GeneralModel* leftElbow = new GeneralModel("LeftElbow", GeneralModel::SPHERE_SHAPE);
				leftElbow->setParam(0.1f);
				leftElbow->getController()->setTransZ(2.7f);
				leftElbow->m_beforeDraw = [](Model* self) {
					self->getController()->setRotateZ(VAL(LEFT_UARM_ROTATE));
				};

					GeneralModel* leftLowerArm = new GeneralModel("LeftLowerArm", GeneralModel::CYLINDER_SHAPE);
					leftLowerArm->setTexture(std::string("./res/MengMeiSkin.jpg"));
					leftLowerArm->setParam(3.0f, 0.3f, 0.20f);
					leftLowerArm->m_beforeDraw = [](Model* self) {
						self->getController()->setRotateY(VAL(LEFT_ELBOW));
					};
						
						Model* leftHand = new MengMeiHand();
						leftHand->getController()->setTransZ(3.5f)->setRotateY(-90);

					leftLowerArm->addChild(leftHand);
				leftElbow->addChild(leftLowerArm);
			leftUpperArm->addChild(leftElbow);

			//--------------------------------
			//rightUpperArm
			//--------------------------------
			GeneralModel* rightUpperArm = new GeneralModel("RightUpperArm", GeneralModel::CYLINDER_SHAPE);
			rightUpperArm->setParam(2.7f, 0.6f, 0.5f);
			rightUpperArm->getController()->setRotate(-70, 180, 0);

				GeneralModel* rightElbow = new GeneralModel("RightElbow", GeneralModel::SPHERE_SHAPE);
				rightElbow->setParam(0.6f);
				rightElbow->getController()->setTransZ(2.7f);
				rightElbow->m_beforeDraw = [](Model* self) {
					self->getController()->setRotateZ(VAL(RIGHT_UARM_ROTATE));
				};

					GeneralModel* rightLowerArm = new GeneralModel("RightLowerArm", GeneralModel::CYLINDER_SHAPE);
					rightLowerArm->setTexture(std::string("./res/MengMeiSkin.jpg"));
					rightLowerArm->setParam(3.0f, 0.5f, 0.4f);
					rightLowerArm->m_beforeDraw = [](Model* self) {
						self->getController()->setRotateY(VAL(RIGHT_ELBOW));
					};

						GeneralModel* rightHand = new GeneralModel("RightHand", GeneralModel::SPHERE_SHAPE);
						rightHand->setParam(0.5f);
						rightHand->getController()->setTransZ(3.0f);

					rightLowerArm->addChild(rightHand);
				rightElbow->addChild(rightLowerArm);
			rightUpperArm->addChild(rightElbow);

			//---------------------------------
			//Head
			//---------------------------------
			Model* head = new MengMeiHead();
			head->getController()->setRotate(90, 0, -90)->setTransZ(0.5f);

		thorax->addChild(leftUpperArm);
		thorax->addChild(rightUpperArm);
		thorax->addChild(head);
	upperBody->addChild(thorax);
	
	// ------------------------------------------
	// Left Leg
	// ------------------------------------------
	
	GeneralModel* leftLowerBody = new GeneralModel("LeftLowerBody", GeneralModel::SPHERE_SHAPE);
	leftLowerBody->setParam(0.7f);
	leftLowerBody->getController()->setTransX(1.2f)->setTransY(-1.4f)->setRotate(60,90,0);
	
		GeneralModel* leftUpperLeg = new GeneralModel("LeftUpperLeg", GeneralModel::CYLINDER_SHAPE);
		leftUpperLeg->setParam(3.5f, 0.6f, 0.5f);
		leftUpperLeg->m_beforeDraw = [](Model* self) {
			self->getController()->setRotateZ(90 - VAL(LEFT_ULEG_ROTATE));
			self->getController()->setRotateY(VAL(LEFT_ULEG_SWAYLR) - 32);
			self->getController()->setRotateX(-VAL(LEFT_ULEG_SWAYFB));
		};
		
			GeneralModel* leftKnee = new GeneralModel("LeftKnee", GeneralModel::SPHERE_SHAPE);
			leftKnee->setParam(0.5f);
			leftKnee->getController()->setTransZ(3.5f)->setRotateZ(-90);
			
				GeneralModel* leftLowerLeg = new GeneralModel("LeftLowerLeg", GeneralModel::CYLINDER_SHAPE);
				leftLowerLeg->setParam(4.0f, 0.5f, 0.4f);
				leftLowerLeg->m_beforeDraw = [](Model* self) {
					self->getController()->setRotateY(VAL(LEFT_KNEE));
				};

					GeneralModel* leftFoot = new GeneralModel("LeftFoot", GeneralModel::SPHERE_SHAPE);
					leftFoot->setParam(0.4f);
					leftFoot->getController()->setTransZ(4.0f);
					leftFoot->m_beforeDraw = [](Model* self) {
						//self->getController()->setRotateY(VAL(LEFT_FOOT_UD));
						self->getController()->setRotateZ(VAL(LEFT_FOOT_LR));
					};

				leftLowerLeg->addChild(leftFoot);

			leftKnee->addChild(leftLowerLeg);
			
		leftUpperLeg->addChild(leftKnee);
		
	leftLowerBody->addChild(leftUpperLeg);
	
	// ------------------------------------------
	// Right Leg
	// ------------------------------------------

	GeneralModel* rightLowerBody = new GeneralModel("RightLowerBody", GeneralModel::SPHERE_SHAPE);
	rightLowerBody->setParam(0.7f);
	rightLowerBody->getController()->setTransX(-1.2f)->setTransY(-1.4f)->setRotate(120, 90, 0);
	
		GeneralModel* rightUpperLeg = new GeneralModel("RightUpperLeg", GeneralModel::CYLINDER_SHAPE);
		rightUpperLeg->setParam(3.5f, 0.6f, 0.5f);
		rightUpperLeg->m_beforeDraw = [](Model* self) {
			self->getController()->setRotateZ(90 + VAL(RIGHT_ULEG_ROTATE));
			self->getController()->setRotateY(32 - VAL(RIGHT_ULEG_SWAYLR));
			self->getController()->setRotateX(-VAL(RIGHT_ULEG_SWAYFB));
		};
		
			GeneralModel* rightKnee = new GeneralModel("RightKnee", GeneralModel::SPHERE_SHAPE);
			rightKnee->setParam(0.5f);
			rightKnee->getController()->setTransZ(3.5f)->setRotateZ(-90);
			rightKnee->getController()->setRotateY(10);

				/*GeneralModel* rightLowerLeg = new GeneralModel("RightLowerLeg", GeneralModel::CYLINDER_SHAPE);
				rightLowerLeg->setParam(4.0f, 0.5f, 0.4f);*/
				Model* rightLowerLeg = new MengMeiLowerLeg();
				rightLowerLeg->m_beforeDraw = [](Model* self) {
					self->getController()->setRotateY(VAL(RIGHT_KNEE));
				};

					/*GeneralModel* rightFoot = new GeneralModel("RightFoot", GeneralModel::SPHERE_SHAPE);
					rightFoot->setParam(0.4f);
					rightFoot->getController()->setTransZ(4.0f);*/
					Model* rightFoot = new MengMeiFoot();
					rightFoot->getController()->setTransZ(4.0f);
					rightFoot->m_beforeDraw = [](Model* self) {
						//self->getController()->setRotateY(VAL(RIGHT_FOOT_UD));
						self->getController()->setRotateZ(VAL(RIGHT_FOOT_LR));
					};

				rightLowerLeg->addChild(rightFoot);

			rightKnee->addChild(rightLowerLeg);

		rightUpperLeg->addChild(rightKnee);
		
	rightLowerBody->addChild(rightUpperLeg);

	addChild(upperBody);
	addChild(leftLowerBody);
	addChild(rightLowerBody);

	for (auto iter : Model::m_modelList) {
		std::cout << iter.first <<std::endl;
	}

}

void MengMei::onDraw()
{
	glPushMatrix();
	drawSphere(0.8f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5f, -0.25f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(60, 1.0f, 0.0f, 0.0f);
	drawCylinder(1.0f, 0.5f, 0.5f);
#ifdef _DEBUG
	//draw the reference coordinate system
	setAmbientColor(0.1f, 0.1f, 0.1f);
	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	drawBox(10, .01f, .01f);
	glPopMatrix();

	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	drawBox(.01f, 10, .01f);
	glPopMatrix();

	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_BLUE);
	drawBox(.01f, .01f, 10);
	glPopMatrix();

	setDiffuseColor(1.0f, 1.0f, 1.0f);
#endif
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5f, -0.25f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glRotatef(-60, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -1.0f);
	drawCylinder(1.0f, 0.5f, 0.5f);
#ifdef _DEBUG
	//draw the reference coordinate system
	setAmbientColor(0.1f, 0.1f, 0.1f);
	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	drawBox(10, .01f, .01f);
	glPopMatrix();

	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	drawBox(.01f, 10, .01f);
	glPopMatrix();

	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_BLUE);
	drawBox(.01f, .01f, 10);
	glPopMatrix();

	setDiffuseColor(1.0f, 1.0f, 1.0f);
#endif
	glPopMatrix();

	
}