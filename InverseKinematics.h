#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include<vector>

namespace IK {
	/**
	 * The delta value signifying an increment.
	 */
	const double delta = 0.001;

	/**
	* Function that maps a vector of parameters to a double metric
	*/
	typedef double(*IKpredicate)(const std::vector<double>& parameters);

	/**
	* Apply IKOptimize based on the given parameters and metric,
	* by minimizing the metric. Output is modified on-site, it's the
	* optimal parameters for the requirement.
	*/
	extern void IKOptimize(std::vector<double>& parameters, IKpredicate metric);

	/**
	* This function only calculates one step of the IKOptimize iterations.
	*/
	extern void IKOneStep(std::vector<double>& parameters, IKpredicate metric);

	/**
	* The sample metric function based on sample model of the tank
	*/
	extern double sampleMetric(const std::vector<double>& parameters);
}

#endif //INVERSE_KINEMATICS_H