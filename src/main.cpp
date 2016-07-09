#include "testapp.h"

int main(int argc, char *argv[])
{
	// create the window
	sf::ContextSettings contextus = sf::ContextSettings(32);TestApp* app;
	contextus.depthBits = 24;
	contextus.stencilBits = 8;
	contextus.antialiasingLevel = 4;
	contextus.majorVersion = 3;
	contextus.minorVersion = 3;
	contextus.attributeFlags = 1;
	if(argc < 2) app = new TestApp(&contextus,"0");
	else app = new TestApp(&contextus,argv[1]);
	int ret = app->Run();
	delete app;
	return ret;
}
