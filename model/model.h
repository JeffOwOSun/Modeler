#ifndef MODEL_H
#define MODEL_H

#include "modelController.h"
#include "../modelerdraw.h"
#include <vector>

class Model
{
public:

	modelController* getController()
	{
		return &m_controller;
	}

	void addChild(Model* p_model);
	
	/**
	 * \brief Get a pointer to children model
	 */
	Model* getChild(const int pos);

	/**
	 * \brief Call controller, be called by modelView
	 */
	void Draw();

	/**
	 * \brief ABC, to be implemented at every sub-class
	 */
	virtual void onDraw() = 0;
	
	virtual ~Model();
private:
	modelController m_controller;
	std::vector<Model*> m_children;
};

#endif