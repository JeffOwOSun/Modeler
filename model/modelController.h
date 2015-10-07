/**
* This file serves as controller for model
*/

#ifndef MODEL_CONTROLLER_H
#define MODEL_CONTROLLER_H

class modelController
{
public:
	modelController()
	{
		trans = { 0, 0, 0 };
		scale = { 1, 1, 1 };
		rotate = { 0, 0, 0 };
	}

	void Control();

	modelController* setTransX(const float x)
	{
		trans.x = x;
		return this;
	}

	modelController* setTransY(const float y)
	{
		trans.y = y;
		return this;
	}

	modelController* setTransZ(const float z)
	{
		trans.z = z;
		return this;
	}

	modelController* setScaleX(const float x)
	{
		scale.x = x;
		return this;
	}

	modelController* setScaleY(const float y)
	{
		scale.y = y;
		return this;
	}

	modelController* setScaleZ(const float z)
	{
		scale.z = z;
		return this;
	}

	modelController* setRotateX(const float x)
	{
		rotate.x = x;
		return this;
	}

	modelController* setRotateY(const float y)
	{
		rotate.y = y;
		return this;
	}

	modelController* setRotateZ(const float z)
	{
		rotate.z = z;
		return this;
	}

private:
	struct {
		float x, y, z;
	} trans;

	struct {
		float x, y, z;
	} scale;

	struct {
		float x, y, z;
	} rotate;
};


#endif