#include"LSystem.h"
#include<exception>

void LSystem::initialize() {
	m_lsys.push_back(m_axiom);
}

void LSystem::evolve(int depth) {
	//use for loop to only evolve to new levels.
	for (int level = m_lsys.size(); level < depth; ++level) {
		m_lsys.push_back(m_lsys[level - 1]);
		for (int i = 0; i < m_lsys[level].length();) {
			//match the evolveRules
			try {
				for (auto iter : m_evolveRules) {
					const std::string &key = iter.first;
					const std::string &val = iter.second;
					//compare the key
					if (m_lsys[level].compare(i, key.length(), key) == 0) {
						//replace the value
						m_lsys[level].replace(i, key.length(), val);
						//increment the index to skip the newly replaced string
						throw val.length();
					}
				}
			}
			catch (unsigned int step) {
				i += step;
				continue;
			}
			//increment i by 1 by default.
			++i;
		}
#ifdef _DEBUG
		printf("LSystem Evolved: %s\n", m_lsys.back().c_str());
#endif
	}
	
}

void LSystem::draw(int level) {
	for (int i = 0; i < m_lsys[level - 1].length();) {
		//match the drawRules
		try {
			for (auto iter : m_drawRules) {
				const std::string &key = iter.first;
				LSysDrawRule &callback = iter.second;
				//compare the key
				if (m_lsys[level - 1].compare(i, key.length(), key) == 0) {
#ifdef _DEBUG
					printf("Drawing: %s\n", key.c_str());
#endif
					//call the callback
					callback();
					//use exception to easily break out of loop
					throw key.length();
				}
			}
		}
		catch(unsigned int step) {
			i += step;
			continue;
		}
		//increment i by 1 by default
		++i;
	}
}

void LSystem::dummyRule() {}