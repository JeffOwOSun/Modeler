#include "MarchingCube.h"

MarchingCube::MarchingCube(int numGrid)
{
	// because the property of square
	numVertices = (numGrid + 1) * (numGrid + 1) * (numGrid + 1);
	m_vertices = new mcVertex[numVertices];

	// because the property of cube (rubbish comment)
	numCubes = numGrid * numGrid * numGrid;
	m_cubes = new mcCube[numCubes];

	int cnt = 0;
	for (int i = 0; i < numVertices + 1; ++i)
		for (int j = 0; j < numVertices + 1; ++j)
			for (int k = 0; k < numVertices + 1; ++k)
				m_vertices[cnt++].position = Vec3f(
					(i*20.0f) / (numGrid - 10.0f),
					(j*20.0f) / (numGrid - 10.0f),
					(k*20.0f) / (numGrid - 10.0f));

	int cnt = 0;
	for (int i = 0; i < numVertices; ++i)
	{
		for (int j = 0; j < numVertices; ++j)
		{
			for (int k = 0; k < numVertices; ++k)
			{
				// May not so friendly in the first see, however, just list them by hand, suppose num Grid is 2
				// 0, 1, 3, 4, 9, 10, 12, 13, just the first cube
				m_cubes[cnt].cbVertices[0] = &m_vertices[(i*(numGrid + 1) + j)*(numGrid + 1) + k];
				m_cubes[cnt].cbVertices[1] = &m_vertices[(i*(numGrid + 1) + j)*(numGrid + 1) + k + 1];
				m_cubes[cnt].cbVertices[3] = &m_vertices[(i*(numGrid + 1) + (j + 1))*(numGrid + 1) + k];
				m_cubes[cnt].cbVertices[2] = &m_vertices[(i*(numGrid + 1) + (j + 1))*(numGrid + 1) + k + 1];
				m_cubes[cnt].cbVertices[4] = &m_vertices[((i + 1)*(numGrid + 1) + j)*(numGrid + 1) + k];
				m_cubes[cnt].cbVertices[5] = &m_vertices[((i + 1)*(numGrid + 1) + j)*(numGrid + 1) + k + 1];
				m_cubes[cnt].cbVertices[6] = &m_vertices[((i + 1)*(numGrid + 1) + (j + 1))*(numGrid + 1) + k + 1];
				m_cubes[cnt].cbVertices[7] = &m_vertices[((i + 1)*(numGrid + 1) + (j + 1))*(numGrid + 1) + k];
				cnt++;
			}
		}
	}

}

void MarchingCube::drawSurface(float threshold)
{
	numSurface = 0;
	static sfVertex edgeVertices[12];
	glBegin(GL_TRIANGLES);
	{
		for (int i = 0; i < numCubes; ++i)
		{
			unsigned char cubeIndex = 0;
			if (m_cubes[i].cbVertices[0]->value < threshold) cubeIndex |= 1;
			if (m_cubes[i].cbVertices[1]->value < threshold) cubeIndex |= 2;
			if (m_cubes[i].cbVertices[2]->value < threshold) cubeIndex |= 4;
			if (m_cubes[i].cbVertices[3]->value < threshold) cubeIndex |= 8;
			if (m_cubes[i].cbVertices[4]->value < threshold) cubeIndex |= 16;
			if (m_cubes[i].cbVertices[5]->value < threshold) cubeIndex |= 32;
			if (m_cubes[i].cbVertices[6]->value < threshold) cubeIndex |= 64;
			if (m_cubes[i].cbVertices[7]->value < threshold) cubeIndex |= 128;

			int usedEdge = edgeTable[cubeIndex];

			if (usedEdge == 0 || usedEdge == 255) continue;

		}

	}
	glEnd();
}

MarchingCube::~MarchingCube()
{
	if (m_vertices) delete[] m_vertices;
	m_vertices = NULL;
	numVertices = 0;
	if (m_cubes) delete[] m_cubes;
	m_cubes = NULL;
	numCubes = 0;
}

