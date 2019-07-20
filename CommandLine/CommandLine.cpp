#include "CommandLine.h"
CommandLine::CommandLine()
{
	font.loadFromFile("font/font.ttf");

	entered_command = new Text("", font, 30);

	key_pressed = false;
}
CommandLine::~CommandLine()
{
	delete entered_command;
}

void CommandLine::get_input()
{
	int first_key = Keyboard::A;
	int last_key  = Keyboard::Num9;

	for (int key = first_key; key < last_key; ++key)
	{
		Keyboard::Key pressed_key = static_cast<Keyboard::Key>(key);
		if (Keyboard::isKeyPressed(pressed_key) && !key_pressed)
		{
			//check is it char, if it's not, than it's number
			bool is_char = key < last_key;
			if (is_char)
			{
				// why +65?
				/*
				  1) A symbol is element of enum Keyboard::Key
					 and A is 0.
				  2) if we convert char variable with A value into int
					 we get variable with value 65, if B, than 66 e.t.c
				*/
				int _char = key + 65;

				char entered_symbol = static_cast<char>(_char);
				entered_text += entered_symbol;
			}
			key_pressed = true;
		}
		if (no_pressing())
		{
			key_pressed = false;
		}
			

	}
	entered_command->setString(entered_text);
}
void CommandLine::draw(RenderWindow* window)
{
	window->draw(*entered_command);
}
bool CommandLine::no_pressing()
{
	bool pressed_keys_states[35];

	int first_key = Keyboard::A;
	int last_key = Keyboard::Num9;

	for (int key = first_key; key < last_key; ++key)
	{
		Keyboard::Key pressed_key = static_cast<Keyboard::Key>(key);
		bool is_pressing = Keyboard::isKeyPressed(pressed_key);
		pressed_keys_states[key] = is_pressing;
	}

	for (int i = 0; i < 35; ++i)
	{
		if (pressed_keys_states[i])
		{
			return false;
		}
	}
	return true;
}