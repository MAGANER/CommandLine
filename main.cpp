#include"CommandLine\CommandLine.h"


int main()
{
	RenderWindow window(VideoMode(720, 640), "CommandLineTest");
	CommandLine cmdl;

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

		cmdl.get_input();

		window.clear();
		cmdl.draw(&window);
		window.display();
	}


	return 0;
}