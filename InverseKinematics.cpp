/**
 * InverseKinematics.cpp
 * Contains the implementation of inverse kinematics calculation
 * and an sample metric function that operates upon the sample model
 */

#include<exception>
#include"InverseKinematics.h"
using namespace std;

void IK::IKOneStep(vector<double>& parameters, IKpredicate metric) {
	//Calculate the derivative using numerical method
	//Modify the parameters
		
	const double origMetric = metric(parameters);

	for (int i = 0; i < parameters.size(); ++i) {
		double x = parameters[i];
		parameters[i] = x + delta;
		//calculate
		double deltaY = metric(parameters) - origMetric;
		double derivative = deltaY / delta;
		//TODO: use momentum
		parameters[i] = x - derivative;
	}
}

double IK::sampleMetric(const vector<double>& parameters) {
	/**
		* Required mode
		* parameters = {
		* XPOS,
		* YPOS,
		* ZPOS,
		* HEIGHT,
		* ROTATE
		*/

	//Do a strict check of number of parameters, for now
	if (parameters.size() != 5)
		throw(exception("In method sampleMetric: number of parameters mismatch"));

	//the position of target
	const vector<double> target({ 10, 10, 10 });

	//calculate the metric
	/**TODO: here the problem is, although the access to parametric variables is not given to our
	 * sample Metric, we assume it knows the structure of the robot, and can imply the coordinates
	 * based on the mere parameters passed in.
	 *
	 * This is not a quite natural way to implement it.
	 * 
	 * One way I could think about, is to build a manager of the model, which can compute the
	 * coordinate of the handle with given parameters.
	 */
}
