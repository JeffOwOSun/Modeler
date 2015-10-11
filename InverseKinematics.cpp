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
	vector<double> gradient;
	//calculate gradient
	for (int i = 0; i < parameters.size(); ++i) {
		//backup parameter i
		double x = parameters[i];
		parameters[i] = x + delta;
		double plusMetric = metric(parameters);
		parameters[i] = x - delta;
		double minusMetric = metric(parameters);
		//restore parameter i
		parameters[i] = x;
		//calculate
		double deltaY = plusMetric - minusMetric;
		double derivative = deltaY / (2 * delta);
		gradient.push_back(derivative);
	}
	//normalize gradient
	double length = 0;
	for (double x : gradient) length = pow(x, 2);
	length = sqrt(length);
	for (double& x : gradient) x = x / length * learningRate;
	//subtract the gradient from parameters
	for (int i = 0; i < parameters.size(); ++i) parameters[i] -= gradient[i];
}
