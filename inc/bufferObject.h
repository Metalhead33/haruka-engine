#ifndef BUFFEROBJECT_H
#define BUFFEROBJECT_H
#include "static.h"

class BufferObject
{
public:
	BufferObject(GLfloat* m_Vertices = 0,size_t m_numVertices = 0,GLuint* m_Indices = 0,size_t m_numIndicces = 0,bool m_Initialize = false);
	bool SetStats(GLfloat* m_Vertices,size_t m_numVertices,GLuint* m_Indices,size_t m_numIndicces);
	bool Initialize(bool CleanOrigins = true);
	bool Destroy();
private:
	GLuint VAO,VBO,EBO;
	GLfloat* Vertices;
	size_t numVertices;
	GLuint* Indices;
	size_t numIndicces;
	bool InBuf;
};

#endif // BUFFEROBJECT_H
