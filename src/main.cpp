#include "testapp.h"

int main()
{
	// create the window
	sf::ContextSettings contextus = sf::ContextSettings(32);
	contextus.depthBits = 24;
	contextus.stencilBits = 8;
	contextus.antialiasingLevel = 4;
	contextus.majorVersion = 3;
	contextus.minorVersion = 3;
	contextus.attributeFlags = 1;
	TestApp app(&contextus,"0");
	return app.Run();
}
