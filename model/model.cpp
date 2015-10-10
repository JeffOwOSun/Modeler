

#include <Fl/gl.h>
#include "model.h"

map< std::string, Model* > Model::m_modelList;

Model::Model(std::string name, Model* parent) :m_name(name), m_parent(parent)
{
	//add this model to the static modelList
	m_modelList[name] = this;
}

void Model::addChild(Model* p_model)
{
	p_model->setParent(this);
	m_children.push_back(p_model);
}

Model* Model::getChild(const int pos)
{
	return m_children[pos];
}

void Model::Draw()
{
	glPushMatrix();
	//Calls Control to set the world coordinate
	m_controller.Control();
	onDraw();

	for (Model* m : m_children)
	{
		m->Draw();
	}

	glPopMatrix();
}


void Model::drawTexture(std::string& fileName, GLuint& handle)
{
	int height, width, numComponent;
	unsigned char* textureData = stbi_load(fileName.c_str(), &width, &height, &numComponent, 4);
	if (textureData == NULL)
	{
		std::cerr << "MengMeiUpperBody:: loading texture failed" << std::endl;
	}

	glGenTextures(1, &handle);
	glBindTexture(GL_TEXTURE_2D, handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, textureData);
	glFlush();

	stbi_image_free(textureData);
}

Vec3f Model::getOrigin() {
	Vec4f origin = Vec4f(0, 0, 0, 1);
	Model* current = this;
	origin = getController()->getMatrix() * origin;
	while (current = current->getParent()) {
		origin = current->getController()->getMatrix() * origin;
	}
	//convert homogeneous coordinate to 3D spatial coordinate
	return Vec3f(origin[0] / origin[3], origin[1] / origin[3], origin[2] / origin[3]);
}

Model::~Model()
{
	for (Model* m : m_children)
	{
		delete m;
	}
}