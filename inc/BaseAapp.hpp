#ifndef BASEAPP_H
#define BASEAPP_H
#include "Static.hpp"

namespace Engine
{

class GameApp
{
public:
	GameApp(unsigned int x, unsigned int y,const std::string title, sf::Uint32 style, sf::ContextSettings* context_proto); //Complex Constructor
	GameApp(sf::ContextSettings *context_proto); //Default Constructor
	~GameApp(); // Destructor
	int Run(); // Run command
	virtual bool Startup() = 0; //This starts all - virtual function
	virtual bool Cleanup() = 0; //This cleans up all - another virtual function
	virtual void Render() = 0; //Rendering function - virtual
	virtual bool Update(sf::Time deltaTime) = 0; //Update function - virtual
	sf::Window* GetWindow(); //In case we need something from the window
	sf::ContextSettings* GetContext(); //In case we need information about the context
private:
	sf::ContextSettings* context;
	sf::Clock *clock;
	sf::Window window;
};

}

#endif // BASEAPP_H
