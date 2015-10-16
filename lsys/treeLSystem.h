#ifndef TREE_LSYSTEM_H
#define TREE_LSYSTEM_H

#include"LSystem.h"

class TreeLSystem : public LSystem {
public:
	TreeLSystem();
private:
	//these are draw rules
	void static zeroDraw();
	void static oneDraw();
	void static openBracketDraw();
	void static closingBracketDraw();
};

#endif //TREE_LSYSTEM_H