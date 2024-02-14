#include "../include/Cursor.h"

void Cursor::initialize(sf::Text *text){
	this->cursor.setSize(sf::Vector2f(2, text->getCharacterSize()));
    this->cursor.setFillColor(text->getFillColor());
}