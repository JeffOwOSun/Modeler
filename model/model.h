#ifndef MODEL_H
#define MODEL_H

#include "modelController.h"
#include "../modelerdraw.h"
#include "../stb_image.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "..\vec.h"
class Model
{
public:
	Model(std::string name = "", Model* parent = NULL);

	modelController* getController()
	{
		return &m_controller;
	}

	void addChild(Model* p_model);
	
	/**
	 * \brief Get a pointer to children model
	 */
	Model* getChild(const int pos);

	//get the parent model
	Model* getParent() { return m_parent; }
	void setParent(Model* parent) { m_parent = parent; }

	//get the origin of this Object Coordinate Space
	Vec3f getOrigin();

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

	//The static map of models
	static std::map < std::string, Model* > m_modelList;

	//function pointer, callback before draw to update necessary informations;
	typedef void(*modelCallback)(Model*);
	modelCallback m_beforeDraw;
private:
	
	modelController m_controller;
	std::vector<Model*> m_children;
	std::string m_name;
	Model* m_parent;
};

#endif