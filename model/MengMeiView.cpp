


#include "MengMeiView.h"
#include "..\InverseKinematics.h"

//Metric function for Inverse Kinematics
double mengMeiMetric(const std::vector<double>& parameters) {
	//update the sliders
	const int startPos = LEVEL_OF_DETAIL + 1;
	for (int i = 0; i + startPos < NUMCONTROLS; ++i) {
		SET(i + startPos, parameters[i]);
	}
	//Calculate the cost. Call refreshParameters() to make sure internal control parameters are 
	//up to date with sliders
	//head cost
	Model::m_modelList[HEAD]->refreshParameters();
	Vec3f headPos= Model::m_modelList[HEAD]->getOrigin();
	Vec3d headConstraint(VAL(HEAD_CSTRN_X), VAL(HEAD_CSTRN_Y), VAL(HEAD_CSTRN_Z));
	double headCost = 0;
	for (int i = 0; i < 3; ++i) {
		headCost += pow((double)headPos[i] - headConstraint[i], 2);
	}
	headCost = sqrt(headCost);


	//left hand cost
	Model::m_modelList[LEFTHAND]->refreshParameters();
	Vec3f leftHandPos = Model::m_modelList[LEFTHAND]->getOrigin();
	Vec3d leftHandConstraint(VAL(LHAND_CSTRN_X), VAL(LHAND_CSTRN_Y), VAL(LHAND_CSTRN_Z));
	double leftHandCost = 0;
	for (int i = 0; i < 3; ++i) {
		leftHandCost += pow((double)leftHandPos[i] - leftHandConstraint[i], 2);
	}
	leftHandCost = sqrt(leftHandCost);

	//right hand cost
	Model::m_modelList[RIGHTHAND]->refreshParameters();
	Vec3f rightHandPos = Model::m_modelList[RIGHTHAND]->getOrigin();
	Vec3d rightHandConstraint(VAL(RHAND_CSTRN_X), VAL(RHAND_CSTRN_Y), VAL(RHAND_CSTRN_Z));
	double rightHandCost = 0;
	for (int i = 0; i < 3; ++i) {
		rightHandCost += pow((double)rightHandPos[i] - rightHandConstraint[i], 2);
	}
	rightHandCost = sqrt(rightHandCost);

	//left foot cost
	Model::m_modelList[LEFTFOOT]->refreshParameters();
	Vec3f leftFootPos = Model::m_modelList[LEFTFOOT]->getOrigin();
	Vec3d leftFootConstraint(VAL(LFOOT_CSTRN_X), VAL(LFOOT_CSTRN_Y), VAL(LFOOT_CSTRN_Z));
	double leftFootCost = 0;
	for (int i = 0; i < 3; ++i) {
		leftFootCost += pow((double)leftFootPos[i] - leftFootConstraint[i], 2);
	}
	leftFootCost = sqrt(leftFootCost);

	//right foot cost
	Model::m_modelList[RIGHTFOOT]->refreshParameters();
	Vec3f rightFootPos = Model::m_modelList[RIGHTFOOT]->getOrigin();
	Vec3d rightFootConstraint(VAL(RFOOT_CSTRN_X), VAL(RFOOT_CSTRN_Y), VAL(RFOOT_CSTRN_Z));
	double rightFootCost = 0;
	for (int i = 0; i < 3; ++i) {
		rightFootCost += pow((double)rightFootPos[i] - rightFootConstraint[i], 2);
	}
	rightFootCost = sqrt(rightFootCost);

	double totalCost = headCost + leftHandCost + rightHandCost + leftFootCost + rightFootCost;
	return totalCost;
}

void MengMeiView::draw()
{
	ModelerView::draw();
	
#ifdef _DEBUG
	//Draw the axis
	setAmbientColor(0.1f, 0.1f, 0.1f);
	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	drawBox(100, .1f, .1f);
	glPopMatrix(); 
	
	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	drawBox(.1f, 100, .1f);
	glPopMatrix();
	
	glPushMatrix();
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_BLUE);
	drawBox(.1f, .1f, 100);
	glPopMatrix();

	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(1.0f, 1.0f, 1.0f);
#endif
	m_MengMei.Draw();
	ModelNames modelName = LEFTFOOT;
	Vec3f origin = Model::m_modelList[LEFTFOOT]->getOrigin();
	printf("%d:\n\tx: %f\n\ty: %f\n\tz: %f\n", modelName, origin[0], origin[1], origin[2]);
	
	//DO INVERSE KINEMATICS
	
	if (VAL(INVERSE_KINEMATICS)) {
		if (!IKLastState) {
			//retrieve the current location of parts
			std::vector<double> constrains;
			ModelNames handles[] = { HEAD, LEFTHAND, RIGHTHAND, LEFTFOOT, RIGHTFOOT };
			for (auto handle : handles) {
				Vec3f constrain = Model::m_modelList[handle]->getOrigin();
				constrains.push_back(constrain[0]);
				constrains.push_back(constrain[1]);
				constrains.push_back(constrain[2]);
			}
			//set the constrains to be the current location of parts
			const int startPos = HEAD_CSTRN_X;
			for (int i = 0; i + startPos <= RFOOT_CSTRN_Z; ++i) {
				SET(i + startPos, constrains[i]);
			}
			IKLastState = true;
		}
		//create a parameters list
		vector<double> parameters;
		const int startPos = LEVEL_OF_DETAIL + 1;
		for (int i = 0; i + startPos < NUMCONTROLS; ++i) {
			parameters.push_back(VAL(i));
		}
		//get the optimized parameters
		IK::IKOneStep(parameters, mengMeiMetric);
		//set the newest parameters
		for (int i = 0; i + startPos < NUMCONTROLS; ++i) {
			SET(i, parameters[i]);
		}
		redraw();
	}
	else {
		IKLastState = false;
	}
}

void MengMeiView::onLighting()
{
	GLfloat pos0[] = { VAL(LIGHT0_X), VAL(LIGHT0_Y), VAL(LIGHT0_Z), 0.0f };
	GLfloat diffuse0[] = { VAL(LIGHT0_R), VAL(LIGHT0_G), VAL(LIGHT0_B) };
	GLfloat pos1[] = { VAL(LIGHT1_X), VAL(LIGHT1_Y), VAL(LIGHT1_Z), 0.0f };
	GLfloat diffuse1[] = { VAL(LIGHT1_R), VAL(LIGHT1_G), VAL(LIGHT1_B) };

	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
}