#include "Mesh.hpp"

Mesh::Mesh(aiMesh *m_origin)
{
	IndexBuffer = 0;
	VectorBuffer = 0;
	origin = m_origin;
	if(origin)
	{
		PreProcess();
	}
}

void Mesh::PreProcess()
{
	if(IndexBuffer)
	{
		glDeleteBuffers(1,&IndexBuffer);
		IndexBuffer = 0;
	}
	if(VectorBuffer)
	{
		glDeleteBuffers(1,&VectorBuffer);
		VectorBuffer = 0;
	}
	std::vector<Vertex> Vertices;
	std::vector<unsigned int> Indices;
	for(unsigned int i = 0;i < origin->mNumVertices;++i)
	{
		Vertex v(glm::vec3(origin->mVertices[i].x,origin->mVertices[i].y,origin->mVertices[i].z),
				 glm::vec3(origin->mNormals[i].x,origin->mNormals[i].y,origin->mNormals[i].z),
				 glm::vec3(0,0,0));
		if(origin->HasTextureCoords(0))
		{
			v.TexCoords = glm::vec3(origin->mTextureCoords[i]->x,origin->mTextureCoords[i]->y,origin->mTextureCoords[i]->z);
		}
		Vertices.push_back(v);
	}
	for(unsigned int i = 0;i < origin->mNumFaces;++i)
	{
		for(unsigned int j = 0;j < origin->mFaces[i].mNumIndices;++j)
		{
			Indices.push_back(origin->mFaces[i].mIndices[j]);
		}
	}
	nVertices = Vertices.size();
	nIndices = Indices.size();
	glGenBuffers(1, &VectorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, VectorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * NumIndices, &Indices[0], GL_STATIC_DRAW);
}
