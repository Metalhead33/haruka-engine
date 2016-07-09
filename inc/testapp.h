#ifndef TESTAPP_H
#define TESTAPP_H
#include "baseapp.h"
#include "static.h"
extern "C" {
#include <lib3ds.h>
}

class TestApp : public GameApp
{
public:
	TestApp(sf::ContextSettings* context_proto,std::string filename);
	bool Startup();
	bool Cleanup();
	void Render();
	bool Update(sf::Time deltaTime);
private:
	sf::Event event;
	GLuint uiVAOid, uiVBOid, theProgram;
	GLuint* mesh;
	Lib3dsFile* fail;
};

#endif // TESTAPP_H
