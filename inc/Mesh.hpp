#ifndef MESH_H
#define MESH_H
#include "Static.hpp"
#include <vector>

class Mesh
{
public:
	Mesh(aiMesh* m_origin = 0);
private:
	aiMesh* origin;
	unsigned int nVertices;
	unsigned int nIndices;
	GLuint VectorBuffer,IndexBuffer;
	void PreProcess();
};

#endif // MESH_H
