#ifndef MODEL_H
#define MODEL_H
#include "static.h"
#include "bufferObject.h"

typedef struct Meshes
{
	GLuint* pointers;
	size_t n_pointers;
} MMeshes;

class Model
{
public:
	Model(); //Default constructor
	~Model(); //Destructor
	Model(aiScene* SetScene,sf::Texture* SetTexture);
	Model(std::string SetScene,sf::Texture* SetTexture);
	Model(aiScene* SetScene,std::string SetTexture);
	Model(std::string SetScene,std::string SetTexture);
	aiScene* GetScene();
	sf::Texture* GetTexture();
	void PrepareScene();
private:
	aiScene* scene;
	sf::Texture* texture;
	Assimp::Importer importer;
	MMeshes meshes;
};

#endif // MODEL_H
