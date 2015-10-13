#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include<vector>
#include"modelerglobals.h"
#include"modelerapp.h"
#include"model\model.h"

class IK
{
public:
	/**
	* Apply IKOptimize based on the given parameters and metric,
	* by minimizing the metric. Output is modified on-site, it's the
	* optimal parameters for the requirement.
	*/
	static void optimize();
private:
	//Make it impossible to instantiate
	IK() {};
	/**
	* This function only calculates one step of the IKOptimize iterations.
	*/
	static void oneStep();

	//The Overall Cost Function
	static double costFunction();

	//The statusQuo
	static double targetCost();
	//The statusQuoCost function
	static double statusQuoCost();

	//parameters for the learning
	static const int maxNumIteration = 10000;
	static const double epselon;
	static const double targetCostCoeff;
	static const double statusQuoCoeff;

	static const double delta;
	static const double learningRate;
	static const double inertia;
	static const double magnifying;

	static const int vectorLength = NUMCONTROLS - LEVEL_OF_DETAIL - 1;
	static const int startPos = LEVEL_OF_DETAIL + 1;

	static std::vector<double> momentum;
	static std::vector<double> statusQuo;
};
#endif //INVERSE_KINEMATICS_H