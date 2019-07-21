#include "CommandLine.h"
CommandLine::CommandLine()
{
	//default parameters
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
	if (working)
	{
	    int first_key = Keyboard::A;
	    int last_key  = Keyboard::Num9;
	    int first_number = Keyboard::Num0;

	    for (int key = first_key; key < last_key; ++key)
	    {
		    Keyboard::Key pressed_key = static_cast<Keyboard::Key>(key);
		    if (Keyboard::isKeyPressed(pressed_key) && !key_pressed)
		    {
			    //check is it char, if it's not, than it's number
			    bool is_char  = key < first_number;
			    if (is_char)
			    {
				   // why +65?
				/*
				  1) A symbol is element of enum Keyboard::Key
					 and A is 0.
				  2) if we convert char variable with A value into int
					 we get variable with value 65, if B, than 66 e.t.c
				  3) so 65 is "distance" between Key code from enumaration 
				     of Keyboard::Key and ASCII symbols
				*/
				int _char = key + 65;

				char entered_symbol = static_cast<char>(_char);
				entered_text += entered_symbol;
			}
			else
			{		
				//why +22
			   /*
				 the same reason as for characters.
				 1) 0 is 26 in Keyboard::Key
				 2) 0 is 48 in ASCII
				 3) so 48-26 = 22  the distance between them 
			   */

				int _char = key + 22;
				char entered_symbol = static_cast<char>(_char);
				entered_text += entered_symbol;
			}

			key_pressed = true;
		}
		    if (no_pressing())
		    {
			    //can press, if key isn't pressede already
			    key_pressed = false;
		    }
	    }

	    entered_command->setString(">"+entered_text);
	}

}
void CommandLine::draw(RenderWindow* window)
{
  if(working) window->draw(*entered_command);
}
bool CommandLine::no_pressing()
{
	//array,containing states of all keys
	bool pressed_keys_states[35];

	int first_key = Keyboard::A;
	int last_key = Keyboard::Num9;

	// check every key, is it pressed
	for (int key = first_key; key < last_key; ++key)
	{
		Keyboard::Key pressed_key = static_cast<Keyboard::Key>(key);
		bool is_pressing = Keyboard::isKeyPressed(pressed_key);
		pressed_keys_states[key] = is_pressing;
	}

	// if there is no pressed keys, than key isn't pressed, obviosly
	for (int i = 0; i < 35; ++i)
	{
		if (pressed_keys_states[i])
		{
			return false;
		}
	}
	return true;
}
void CommandLine::set_working_state(bool flag)
{
	working = flag;
}
bool CommandLine::is_working()
{
	return working;
}
void CommandLine::clear()
{
	entered_command->setString("");
	entered_text.clear();
}