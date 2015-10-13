/**
 * InverseKinematics.cpp
 * Contains the implementation of inverse kinematics calculation
 * and an sample metric function that operates upon the sample model
 */

#include<exception>
#include"InverseKinematics.h"
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

std::vector<double> IK::momentum = std::vector<double>(vectorLength, 0.0);
std::vector<double> IK::statusQuo = std::vector<double>(vectorLength, 0.0);

const double IK::epselon = 0.00001;
const double IK::targetCostCoeff = 8;
const double IK::statusQuoCoeff = 3;

const double IK::delta = 0.1;
const double IK::learningRate = 0.1;
const double IK::inertia = 1 - learningRate;
const double IK::magnifying = 1.2;

void IK::optimize() {

	//remember the old parameters for statusQuo calculation
	for (int i = 0; i < vectorLength; ++i) {
		statusQuo[i] = (VAL(startPos + i));
	}
	//reset the momentum vector
	std::fill(momentum.begin(), momentum.end(), 0.0);

	//remember the last Cost function so that one can break off whenever it stables
	double lastCost = costFunction(), thisCost = 0;

	//randomize the initial value of controls
	srand(time(NULL));
	for (int i = startPos; i < NUMCONTROLS; ++i) {
		RANDOMIZE(i);
	}
	
	//optimize
	for (int i = 0; i < maxNumIteration; ++i) {
		oneStep();
		thisCost = costFunction();
		//for debug use
#ifdef _DEBUG
		printf("cost%d: %f\n", i, thisCost);
#endif
		//break if the change is small enough
		if (abs(lastCost - thisCost) < epselon) break;
		lastCost = thisCost;
	}
}

void IK::oneStep() {
	//Calculate the derivative using numerical method
	/**
	* The delta value signifying an increment.
	*/
	
	//the gradient vector
	vector<double> gradient;
	//calculate gradient
	const int startPos = LEVEL_OF_DETAIL + 1;
	for (int i = startPos; i < NUMCONTROLS; ++i) {
		//backup parameter i
		double x = VAL(i);
		STEPUP(i);
		double plusCost = costFunction();
		SET(i, x);
		STEPDOWN(i);
		double minusCost = costFunction();
		SET(i, x); //restore parameter
		//calculate
		double deltaY = plusCost - minusCost;
		double derivative = deltaY / (2 * delta);
		gradient.push_back(magnifying * derivative);
	}
	for (int i = 0; i < momentum.size(); ++i) {
		momentum[i] = inertia * momentum[i] + learningRate * gradient[i];
	}
	//subtract the gradient from parameters
	for (int i = startPos; i < NUMCONTROLS; ++i) {
		SET(i, VAL(i) - /*learningRate * */momentum[i - startPos]);
	}
}

double IK::targetCost() {
	//Calculate the cost. Call refreshParameters() to make sure internal control parameters are 
	//up to date with sliders
	//head cost
	Model::m_modelList[HEAD]->refreshParameters();
	Vec3f headPos = Model::m_modelList[HEAD]->getOrigin();
	Vec3f headConstraint(VAL(HEAD_CSTRN_X), VAL(HEAD_CSTRN_Y), VAL(HEAD_CSTRN_Z));
	double headCost = (headPos - headConstraint).length();

	//left hand cost
	Model::m_modelList[LEFTHAND]->refreshParameters();
	Vec3f leftHandPos = Model::m_modelList[LEFTHAND]->getOrigin();
	Vec3f leftHandConstraint(VAL(LHAND_CSTRN_X), VAL(LHAND_CSTRN_Y), VAL(LHAND_CSTRN_Z));
	double leftHandCost = (leftHandPos - leftHandConstraint).length();

	//right hand cost
	Model::m_modelList[RIGHTHAND]->refreshParameters();
	Vec3f rightHandPos = Model::m_modelList[RIGHTHAND]->getOrigin();
	Vec3f rightHandConstraint(VAL(RHAND_CSTRN_X), VAL(RHAND_CSTRN_Y), VAL(RHAND_CSTRN_Z));
	double rightHandCost = (rightHandPos - rightHandConstraint).length();

	//left foot cost
	Model::m_modelList[LEFTFOOT]->refreshParameters();
	Vec3f leftFootPos = Model::m_modelList[LEFTFOOT]->getOrigin();
	Vec3f leftFootConstraint(VAL(LFOOT_CSTRN_X), VAL(LFOOT_CSTRN_Y), VAL(LFOOT_CSTRN_Z));
	double leftFootCost = (leftFootPos - leftFootConstraint).length();

	//right foot cost
	Model::m_modelList[RIGHTFOOT]->refreshParameters();
	Vec3f rightFootPos = Model::m_modelList[RIGHTFOOT]->getOrigin();
	Vec3f rightFootConstraint(VAL(RFOOT_CSTRN_X), VAL(RFOOT_CSTRN_Y), VAL(RFOOT_CSTRN_Z));
	double rightFootCost = (rightFootPos - rightFootConstraint).length();

	return headCost + leftHandCost + rightHandCost + leftFootCost + rightFootCost;
}

double IK::statusQuoCost() {
	const int numParam = vectorLength;
	double cost = 0;
	for (int i = 0; i < numParam; ++i) {
		//get the range of the control
		double range = RANGE(startPos + i);
		//normalize the difference
		double difference = abs(VAL(i + startPos) - statusQuo[i]) / range;
		cost += difference;
	}
	//take an average
	//cost /= numParam;
	
	//the final cost will be a number smaller than 1
	return cost;
}

double IK::costFunction() {
	return targetCostCoeff * targetCost() + statusQuoCoeff * statusQuoCost();
}