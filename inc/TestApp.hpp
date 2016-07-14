#ifndef TESTAPP_H
#define TESTAPP_H
#include "BaseAapp.hpp"
#include "Static.hpp"
/*extern "C" {
#include <lib3ds.h>
}*/

namespace Engine
{

class TestApp : public GameApp
{
public:
	TestApp(sf::ContextSettings* context_proto,std::string filename);
	~TestApp();
	bool Startup();
	bool Cleanup();
	void Render();
	bool Update(sf::Time deltaTime);
private:
	sf::Event event;
	GLuint uiVAOid, uiVBOid, theProgram;
	/*GLuint* mesh;
	Lib3dsFile* fail;*/
};

}

#endif // TESTAPP_H
