

#include <Fl/gl.h>
#include "model.h"

void Model::addChild(Model* p_model)
{
	m_children.push_back(p_model);
}

Model* Model::getChild(const int pos)
{
	return m_children[pos];
}

void Model::Draw()
{
	glPushMatrix();
	m_controller.Control();
	onDraw();

	for (Model* m : m_children)
	{
		m->Draw();
	}

	glPopMatrix();
}

Model::~Model()
{
	for (Model* m : m_children)
	{
		delete m;
	}
}