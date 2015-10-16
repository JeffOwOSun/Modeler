#ifndef PLANT_LSYSTEM_H
#define PLANT_LSYSTEM_H

#include"LSystem.h"

class PlantLSystem : public LSystem {
public:
	PlantLSystem();
private:
	//these are draw rules
	void static drawForward();
	void static turnLeft();
	void static turnRight();
	void static saveAngles();
	void static loadAngles();
};

#endif //TREE_LSYSTEM_H