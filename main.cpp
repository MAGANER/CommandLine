#include"CommandLine\CommandLine.h"


int main()
{
	RenderWindow window(VideoMode(720, 640), "CommandLineTest");
	CommandLine cmdl;

	bool key_pressed = false;
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

		if (Keyboard::isKeyPressed(Keyboard::Tilde) && !key_pressed)
		{
			bool is_working = cmdl.is_working();
			if (is_working)
			{
				cmdl.set_working_state(false);
			}
			else
			{
				cmdl.set_working_state(true);
			}

			key_pressed = true;
		}
		if (!Keyboard::isKeyPressed(Keyboard::Tilde))
		{
			key_pressed = false;
		}

		cmdl.get_input();

		window.clear();
		cmdl.draw(&window);
		window.display();
	}


	return 0;
}