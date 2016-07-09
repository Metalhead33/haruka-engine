#ifndef VECTOR_H
#define VECTOR_H
#include "static.h"
#include <vector>

const std::string ReadFromFile(std::string filename);
GLuint InitializeProgram(std::string strVertexShader,std::string strFragmentShader);
GLuint CreateShader(GLenum eShaderType, const std::string strShaderFile);
GLuint CreateProgram(const std::vector<GLuint> &shaderList);

#endif // VECTOR_H
