#ifndef LSYSTEM_H
#define LSYSTEM_H

#include"../modelerglobals.h"
#include<string>
#include<vector>
#include<map>

class LSystem {
public:
	//the function pointer for draw rule
	typedef void(*LSysDrawRule)();
	//operations
	void initialize();
	void evolve(int depth = 1);
	void draw(int depth = 1);
	//parameters
	std::vector<std::string> m_variables;
	std::vector<std::string> m_constants;
	std::string m_axiom;
	std::map<std::string, std::string> m_evolveRules;
	std::map<std::string, void (*)()> m_drawRules;
protected:
	void static dummyRule();
private:
	std::vector<std::string> m_lsys;
};

#endif //LSYSTEM_H