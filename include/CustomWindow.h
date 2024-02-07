#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string.h>
#include <SFML/Graphics/RectangleShape.hpp>

class CustomWindow{
public:	
	struct{
		int x;
		int y;
		int currLine;
	}pos;
	sf::RenderWindow window;
	sf::Text text;
	sf::Font font;
	sf::RectangleShape cursor;
	sf::Clock clock; // create a clock for the blinking effect
	int CharacterSize;
	CustomWindow(){
    	window.create(sf::VideoMode(800, 600), "Text editor");
    	window.setFramerateLimit(60);
    	window.setKeyRepeatEnabled(true); 
	}
	void initialize_text();
	void start_window();
	void handle_events(sf::Event *event, sf::RenderWindow *window);
	void initialize_cursor();
};