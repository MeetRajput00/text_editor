#include "../include/Text.h"

void Text::initialize(){
	if (!this->font.loadFromFile("../../fonts/OpenSans-Regular.ttf"))
    {
        std::cout<<"Error loading font."<<std::endl;
    }
    this->text.setFont(this->font);

    this->text.setCharacterSize(24);

    this->text.setFillColor(sf::Color::Black);
}