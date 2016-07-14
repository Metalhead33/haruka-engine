#ifndef MODEL_H
#define MODEL_H
#include "Static.hpp"
#include "bufferObject.hpp"

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
	BufferObject* buf;
};

#endif // MODEL_H
