#pragma once
#include"SFML\Graphics.hpp"
using namespace sf;

#include<iostream>
using namespace std;

class CommandLine
{
private:
	Font font;
	Text* entered_command;

	string entered_text;

	bool key_pressed;
public:
	CommandLine();
	virtual ~CommandLine();

	void get_input();
	void draw(RenderWindow* window);
private:
	bool no_pressing();
};

