#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include<vector>
#include"modelerglobals.h"
#include"modelerapp.h"
#include"model\model.h"

/**
* Apply IKOptimize based on the given parameters and metric,
* by minimizing the metric. Output is modified on-site, it's the
* optimal parameters for the requirement.
*/
extern void IKOptimize();

/**
* This function only calculates one step of the IKOptimize iterations.
*/
extern void IKOneStep();

//The Cost Function
extern double IKCostFunction();

#endif //INVERSE_KINEMATICS_H