#ifndef MODEL_H
#define MODEL_H

#include "modelController.h"
#include "../modelerdraw.h"
#include "../stb_image.h"
#include <vector>
#include <string>
#include <iostream>

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
	 * \brief This function is to cover texture into object
	 * \param fileName JPG file name to be textured
	 * \param handle associated GLuint name in that class
	 */
	void drawTexture(std::string& fileName, GLuint& handle);

	void drawTorus(GLdouble r1, GLdouble r2);

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