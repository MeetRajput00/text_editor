#include "../common/common_includes.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../include/Text.h"
#include "../include/Cursor.h"

class CustomWindow{
public:	
	sf::RenderWindow window;
	sf::Clock clock; // create a clock for the blinking effect    
	Text text;
    Cursor cursor;
	int CharacterSize;
	CustomWindow(){
    	window.create(sf::VideoMode(800, 600), "Text editor");
    	window.setFramerateLimit(60);
    	window.setKeyRepeatEnabled(true); 
	}
	void start_window();
private:
	void handle_events(sf::Event *event);
	void handle_keyboard_input(sf::Event *event);
	void draw_text();
	void handle_cursor_visibility();
};