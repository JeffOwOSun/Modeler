

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

Model::~Model()
{
	for (Model* m : m_children)
	{
		delete m;
	}
}