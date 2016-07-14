#include "bufferObject.hpp"

BufferObject::BufferObject(GLfloat* m_Vertices, size_t m_numVertices, GLuint* m_Indices, size_t m_numIndicces, bool m_Initialize)
{
	VAO = 0;
	VBO = 0;
	EBO = 0;
	Vertices = m_Vertices;
	numVertices = m_numVertices;
	Indices = m_Indices;
	numIndicces = m_numIndicces;
	InBuf = false;
	if(m_Initialize) this->Initialize();
}

bool BufferObject::SetStats(GLfloat* m_Vertices,size_t m_numVertices,GLuint* m_Indices,size_t m_numIndicces)
{
	if(InBuf) return false;
	Vertices = m_Vertices;
	numVertices = m_numVertices;
	Indices = m_Indices;
	numIndicces = m_numIndicces;
	return true;
}

BufferObject::~BufferObject()
{
	this->Destroy();
}

bool BufferObject::Initialize(bool CleanOrigins)
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	//Binding the VAO
	glBindVertexArray(VAO);

	//Allocating the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * numVertices, Vertices, GL_STATIC_DRAW);

	//Allocating the EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * numIndicces, Indices, GL_STATIC_DRAW);
	//Triangles, right?
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	InBuf = true;
	if(CleanOrigins)
	{
		delete Vertices;
		Vertices = 0;
		delete = Indices;
		Indices = 0;
	}
	return true;
}

bool BufferObject::Destroy()
{
	if(!InBuf) return false;
	if(VAO)
	{
		glDeleteVertexArrays(1,&VAO);
		VAO = 0;
	}
	if(VBO)
	{
		glDeleteBuffers(1,&VBO);
		VBO = 0;
	}
	if(EBO)
	{
		glDeleteBuffers(1,&EBO);
		EBO = 0;
	}
	InBuf = false;
	return true;
}
