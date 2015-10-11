#ifndef MENGMEIVIEW_H
#define MENGMEIVIEW_H

#include "../modelerdraw.h"
#include "../modelerview.h"
#include "../modelerglobals.h"
#include "../modelerapp.h"

#include "MengMei.h"

class MengMeiView : public ModelerView
{
public:
	/**
	 * \brief Defualt constructor, following exactly in the sample
	 */
	MengMeiView(int x, int y, int w, int h, char* label)
		: ModelerView(x, y, w, h, label) {}

	/**
	 * \brief Override the draw() method of ModelerView to draw out our Mengmeizi
	 * \remark Accomplished by calling MengMei's Draw();
	 */
	void draw();

protected:
	void onLighting();

private:
	MengMei m_MengMei;
	bool IKLastState = false;
};

#endif