


#include "MengMeiView.h"

void MengMeiView::draw()
{
	ModelerView::draw();
	setAmbientColor(0.1f, 0.1f, 0.1f);
	setDiffuseColor(COLOR_RED);

	m_MengMei.Draw();
}