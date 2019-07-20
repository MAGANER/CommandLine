#include"SFML\Graphics.hpp"
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(720, 640), "CommandLineTest");
	while (window.isOpen())
	{
		//handle SFML events
		Event event;
		while(window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}


		window.clear();
		window.display();
	}


	return 0;
}