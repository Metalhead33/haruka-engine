#ifndef STATIC_H
#define STATIC_H
#include <iostream>
#include <fstream>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include "fileio.h"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

// Some useful defines
#define ESZ(elem) (int)elem.size()

#endif // STATIC_H
