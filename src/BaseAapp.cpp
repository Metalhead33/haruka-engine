#include "BaseAapp.hpp"

namespace Engine
{

GameApp::GameApp(unsigned int x, unsigned int y,const std::string title, sf::Uint32 style, sf::ContextSettings* context_proto)
	: window(sf::VideoMode(x,y),title,style,*(context = context_proto))
{
	clock = 0;
	window.setVerticalSyncEnabled(true);
}
GameApp::GameApp(sf::ContextSettings* context_proto)
	: window(sf::VideoMode::getDesktopMode(),"Default Window",sf::Style::Default,*(context = context_proto))
{
	clock = 0;
	window.setVerticalSyncEnabled(true);
}

GameApp::~GameApp()
{
	if(clock) delete clock;
}

int GameApp::Run()
{
	sf::Time temp_time;
	if(!clock) clock = new sf::Clock();
	if(!Startup())
	return -1;
	while(window.isOpen())
	{
		temp_time = clock->restart();
		if(!Update(temp_time)) window.close();
		else Render();
	}
	delete clock;
	clock = 0;
	return !(Cleanup());
}

sf::Window* GameApp::GetWindow()
{
	return &window;
}

sf::ContextSettings* GameApp::GetContext()
{
	return context;
}

}
