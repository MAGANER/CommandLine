#pragma once
#include"SFML\Graphics.hpp"
#include<string>
using namespace std;
using namespace sf;

/*
 the base class for CommandLine that can be used
 as integrated Console in SFML applications.
 This class provides ability to get input only.
 So it means you have to write function to check input
 and apply action
    - MAGANER
*/
class CommandLine
{
private:
	Font font;             //can be changed
	Text* entered_command; //rendered command text

	string entered_text;   //input string

	bool key_pressed;      //is used to prevent key repeating
	bool working;          // working = true, not working = false
public:
	CommandLine();
	virtual ~CommandLine();

	void get_input();
	void draw(RenderWindow* window);

	void set_working_state(bool flag);
	bool is_working();
private:
	bool no_pressing();
};

