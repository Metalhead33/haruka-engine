#ifndef BASEAPP_H
#define BASEAPP_H
#include "static.h"

class GameApp
{
public:
	GameApp(unsigned int x, unsigned int y,const std::string title, sf::Uint32 style, sf::ContextSettings* context_proto);
	GameApp(sf::ContextSettings *context_proto);
	~GameApp();
	int Run();
	virtual bool Startup() = 0;
	virtual bool Cleanup() = 0;
	virtual void Render() = 0;
	virtual bool Update(sf::Time deltaTime) = 0;
	sf::Window* GetWindow();
	sf::ContextSettings* GetContext();
private:
	sf::ContextSettings* context;
	sf::Clock *clock;
	sf::Window window;
};

#endif // BASEAPP_H
