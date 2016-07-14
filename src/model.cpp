#include "Model.hpp"


void Model::PrepareScene()
{
	if(scene)
	{
		buf = new BufferObject[scene->mNumMeshes];
		for(int i = 0;i < scene->mNumMeshes;++i)
		{
		}
	}
}

Model::Model()
{
	scene = 0;
	texture = 0;
	buf = 0;
}

Model::~Model()
{
	if(scene) delete scene;
	if(texture) delete texture;
	if(buf) delete buf;
}

Model::Model(aiScene* SetScene,sf::Texture* SetTexture)
{
	scene = SetScene;
	texture = SetTexture;
}

Model::Model(std::string SetScene,sf::Texture* SetTexture)
{
	scene = importer.ReadFile(SetScene,
							  aiProcess_CalcTangentSpace       |
							  aiProcess_Triangulate            |
							  aiProcess_JoinIdenticalVertices  |
							  aiProcess_SortByPType);
	texture = SetTexture;
}

Model::Model(aiScene* SetScene,std::string SetTexture)
{
	scene = SetScene;
	texture = new sf::Texture();
	if(!(texture->loadFromFile(SetTexture)))
	{
			delete texture;
			texture = 0;
	}
}

Model::Model(std::string SetScene,std::string SetTexture)
{
	scene = importer.ReadFile(SetScene,
							  aiProcess_CalcTangentSpace       |
							  aiProcess_Triangulate            |
							  aiProcess_JoinIdenticalVertices  |
							  aiProcess_SortByPType);
	texture = new sf::Texture();
	if(!(texture->loadFromFile(SetTexture)))
	{
			delete texture;
			texture = 0;
	}
}

aiScene* Model::GetScene()
{
	return scene;
}

sf::Texture* Model::GetTexture()
{
	return texture;
}
